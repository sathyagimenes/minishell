/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:25:07 by sde-cama          #+#    #+#             */
/*   Updated: 2023/02/11 21:21:49 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dellist(t_list **list)
{
	t_list	*node;

	while (*list)
	{
		node = *list;
		*list = (*list)->next;
		ft_delnode(node);
	}
}
