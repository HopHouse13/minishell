/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swendum <swendum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:51:45 by swendum           #+#    #+#             */
/*   Updated: 2025/01/21 23:32:07 by swendum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigint(void)
{
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("^C\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	sigquit(void)
{
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \b\b", 1);
}

static void	handle_signal(int signo)
{
	int	pid;
	int	status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT)
	{
		g_sig = 130;
		if (pid != 0)
			sigint();
		else
			ft_putstr_fd("\n", 1);
	}
	else if (signo == SIGQUIT)
	{
		g_sig = 131;
		if (pid != 0)
			sigquit();
		else
			ft_putstr_fd("Quit (Core dumped)\n", 1);
	}
}

void	do_nothing(int signo)
{
	(void) signo;
}

void	setup_signal_handlers(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}
