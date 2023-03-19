/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:54:20 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/19 16:07:09 by sde-cama         ###   ########.fr       */
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
/**
 * @brief Check quantity of arguments for main function.
 * @param argc quantity of arguments received.
 * @param argv arguments received.
 * @return If too many arguments returns 1.
**/
int		ft_check_main_args(int argc, char **argv);

/**
 * @brief Prints error message to stderror.
 * @param msg message to be printed.
**/
void	ft_print_error_msg(char *msg);

#endif
