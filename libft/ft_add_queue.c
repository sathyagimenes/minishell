/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:15:49 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/06 08:21:19 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_queue(t_list **list, void *content)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = ft_newnode(content);
	if (*list)
	{
		last_node = ft_lastnode(*list);
		last_node->next = new_node;
	}
	else
		*list = new_node;
}
