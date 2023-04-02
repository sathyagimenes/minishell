/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:42:18 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/26 17:42:01 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_pos(char *s, char c)
{
	int				position;
	unsigned char	character;
	unsigned char	*string;

	position = 0;
	character = c;
	string = (unsigned char *)s;
	while (string[position])
	{
		if (string[position] == character)
		{
			return (position);
		}
		position++;
	}
	if (character == '\0')
		return (ft_strlen((char *)string));
	return (-1);
}
