/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:37:37 by swendum           #+#    #+#             */
/*   Updated: 2025/01/23 21:22:40 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	link_heredoc_file(t_data *data, int i)
{
	int		fd;
	char	*temp;
	char	*name;

	temp = ft_itoa(i);
	name = ft_strjoin("temp", temp);
	fd = open(name, O_RDONLY);
	free(name);
	free(temp);
	if (fd == -1)
	{
		clean_data(data, -1, NULL, NULL);
		exit(errno);
	}
	if (dup2(fd, 0) == -1)
	{
		perror("Dup2");
		clean_data(data, -1, NULL, NULL);
		close(fd);
		exit(errno);
	}
	close(fd);
}

void	sub_heredoc_file(t_data *data, int i, int fd)
{
	char	*line;

	line = "Buff Zangief";
	signal(SIGINT, SIG_DFL);
	while (read(0, 0, 0) >= 0 && line)
	{
		line = readline("heredoc> ");
		if (g_sig == 130 || !line
			|| ft_strncmp(line, data->cmd[i], ft_strlen(data->cmd[i])) == 0)
		{
			if (line)
				free(line);
			else
				ft_printfd(2,
					"\nwarning: heredoc delimited by eof wanted ('%s')",
					data->cmd[i]);
			line = NULL;
			close(fd);
			write(1, "\n", 1);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
}

int	do_heredoc_file(t_data *data, int i, char *line)
{
	int		fd;
	char	*temp;
	char	*name;

	free(line);
	temp = ft_itoa(i);
	name = ft_strjoin("temp", temp);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	free(name);
	free(temp);
	if (fd == -1)
	{
		ft_printfd(2, "%s: %s\n", strerror(errno), data->cmd[i]);
		clean_data(data, -1, NULL, NULL);
		exit(errno);
	}
	sub_heredoc_file(data, i, fd);
	close(fd);
	clean_data(data, -1, NULL, NULL);
	exit(1);
}

void	sub_wait_doc(t_data *data, int *u, int *i, int *p)
{
	while (*p != *i)
	{
		if (data->token[*u + 1] && data->token[++(*u)] == 'P')
			(*p)++;
	}
	if (*i > 0)
		*p = 1;
	*i = 0;
	while (data->token[*u + *p] && data->token[*u + *p] != 'P')
	{
		if (data->token[*u + *p] == 'I')
			*i = -(*u + *p);
		else if (data->token[*u + *p] == 'H')
			*i = *u + *p + 1;
		(*p)++;
	}
}

int	wait_the_doc(t_data *data, int i, char *line, int p)
{
	int	id;
	int	u;

	u = 0;
	sub_wait_doc(data, &u, &i, &p);
	if (i-- > 0)
	{
		id = fork();
		if (id == -1)
			return (perror("Fork"), 0);
		if (id == 0)
			do_heredoc_file(data, i, line);
		else
		{
			signal(SIGQUIT, do_nothing);
			waitpid(id, &data->status, 0);
			if (WIFEXITED(data->status))
				data->status = WEXITSTATUS(data->status);
			if (WIFSIGNALED(data->status))
				data->status = g_sig;
			if (g_sig == 130)
				return (0);
		}
	}
	return (1);
}
