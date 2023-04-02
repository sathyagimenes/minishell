/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:20:05 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/02 18:23:14 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_env(char *envp)
{
	int		index;
	char	**split_env;

	index = ft_strchr_pos(envp, EQUAL_CHAR);
	if (index == -1)
		return (NULL);
	split_env = (char **)malloc(sizeof(char *) * 2);
	split_env[0] = ft_substr(envp, 0, index);
	split_env[1] = ft_substr(envp, index + 1, ft_strlen(envp) - index);
	return (split_env);
}

void	ft_free_split_env(char ***split_envp)
{
	size_t	index;

	index = 0;
	while (index < 2)
	{
		ft_free_ptr((void **)&((*split_envp)[index++]));
	}
	ft_free_ptr((void **)(*split_envp));
	ft_free_ptr((void **)&(*split_envp));
}

unsigned int	ft_hash(char *key, size_t size)
{
	size_t	key_len;
	size_t	index;
	size_t	hash;

	key_len = ft_strlen(key);
	index = 0;
	hash = 0;
	while (index < key_len)
	{
		hash += key[index];
		hash = (hash * key[index]) % size;
		index++;
	}
	return (hash);
}
