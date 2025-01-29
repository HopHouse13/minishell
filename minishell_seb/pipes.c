/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:10:06 by swendum           #+#    #+#             */
/*   Updated: 2025/01/11 19:50:57 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sub_dopart(t_data *data, int i)
{
	if (i)
	{
		close(data->pfd[(i - 1) * 2 + 1]);
		dup2(data->pfd[(i - 1) * 2], 0);
		close(data->pfd[(i - 1) * 2]);
	}
	if (i < count_pipes(data))
	{
		close(data->pfd[i * 2]);
		dup2(data->pfd[(i * 2) + 1], 1);
		close(data->pfd[(i * 2) + 1]);
	}
	i--;
	while (--i >= 0)
	{
		close(data->pfd[i * 2]);
		close(data->pfd[(i * 2) + 1]);
	}
}

void	do_part(t_data *data, int i, int u, int p)
{
	sub_dopart(data, i);
	while (p != i)
	{
		if (data->token[++u] == 'P')
			p++;
	}
	if (i != 0)
		p = 1;
	i = -1;
	while (data->token[u + p] && data->token[u + p] != 'P')
	{
		if (data->token[u + p] == 'I' || data->token[u + p] == 'O'
			|| data->token[u + p] == 'C')
			do_redirection(data, u + p, -1, -1);
		else if (data->token[u + p] == 'H')
			link_heredoc_file(data, u + p);
		else if ((data->token[u + p] != 'R' && i == -1))
			i = u + p;
		p++;
	}
	launch(data, i);
}

void	close_all(t_data *data, int i)
{
	while (--i >= 0)
	{
		close(data->pfd[i * 2]);
		close(data->pfd[(i * 2) + 1]);
	}
}

int	divise_the_thing(t_data *data, int pipes, int i)
{
	if (pipes)
	{
		data->pfd = malloc(sizeof(int) * 2 * pipes);
		if (!data->pfd)
			return (perror("Malloc"), 0);
		data->id = malloc(sizeof(int) * (pipes + 1));
		if (!data->id)
			return (perror("Malloc"), free(data->pfd), 0);
		while (++i <= pipes)
		{
			if (i < pipes && pipe(&data->pfd[i * 2]) == -1)
				return (perror("Pipe"), 0);
			data->id[i] = fork();
			if (data->id[i] == -1)
				return (perror("Fork"), close_pfd(i * 2, data), 0);
			if (data->id[i] == 0)
				do_part(data, i, 0, 0);
		}
		close_all(data, i - 1);
		wait_children(data);
		reboot_data(data, -1, NULL, NULL);
	}
	else
		do_direct(data, -1, -1, -1);
	return (1);
}
