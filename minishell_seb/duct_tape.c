/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duct_tape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 23:34:04 by swendum           #+#    #+#             */
/*   Updated: 2025/01/28 14:22:40 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fix_parsing(t_data *data, int i)
{
	while (data->token[++i])
	{
		if (data->token[i] == 'P' && data->token[i + 1]
			&& data->token[i + 1] == 'P')
			return (ft_printfd(2,
					"syntax error near token \'%s\'\n", data->cmd[i]), 0);
		if (data->token[i] == 'R' && (!data->token[i + 1]
				|| data->token[i + 1] == 'P'))
			return (ft_printfd(2,
					"syntax error near token \'%s\'\n", data->cmd[i]), 0);
	}
	return (1);
}
/*
int	fix_redirection(t_data *data)
{
	int	i;

	while (data->token[i] &&)
}*/