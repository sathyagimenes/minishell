/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:15:40 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/02 18:54:39 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_hash_item	*ft_new_item(char *key, char *value);
static void			ft_add_item(t_hash_item **hash_item, t_hash_item *new_hash_item);
static t_hash_item	*ft_find_last_item(t_hash_item *hash_head);

void	ft_insert_hash_item(t_hash_table *hash_table, char *key, char *value)
{
	unsigned int	hash;
	t_hash_item		*hash_item;

	hash = ft_hash(key, hash_table->size);
	hash_item = ft_new_item(key, value);
	ft_add_item(&hash_table->hash_items[hash], hash_item);
	hash_table->quantity++;
}

static t_hash_item	*ft_new_item(char *key, char *value)
{
	t_hash_item	*item;

	item = (t_hash_item *)malloc(sizeof(t_hash_item));
	if (!item)
		return (NULL);
	item->key = ft_strdup(key);
	item->value = ft_strdup(value);
	item->prev = NULL;
	item->next = NULL;
	return (item);
}

static void	ft_add_item(t_hash_item **hash_item, t_hash_item *new_hash_item)
{
	t_hash_item	*last_item;

	if (!(*hash_item))
	{
		*hash_item = new_hash_item;
		return ;
	}
	last_item = ft_find_last_item(*hash_item);
	last_item->next = new_hash_item;
	new_hash_item->prev = last_item;
}

static t_hash_item	*ft_find_last_item(t_hash_item *hash_head)
{
	t_hash_item	*head_item;

	if (!hash_head)
		return (NULL);
	head_item = hash_head;
	while (head_item->next)
		head_item = head_item->next;
	return (head_item);
}
