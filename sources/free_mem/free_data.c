/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:55:47 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/07 18:36:11 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_executor(t_data *data);

void	ft_free_data(t_data *data, t_bool free_all)
{
	if (free_all)
	{
		ft_free_env(&data->env);
		rl_clear_history();
	}
	ft_free_executor(data);
	ft_free_ptr((void **)&data->prompt);
	data->buffer = NULL;
}

void	ft_free_executor(t_data *data)
{
	int	i;

	i = 0;
	while (data->exec.argv[i])
		ft_free_ptr((void **)&data->exec.argv[i++]);
	ft_free_ptr((void **)&data->exec.argv);
	ft_free_ptr((void **)&data->exec.cmd);
	ft_dellist(&data->pid_list);
	data->pid_list = NULL;
}
