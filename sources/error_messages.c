/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:01:04 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/19 15:34:56 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_error_msg(char *msg)
{
	char *formated_msg;

	if (msg != NULL)
		formated_msg = ft_strjoin("minishell: ", msg);
	ft_putendl_fd(formated_msg, STDERROR);
	free(formated_msg);
}
