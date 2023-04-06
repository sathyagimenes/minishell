/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:24:55 by sde-cama          #+#    #+#             */
/*   Updated: 2023/04/05 23:04:57 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_exec(t_data *data);
static void	ft_exec_child(t_exec *exec, t_env *env);
static char	*ft_build_cmds(t_data *data, char *cmd);

void	ft_handle_exec(t_data *data)
{
	//fazer redirecionamento... é pipe?...
	ft_exec(data);
}

static int	ft_exec(t_data *data)
{
	int		pid;
	int		exit_code;

	//verificar se tem pipe ou builtin e fazer exec diferente
	// build comd com path
	exit_code = SUCCESS_CODE;
	data->exec.cmd = ft_build_cmds(data, data->exec.argv[0]);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		ft_exec_child(&data->exec, &data->env);
	if (pid != 0)
	{
		//verificar se precisa fazer algo no pai
		waitpid(pid, &exit_code, 0);//mudar waitpid de lugar. tem que fazer ele fora e depois de rodas todos os processos filhos e pais. faz antes de voltar pra função principal e faz pra todos os pids... isso por conta do compoortamento assincrono do shell/pipes. Ele utiliza o kork pra rodar tudo de uma vez e depois faz a espera
		if (WIFEXITED(exit_code))
			exit_code = WEXITSTATUS(exit_code);
	}
	return (exit_code);
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
