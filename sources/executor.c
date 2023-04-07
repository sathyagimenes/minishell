/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:24:55 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/07 11:20:10 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_exec(t_data *data);
static void	ft_exec_child(t_exec *exec, t_env *env);
static char	*ft_build_cmds(t_data *data, char *cmd);
static int	ft_wait_execs(t_data *data);

void	ft_handle_exec(t_data *data)
{
	//fazer redirecionamento... é pipe?...
	ft_exec(data);
	data->exit_code = ft_wait_execs(data);
}

static void	ft_exec(t_data *data)
{
	pid_t	*pid;

	//verificar se tem pipe ou builtin e fazer exec diferente
	// build comd com path
	data->exec.cmd = ft_build_cmds(data, data->exec.argv[0]);
	pid = (pid_t *)malloc(sizeof(pid_t));
	*pid = fork();
	if (*pid == -1)
		exit(1);
	if (*pid == 0)
	{
		ft_free_ptr((void **)&pid);
		ft_exec_child(&data->exec, &data->env);
	}
	if (*pid != 0)
	{
		ft_add_queue(&data->pid_list, pid);
		//verificar se precisa fazer mais alguma coisa no pai
	}
}

static void	ft_exec_child(t_exec *exec, t_env *env)
{
	//refazer a envp usando a hash table, pq pode ser que user tenha alterado alguma variavel anteriormente
	//set redirection do input/output
	if (execve(exec->cmd, exec->argv, env->envp) == -1)
	{
		// mensagem de erro
		ft_printf("%s \n", "tentou executar, mas falhou");
		//dar free?
		//setar o exit code?
		exit(1);
	}
}

static char	*ft_build_cmds(t_data *data, char *cmd)
{
	char	*full_path;
	char	*cmd_line;
	int		i;

	if (!(ft_strchr(cmd, '.')) || !(ft_strchr(cmd, '/')))
	{
		i = 0;
		while (data->env.path[i])
		{
			full_path = ft_strjoin(data->env.path[i], "/");
			cmd_line = ft_strjoin(full_path, cmd);
			ft_free_ptr((void **)&(full_path));
			if (access(cmd_line, F_OK) == 0)
				return (cmd_line);
			free(cmd_line);
			i++;
		}
	}
	return (ft_strdup(cmd));
}

static int	ft_wait_execs(t_data *data)
{
	int	new_exit_code;

	while (data->pid_list)
	{
		waitpid((*(pid_t *)data->pid_list->content), &new_exit_code, 0);
		if (WIFEXITED(new_exit_code))
			new_exit_code = WEXITSTATUS(new_exit_code);
		data->pid_list = data->pid_list->next;
	}
	return (new_exit_code);
}
