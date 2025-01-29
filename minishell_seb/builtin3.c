/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 22:32:18 by swendum           #+#    #+#             */
/*   Updated: 2025/01/18 00:46:41 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_the_pwd(void)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	if (!temp)
		return (1);
	ft_printfd(1, "%s\n", temp);
	free(temp);
	return (0);
}

void	dump_env(char **env, int i)
{
	int	u;

	while (env && env[i])
	{
		u = 0;
		ft_putstr_fd("declare -x ", 1);
		while (env[i][u] && env[i][u] != '=')
			ft_putchar_fd(env[i][u++], 1);
		if (env[i][u])
		{
			ft_putstr_fd("=\"", 1);
			while (env[i][++u])
				ft_putchar_fd(env[i][u], 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}

int	check_name(char *var)
{
	int	i;

	i = 1;
	if (!var || (!ft_isalpha(var[0]) && var[0] != '_'))
		return (ft_printfd(2,
				"export: `%s': not a valid identifier\n", var), 0);
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (ft_printfd(2,
					"export: `%s': not a valid identifier\n", var), 0);
		i++;
	}
	return (1);
}

void	sub_export(t_data *data, char *cmd)
{
	int		in;
	char	**split_var;

	split_var = mini_split(cmd, 0, 0);
	if (split_var[1])
	{
		in = get_env_index(data->env, split_var[0]);
		if (in != -1)
		{
			free(data->env[in]);
			data->env[in] = ft_strdup(cmd);
		}
		else
			add_env(data, ft_strdup(cmd));
	}
	else
	{
		in = get_env_index(data->env, split_var[0]);
		if (in == -1)
			add_env(data, ft_strdup(cmd));
	}
	if (split_var)
		free_tab(split_var);
	split_var = 0;
}

int	do_the_export(char **cmd, t_data *data, int i)
{
	if (!cmd[1])
		return (dump_env(data->env, i), 0);
	while (cmd[i])
	{
		if (check_name(cmd[i]))
			sub_export(data, cmd[i]);
		else if (!cmd[i + 1])
			return (1);
		if (!cmd[++i])
			return (0);
	}
	return (1);
}
