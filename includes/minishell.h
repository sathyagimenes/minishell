/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:54:20 by sde-cama          #+#    #+#             */
/*   Updated: 2023/03/19 17:31:30 by sde-cama         ###   ########.fr       */
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

// STRUCTS
/**
 * @brief Structure that holds environment data.
 * @param envp Holds environment variables.
 * @param path Path to executables.
**/
typedef struct s_env
{
	char	**envp;
	char	**path;
}	t_env;

/**
 * @brief Structure that holds the main data.
 * @param env Structure that holds environment data.
**/
typedef struct s_data
{
	t_env	env;
}	t_data;

// FUNCTIONS
/**
 * @brief Check quantity of arguments for main function.
 * @param argc Quantity of arguments received.
 * @param argv Arguments received.
 * @return If too many arguments returns 1.
**/
int		ft_check_main_args(int argc, char **argv);

/**
 * @brief Prints error message to stderror.
 * @param msg Message to be printed.
**/
void	ft_print_error_msg(char *msg);

/**
 * @brief Initializes the shell.
 * @param data Structure that holds the main data.
 * @return Returns 0 if success.
**/
int		ft_start_shell(t_data *data);


#endif
