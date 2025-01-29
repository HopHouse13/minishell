/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:00:38 by swendum           #+#    #+#             */
/*   Updated: 2025/01/27 16:21:18 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_the_builtin(t_data *data, char **cmd)
{
	int	r;

	r = 0;
	if (!ft_strncmp(cmd[0], "cd", 3))
		r = do_the_cd(cmd, data, NULL, getcwd(NULL, 0));
	else if (!ft_strncmp(cmd[0], "exit", 5))
		r = do_the_exit(cmd, data);
	else if (!ft_strncmp(cmd[0], "echo", 5))
		r = do_the_echo(cmd);
	else if (!ft_strncmp(cmd[0], "unset", 6))
		r = do_the_unset(cmd, data, 0);
	else if (!ft_strncmp(cmd[0], "export", 7))
		r = do_the_export(cmd, data, 1);
	else if (!ft_strncmp(cmd[0], "pwd", 4))
		r = do_the_pwd();
	else if (!ft_strncmp(cmd[0], "env", 4))
		r = do_the_env(data);
	free_tab(cmd);
	clean_data(data, -1, NULL, NULL);
	exit(r);
}

void	do_the_execve(t_data *data, char **cmd)
{
	char	*exe;

	if (!cmd || !cmd[0] || !cmd[0][0])
	{
		free_tab(cmd);
		clean_data(data, -1, NULL, NULL);
		exit(0);
	}
	exe = get_real_path(cmd, get_env(data->env, "PATH"));
	if (!exe)
	{
		ft_printfd(2, "Command not found: %s\n", cmd[0]);
		free_tab(cmd);
		clean_data(data, -1, NULL, NULL);
		exit(127);
	}
	execve(exe, cmd, data->env);
	perror("Execve");
	free(exe);
	free_tab(cmd);
	clean_data(data, -1, NULL, NULL);
	exit(10);
}

void	do_direct_part2(t_data *data, int i, int b, int id)
{
	if (id == 0)
	{
		while (data->token[++i])
		{
			if (data->token[i] == 'I' || data->token[i] == 'O'
				|| data->token[i] == 'C')
				do_redirection(data, i, -1, -1);
			else if (data->token[i] == 'H')
				link_heredoc_file(data, i);
			else if ((data->token[i] != 'R' && b == -1))
				b = i;
		}
		launch(data, b);
	}
	waitpid(id, &data->status, 0);
	if (WIFEXITED(data->status))
		data->status = WEXITSTATUS(data->status);
	else if (WIFSIGNALED(data->status))
		data->status = g_sig;
	reboot_data(data, -1, NULL, NULL);
}

int	do_direct(t_data *data, int i, int b, int id)
{
	while (data->token[++i])
	{
		if ((data->token[i] == 'U' || data->token[i] == 'W'
				|| data->token[i] == 'B' || data->token[i] == 'X'
				|| data->token[i] == 'V' || data->token[i] == 'D') && b == -1)
			b = i;
	}
	if (b != -1 && (!ft_strncmp(data->cmd[b], "cd", 3)
			|| !ft_strncmp(data->cmd[b], "exit", 5)
			|| !ft_strncmp(data->cmd[b], "export", 7)
			|| !ft_strncmp(data->cmd[b], "unset", 6)) && data->token[b] == 'B' )
		return (do_shi_in(data, b, -1, NULL), 1);
	i = -1;
	id = fork();
	if (id == -1)
		return (perror("Fork"), reboot_data(data, -1, NULL, NULL), 0);
	return (do_direct_part2(data, i, b, id), 1);
}

int	launch(t_data *data, int i)
{
	char	**exe;

	exe = extract_exe_only(data, i, 1, 0);
	if (!exe)
		return (clean_data(data, -1, NULL, NULL), exit(0), 1);
	if (data->token[i] == 'B')
		do_the_builtin(data, exe);
	else if (data->token[i] == 'X')
		do_the_execve(data, exe);
	free_tab(exe);
	if (data->token[i] == 'D')
	{
		ft_printfd(2, "%s: Is a directory\n", data->cmd[i]);
		clean_data(data, -1, NULL, NULL);
		exit(126);
	}
	else
		ft_printfd(2, "Command not found: %s\n", data->cmd[i]);
	clean_data(data, -1, NULL, NULL);
	exit(127);
}
