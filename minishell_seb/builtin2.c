/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:36:29 by swendum           #+#    #+#             */
/*   Updated: 2025/01/18 18:53:19 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoexit(char *str, long long r, int i)
{
	int		c;
	long	s;

	s = 1;
	c = -1;
	if (!ft_isnum(str))
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9' && c++ > -2)
		r = r * 10 + (str[i++] - 48);
	if (r > 9223372036854775807 || c > 19)
		return (-1);
	if (r > 255)
		r = r % 256;
	if (s == -1)
		r = 255 - (r - 1);
	return (r);
}

int	do_the_exit(char **cmd, t_data *data)
{
	int	e;

	e = 0;
	if (!cmd[1])
		e = data->status;
	else if (ft_atoexit(cmd[1], 0, 0) == -1)
	{
		ft_printfd(2, "exit\nexit: %s: numeric arg required\n", cmd[1]);
		e = 2;
	}
	else if (cmd[1] && cmd[2])
	{
		e = 1;
		ft_printfd(2, "exit\nexit: too many arguments\n");
	}
	else if (cmd[1] && ft_atoexit(cmd[1], 0, 0) > -1)
	{
		ft_printfd(1, "exit\n");
		e = ft_atoexit(cmd[1], 0, 0);
	}
	clean_data(data, -1, NULL, NULL);
	free_tab(cmd);
	rl_clear_history();
	exit(e);
}

int	do_the_unset(char **cmd, t_data *data, int i)
{
	int	j;

	if (!cmd[1])
		return (0);
	while (cmd[++i])
	{
		j = -1;
		while (data->env[++j])
		{
			if (!ft_strncmp(data->env[j], cmd[i], ft_strlen(cmd[i]))
				&& data->env[j][ft_strlen(cmd[i])] == '=')
			{
				free(data->env[j]);
				while (data->env[j + 1])
				{
					data->env[j] = data->env[j + 1];
					j++;
				}
				data->env[j] = NULL;
				break ;
			}
		}
	}
	return (0);
}

int	do_the_env(t_data *data)
{
	int	i;
	int	ok;
	int	u;

	i = -1;
	if (!data->env)
		return (1);
	while (data->env[++i])
	{
		ok = 0;
		u = -1;
		while (data->env[i][++u])
		{
			if (data->env[i][u] == '=' && data->env[i][u + 1])
				ok = 1;
		}
		if (ok)
			ft_printfd(1, "%s\n", data->env[i]);
	}
	return (0);
}
