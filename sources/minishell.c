/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:34:43 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/19 15:41:25 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	if (ft_check_main_args(argc, argv))
		return (ERROR_CODE);
	// depois excluir if da envp
	if (!envp)
		return (ERROR_CODE);
	// salvar envp em uma hash table
	return (SUCCESS_CODE);
}
