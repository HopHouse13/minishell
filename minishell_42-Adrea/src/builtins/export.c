/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:25:23 by witong            #+#    #+#             */
/*   Updated: 2025/02/05 17:05:25 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_var_name(t_shell *shell, char *str)
{
	int	i;
	char *name;

	i = 0;
	while(str[i] && str[i] != '=')
		i++;
	name = ft_substr_track(shell, str, 0, i);
	return (name);
}

static int	find_env_var(char **envp, char *var_name)
{
	int	i;
	int var_len;

	if (!envp || !var_name)
		return (-1);
	var_len = ft_strlen(var_name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var_name, var_len) == 0
				&& (envp[i][var_len] == '=' || envp[i][var_len] == '\0'))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static void	add_to_env(t_shell *shell, char *arg)
{
	int env_size;
	char	**new_env;

	env_size = 0;
	while (shell->envp && shell->envp[env_size])
		env_size++;
	new_env = ft_realloc_array(shell->envp, env_size + 1);
	if (!new_env)
		return ;
	new_env[env_size] = ft_strdup(arg);
	shell->envp = new_env;
}

static void	update_env_var(t_shell *shell, int i, char *arg)
{
	free(shell->envp[i]);
	shell->envp[i] = ft_strdup(arg);
}

static void	handle_env_var(t_shell *shell, char *arg)
{
	char	*var_name;
	int		var_index;

	if (!is_valid_var(arg))
	{
		ft_putstr_fd("minishell: export: '", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return ;
	}
	var_name = get_var_name(shell, arg);
	var_index = find_env_var(shell->envp, var_name);
	if (ft_strchr(arg, '='))
	{
		if (var_index >= 0)
			update_env_var(shell, var_index, arg);
		else
			add_to_env(shell, arg);
	}
}

int	ft_export(t_shell *shell)
{
	int	i;

	i = 1;
	if (!shell->cmd->full_cmd[1])
		ft_env_export(shell->envp);
	else
	{
		while (shell->cmd->full_cmd[i])
		{
			handle_env_var(shell, shell->cmd->full_cmd[i]);
			i++;
		}
	}
	return (0);
}
