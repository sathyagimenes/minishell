/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:46:28 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/19 15:25:38 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_main_args(int argc, char **argv)
{
	if (argc > 1 && *argv)
	{
		ft_print_error_msg("you cannot run minishell with arguments");
		return (ERROR_CODE);
	}
	return (SUCCESS_CODE);
}
