/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:02:36 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/02 18:25:10 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_init_env(t_env *env, char **envp);
static t_hash_table	*ft_init_hash_table(size_t size);
static void			ft_populate_table(t_env *env);
static void			ft_save_path(t_data *data);

void	ft_create_env(t_data *data, char **envp)
{
	ft_init_env(&data->env, envp);
	data->env.table = ft_init_hash_table(TABLE_SIZE);
	ft_populate_table(&data->env);
	ft_save_path(data);
}

static void	ft_init_env(t_env *env, char **envp)
{
	env->envp = envp;
	env->table = NULL;
	env->path = NULL;
}

static t_hash_table	*ft_init_hash_table(size_t size)
{
	t_hash_table	*hash_table;
	size_t			index;

	index = 0;
	hash_table = (t_hash_table *)malloc(sizeof(t_hash_table));
	hash_table->hash_items = (t_hash_item **)malloc(sizeof(t_hash_item *) * size);
	hash_table->size = size;
	hash_table->quantity = 0;
	while (index < hash_table->size)
	{
		hash_table->hash_items[index] = NULL;
		index++;
	}
	return (hash_table);
}

static void	ft_populate_table(t_env *env)
{
	int		index;
	char	**split_envp;

	index = 0;
	while (env->envp[index])
	{
		split_envp = ft_split_env(env->envp[index]);
		ft_insert_hash_item(env->table, split_envp[0], split_envp[1]);
		ft_free_split_env(&split_envp);
		index++;
	}
}

static void	ft_save_path(t_data *data)
{
	t_hash_item	*path;

	path = ft_get_value(data->env.table, "PATH");
	data->env.path = ft_split(path->value, COLON_CHAR);
}
