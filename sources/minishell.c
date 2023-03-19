/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:34:43 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/19 17:32:21 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_data data;

	if (ft_check_main_args(argc, argv))
		return (ERROR_CODE);
	data.env.envp = envp; // salvar envp em uma hash table e salvar path
	return (ft_start_shell(&data));
}
