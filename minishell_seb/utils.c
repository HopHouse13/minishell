/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:54:56 by swendum           #+#    #+#             */
/*   Updated: 2025/01/27 15:15:31 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		tab[i] = 0;
		i++;
	}
	free(tab);
	tab = 0;
}

void	close_pfd(int i, t_data *data)
{
	if (!data->pfd)
		return ;
	while (i >= 0)
		close(data->pfd[i--]);
}

int	count_pipes(t_data *data)
{
	int	i;
	int	pipes;

	pipes = 0;
	i = -1;
	while (data->token[++i])
	{
		if (data->token[i] == 'P')
			pipes++;
	}
	return (pipes);
}
