/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:39:17 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/07 17:18:28 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_exit(t_data *data);

t_bool	is_builtin(t_data *data, t_exec *exec)
{
	if (!(ft_strncmp(exec->argv[0], "exit", ft_strlen("exit"))))
	{
		ft_exec_exit(data);
		return (TRUE);
	}
	return (FALSE);
}

void	ft_exec_exit(t_data *data)
{
	//melhorar essa func
	ft_free_data(data, TRUE);
	ft_printf("exit\n");
	exit(0);
}
