/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:58:22 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/19 17:32:34 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_start_shell(t_data *data)
{
	int i = 0;
	while (data->env.envp[i])
	{
		ft_putendl_fd(data->env.envp[i++], 1);
	}
	return (SUCCESS_CODE);
}
