/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:06:22 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/02 18:23:03 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_hash_item	*ft_get_value(t_hash_table *hash_table, char *key)
{
	unsigned int	hash;
	t_hash_item		*head;

	hash = ft_hash(key, hash_table->size);
	head = hash_table->hash_items[hash];
	while (head)
	{
		if (head && ft_strncmp(head->key, key, ft_strlen(key)) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}
