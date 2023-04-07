/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:54:20 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/07 16:49:39 by sde-cama         ###   ########.fr       */
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

# define AT "@"
# define PROMPT_SIGN "$ "
# define COLON ":"
# define EQUAL "="
# define COLON_CHAR ':'
# define EQUAL_CHAR '='

# define PURPLE "\001\033[0;34m\002"
# define RESET "\001\033[0m\002"
# define GREEN "\001\033[0;32m\002"

# define TABLE_SIZE 503

// LOCAL LIBRARIES
#include <libft.h>

// EXTERNAL LIBRARIES
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>

// STRUCTS
/**
 * @brief Structure that will compose a list of key-values (Dictonary).
 * @param key Variable that will be the reference to a value.
 * @param value Variable that holds the value to be retrieved by key.
 * @param next Address to the next item in the linked list of key-values.
 * @param prev Address to the previous item in the linked list of key-values.
**/
typedef struct s_hash_item
{
	char				*key;
	char				*value;
	struct s_hash_item	*next;
	struct s_hash_item	*prev;
}	t_hash_item;

/**
 * @brief Structure that holds a list of key-values (Dictonary).
 * @param hash_items Struct that composes the table key-value.
 * @param size Max size of table.
 * @param quantity Quantity of key-values.
**/
typedef struct s_hash_table
{
	t_hash_item	**hash_items;
	size_t		size;
	size_t		quantity;
}	t_hash_table;

/**
 * @brief Structure that holds environment data.
 * @param envp Holds environment variables.
 * @param path Path to executables.
 * @param table Structure that holds a list of key-values (Dictonary).
**/
typedef struct s_env
{
	char			**envp;
	t_hash_table	*table;
	char			**path;
}	t_env;

typedef struct s_exec
{
	char	*cmd;
	char	**argv;
}	t_exec;

/**
 * @brief Structure that holds the main data.
 * @param env Structure that holds environment data.
 * @param buffer Holds the line read.
 * @param prompt Holds the prompt string.
**/
typedef struct s_data
{
	t_env	env;
	int		exit_code;
	char	*buffer;
	char	*prompt;
	t_exec	exec;
	t_list	*pid_list;
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

/**
 * @brief Reads a file until limitter is not found.
 * @param fd File to be read.
 * @param limitter determinates the end of file (EOF).
 * @return Returns the content read.
**/
char	*get_next_line(int fd, char *limitter);


//FUNCTIONS - Environment Hash Table

/**
 * @brief Create the environment hash table.
 * @param data Structure that will hold the environment table.
 * @param envp List of environment variables .
**/
void	ft_create_env(t_data *data, char **envp);

/**
 * @brief Inserts an item(key-value) into the hash table.
 * @param hash_table Hash table where to insert the item.
 * @param key Variable that holds the key of the item.
 * @param value Variable that holds the value of the item.
**/
void	ft_insert_hash_item(t_hash_table *hash_table, char *key, char *value);

/**
 * @brief Finds a hash item inside a hash table.
 * @param hash_table Hash table where to search the item.
 * @param key Key of the item to be searched.
 * @return Returns the hash item or null if not found.
**/
t_hash_item	*ft_get_value(t_hash_table *hash_table, char *key);

/**
 * @brief Frees memory of the given structure.
 * @param env Structure to be freed.
**/
void	ft_free_env(t_env *env);

/**
 * @brief Generates a hash(index code) according to the given key.
 * @param key Key of the item to extract the hash code.
 * @param size Size of the hash table where the item is.
 * @return Returns the hash code.
**/
unsigned int	ft_hash(char *key, size_t size);

/**
 * @brief Splits the given environment variable.
 * @param envp The environment variable to be splitted.
 * @return Returns the envp splitted in an array of two elements - index 0 is the key and index 1 is the value.
**/
char	**ft_split_env(char *envp);

/**
 * @brief Frees memory of the given array.
 * @param split_envp Array to be freed.
**/
void	ft_free_split_env(char ***split_envp);

int		ft_tokenizer(t_data *data);
void	ft_handle_exec(t_data *data);

void	ft_free_data(t_data *data, t_bool free_all);

t_bool	is_builtin(t_data *data, t_exec *exec);

#endif
