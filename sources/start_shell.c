/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:58:22 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/25 16:38:24 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_data(t_data *data);
void	ft_create_prompt(t_data *data);
void	ft_free_data(t_data *data);

int ft_start_shell(t_data *data)
{
	while (1)
	{
		ft_init_data(data);
		ft_create_prompt(data);
		data->buffer = readline(data->prompt);
		if (data->buffer == NULL)
		{
			ft_free_data(data);
			exit(0);
		}
		/*
		- Criar struct para estruturar dados
		- setar sinais/eventos
		- cria o prompt (o que vai aparecer como prompt do minishel)
			-pegar variaveis de ambiente user, hostname e cwd
			- cria uma struct com os dados do prompt
		- executa readline
		- faz tokenização
		- salva no historico o que foi escrito
		- Faz o parse do token
		- Tenta executar
		- da free na estrutura de dados
		*/
	}
	ft_putendl_fd(data->env.envp[0], 1); //apagar
	return (SUCCESS_CODE);
}

void	ft_init_data(t_data *data)
{
	data->buffer = NULL;
	data->prompt = NULL;
}

void	ft_create_prompt(t_data *data)
{
	data->prompt = (char *)malloc(sizeof(char) * 12);
	ft_strlcpy(data->prompt, "minishell: ", 11);
}

void	ft_free_data(t_data *data)
{
	//melhorar esse free
	free(data->buffer);
	free(data->prompt);
}
