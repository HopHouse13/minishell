/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:19:13 by swendum           #+#    #+#             */
/*   Updated: 2025/01/20 22:21:30 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sub_expension(t_data *data, char *line, char **bonusline, char **gogeta)
{
	*bonusline = "\n";
	while (!ft_strncmp(*bonusline, "\n", 1))
	{
		write(1, "pipe> ", 6);
		*bonusline = get_next_line(0);
		if (!(*bonusline))
		{
			clean_data(data, -1, NULL, NULL);
			free(line);
			rl_clear_history();
			exit(0);
		}
	}
	get_next_line(-1);
	*gogeta = ft_strtrim(*bonusline, "\n");
	free(*bonusline);
	*bonusline = ft_strjoin(" ", *gogeta);
	free(*gogeta);
	*gogeta = ft_strjoin(line, *bonusline);
	free_tab(data->cmd);
	data->cmd = NULL;
	free(data->token);
	data->token = NULL;
}

int	domain_expension(t_data *data, char *line)
{
	char	*bonusline;
	char	*gogeta;

	if (ft_strlen(data->token) == 1 && data->token[0] == 'P')
		return (ft_putstr_fd("syntax error near token \'|\'\n", 2), 0);
	while (data->expension <= count_pipes(data) && ft_strlen(data->token) >= 1)
	{
		if (!wait_the_doc(data, data->expension++, line, 0))
			return (0);
	}
	if (data->token[ft_strlen(data->token) - 1] != 'P')
		return (1);
	sub_expension(data, line, &bonusline, &gogeta);
	if (!parsing(gogeta, 0, data))
		return (free(bonusline), 0);
	return (free(bonusline), 1);
}

int	sub_quoteception(t_data *data, int *i, char *line)
{
	int	j;

	j = (*i)++;
	if (line[(*i)] && line[(*i)] == line[j])
	{
		line[(*i)] = 0;
		line[j] = 0;
		(*i) = j - 1;
		j++;
		while (line[++j])
		{
			line[j - 2] = line[j];
			line[j] = 0;
		}
	}
	else
	{
		while (line[(*i)] && line[(*i)] != line[j])
			(*i)++;
		if (!line[(*i)])
			return (ft_printfd(2, "quote error\n"), free(line),
				reboot_data(data, -1, NULL, NULL), 0);
	}
	return (1);
}

int	remove_quoteception(char *line, int i, t_data *data)
{
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			if (!sub_quoteception(data, &i, line))
				return (0);
		}
		i++;
	}
	return (1);
}

int	parsing(char *line, long unsigned int i, t_data *data)
{
	if (!remove_quoteception(line, i, data))
		return (data->status = 1, 0);
	while (line[i] && (line[i] == ' ' || line[i] == '	'))
		i++;
	if (!ft_neosplit(line + i, data))
		return (free(line), line = NULL, 0);
	tokenisation(data, -1, 1);
	if (!fix_parsing(data, -1) || !domain_expension(data, line))
		return (reboot_data(data, -1, NULL, NULL), free(line), line = NULL, 0);
	return (free(line), line = NULL, 1);
}
