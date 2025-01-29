/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shi_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:30:56 by swendum           #+#    #+#             */
/*   Updated: 2025/01/18 00:56:16 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_shitdoc(t_data *data, int i)
{
	char	*line;

	line = "Buff Zangief";
	while (read(0, 0, 0) >= 0 || line)
	{
		write(1, ">", 1);
		line = get_next_line(0);
		if (ft_strncmp(line, data->cmd[i], ft_strlen(data->cmd[i])) == 0)
		{
			get_next_line(-1);
			free(line);
			return ;
		}
		write(1, line, ft_strlen(line));
		free(line);
	}
}

int	do_shitrection(t_data *data, int i)
{
	int	fd;

	fd = -1;
	if (data->token[i] == 'I')
		fd = open(data->cmd[i], O_RDONLY);
	else if (data->token[i] == 'O')
		fd = open(data->cmd[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (data->token[i] == 'C')
		fd = open(data->cmd[i], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		ft_printfd(2, "%s: %s\n", strerror(errno), data->cmd[i]);
		return (0);
	}
	return (1);
}

int	do_shi_in(t_data *data, int b, int i, char **exe)
{
	while (data->token[++i])
	{
		if (data->token[i] == 'I' || data->token[i] == 'O'
			|| data->token[i] == 'C')
		{
			if (!do_shitrection(data, i))
				return (reboot_data(data, -1, NULL, NULL), data->status = 1, 1);
		}
		else if ((data->token[i] != 'R' && b == -1))
			b = i;
	}
	exe = extract_exe_only(data, b, 1, 0);
	if (!exe)
		return (reboot_data(data, -1, NULL, NULL), 0);
	if (!ft_strncmp(data->cmd[b], "cd", 3))
		data->status = (do_the_cd(exe, data, NULL, getcwd(NULL, 0)));
	else if (!ft_strncmp(data->cmd[b], "exit", 5))
		data->status = (do_the_exit(exe, data));
	else if (!ft_strncmp(data->cmd[b], "unset", 6))
		data->status = (do_the_unset(exe, data, 0));
	else if (!ft_strncmp(exe[0], "export", 7))
		data->status = do_the_export(exe, data, 1);
	return (reboot_data(data, -1, NULL, NULL), free_tab(exe), exe = 0, 1);
}
