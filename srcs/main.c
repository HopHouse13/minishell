/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:25:32 by pbret             #+#    #+#             */
/*   Updated: 2025/02/10 19:51:48 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_loop_mshell(t_mshell *mshell)
{
	while (1)
	{
		ft_signal(); // je sais pas encore comment gerer ca
		mshell->input = readline("minishell :");
		if (!mshell)
			break ;
		if (mshell->input != NULL)
			add_history(mshell->input);
		
	
	}
}

int	main(int ac, char **av, char **env)
{
	t_mshell	*mshell;

	(void)av; // utilisation de av pour pourvoir compiler sans erreurs.
	if (ac == 1)
	{
		mshell = malloc(sizeof(t_mshell));
		if (!mshell)
			
		ft_init_mshell(mshell); // initialisation de toutes les struct
		ft_loop_mshell(mshell);
	}
	else
	{
		errno = EINVAL; // code error du nombre d'arg inscrit dans la macro errno.
		perror("Error main ");
		exit(EXIT_FAILURE);
	}
	return (0);
}
