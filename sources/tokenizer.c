/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:45:53 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/08 13:11:40 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	*ft_init_exec(void);

int	ft_tokenizer(t_data *data)
{
	data->exec = ft_init_exec();
	data->exec->argv = ft_split(data->buffer, ' ');
	return(0);
}

t_exec	*ft_init_exec(void)
{
	t_exec	*executor;

	executor = (t_exec *)malloc(sizeof(t_exec));
	if (!executor)
		return (NULL);
	executor->argv = NULL;
	executor->cmd = NULL;
	return (executor);
}
