/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:34:43 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/19 13:18:19 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	// deletar - somente teste
	if (argc == 1 && *envp)
	{
		ft_printf("\n O arquivo criado: %s \n", *argv);
	}
	return (0);
}
