/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:14:42 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/02 18:52:38 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_path(char **path);
static void	ft_free_hash_table(t_hash_table *hash_table);
static void	ft_free_hash_items(t_hash_item **hash_head);
static void	ft_free_hash_item(t_hash_item *hash_item);

void	ft_free_env(t_env *env)
{
	ft_free_hash_table(env->table);
	ft_free_path(env->path);
}

static void	ft_free_hash_table(t_hash_table *hash_table)
{
	size_t	index;

	index = 0;
	while (index < hash_table->size)
	{
		ft_free_hash_items(&hash_table->hash_items[index]);
		index++;
	}
	ft_free_ptr((void **)&(hash_table->hash_items));
	ft_free_ptr((void **)&(hash_table));
}

static void	ft_free_hash_items(t_hash_item **hash_head)
{
	t_hash_item	*hash_tmp;

	while (*hash_head)
	{
		if (!(*hash_head)->next)
		{
			ft_free_hash_item(*hash_head);
			break ;
		}
		hash_tmp = (*hash_head)->next;
		hash_tmp->prev = NULL;
		ft_free_hash_item(*hash_head);
		(*hash_head) = hash_tmp;
	}
	hash_head = NULL;
}

static void	ft_free_hash_item(t_hash_item *hash_item)
{
	ft_free_ptr((void **)&(hash_item->key));
	ft_free_ptr((void **)&(hash_item->value));
	hash_item->next = NULL;
	ft_free_ptr((void **)&(hash_item));
	hash_item = NULL;
}

static void	ft_free_path(char **path)
{
	int	i;

	i = 0;
	if (!path)
		return ;
	while (path[i])
	{
		ft_free_ptr((void **)&path[i++]);
	}
	ft_free_ptr((void **)(path));
	ft_free_ptr((void **)&(path));
}
