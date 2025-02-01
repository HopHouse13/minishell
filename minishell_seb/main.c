/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:24:09 by swendum           #+#    #+#             */
/*   Updated: 2025/02/01 18:47:50 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig = 1;

char	*get_real_path(char **split_cmd, char *path)
{
	char	**split_path;
	int		i;
	char	*temp;
	char	*exe;

	if (access(split_cmd[0], F_OK | X_OK) == 0 && ft_strchr(split_cmd[0], '/'))
		return (ft_strdup(split_cmd[0]));
	split_path = ft_split((const char *)path, ':');
	if (!split_path)
		return (NULL);
	i = 0;
	while (split_path[i])
	{
		temp = ft_strjoin(split_path[i], "/");
		exe = ft_strjoin(temp, split_cmd[0]);
		free(temp);
		if (access(exe, F_OK | X_OK) == 0)
			return (free_tab(split_path), exe);
		free(exe);
		i++;
	}
	return (free_tab(split_path), NULL);
}
	
void	do_redirection(t_data *data, int i, int fd, int dup)
{
	if (data->token[i] == 'I')
		fd = open(data->cmd[i], O_RDONLY);
	else if (data->token[i] == 'O')
		fd = open(data->cmd[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (data->token[i] == 'C')
		fd = open(data->cmd[i], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		ft_printfd(2, "%s: %s\n", strerror(errno), data->cmd[i]);
		clean_data(data, -1, NULL, NULL);
		exit(1);
	}
	if (data->token[i] == 'I')
		dup = dup2(fd, 0);
	else if (data->token[i] == 'O' || data->token[i] == 'C')
		dup = dup2(fd, 1);
	close(fd);
	if (dup == -1)
	{
		perror("Dup2");
		clean_data(data, -1, NULL, NULL);
		exit(errno);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	char	*temp;
	t_data	*data;

	if (argc == 10)
		argv[0] = "prout";
	data = create_data(env, 0);
	if (!data)
		return (1);
	while (1)
	{
		setup_signal_handlers();
		temp = readline("Mini SHEESH> ");
		if (!temp)
			break ;
		line = ft_strtrim(temp, "\n");
		free(temp);	
		if (!is_empty(line))
			add_history(line);
		if (parsing(line, 0, data))
			divise_the_thing(data, count_pipes(data), -1);
	}
	clean_data(data, -1, NULL, NULL);
	return (0);
}
