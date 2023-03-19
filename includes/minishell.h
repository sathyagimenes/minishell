/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:54:20 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/19 15:37:41 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

// DEFINES
#define ERROR_CODE 1
#define SUCCESS_CODE 0

# define STDIN 0
# define STDOUT 1
# define STDERROR 2

// LOCAL LIBRARIES
#include <libft.h>

// EXTERNAL LIBRARIES

// FUNCTIONS
int		ft_check_main_args(int argc, char **argv);
void	ft_print_error_msg(char *msg);

#endif
