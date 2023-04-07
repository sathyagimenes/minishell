/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:58:22 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/07 13:56:54 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_data(t_data *data);
static void	ft_create_prompt(t_data *data);

int ft_start_shell(t_data *data)
{
	while (1)
	{
		ft_init_data(data);
		ft_create_prompt(data);
		//configura os sinais antes do readline
		data->buffer = readline(data->prompt);
		if (data->buffer == NULL)
		{
			ft_free_data(data, TRUE);
			exit(0);
		}
		ft_tokenizer(data); //tokeniza buffer e executa
		add_history(data->buffer);
		//fazer parser
		ft_handle_exec(data);
		// if (data->buffer != NULL)
		// {
		// 	ft_free_data(data);
		// 	exit(0);
		// }
		ft_free_data(data, FALSE);
	}
	return (SUCCESS_CODE);
}

static void	ft_init_data(t_data *data)
{
	data->buffer = NULL;
	data->prompt = NULL;
	data->pid_list = NULL;
}

static void	ft_create_prompt(t_data *data)
{
	t_hash_item	*user;
	t_hash_item	*hostname;
	t_hash_item	*cwd;
	size_t		len;

	user = ft_get_value(data->env.table, "USER");
	hostname = ft_get_value(data->env.table, "USERNAME");
	cwd = ft_get_value(data->env.table, "PWD");
	len = ft_strlen(user->value) + ft_strlen(AT) + ft_strlen(hostname->value) + ft_strlen(COLON) + ft_strlen(cwd->value) + ft_strlen(PROMPT_SIGN) + ft_strlen(GREEN) + ft_strlen(RESET) + ft_strlen(PURPLE) + ft_strlen(RESET);
	data->prompt = (char *)malloc(sizeof(char) * len);
	ft_strlcpy(data->prompt, GREEN, len);
	ft_strlcat(data->prompt, user->value, len);
	ft_strlcat(data->prompt, AT, len);
	ft_strlcat(data->prompt, hostname->value, len);
	ft_strlcat(data->prompt, RESET, len);
	ft_strlcat(data->prompt, COLON, len);
	ft_strlcat(data->prompt, PURPLE, len);
	ft_strlcat(data->prompt, cwd->value, len);
	ft_strlcat(data->prompt, RESET, len);
	ft_strlcat(data->prompt, PROMPT_SIGN, len);
}
