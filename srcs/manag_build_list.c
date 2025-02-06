/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_build_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:26:19 by pbret             #+#    #+#             */
/*   Updated: 2025/02/06 16:25:06 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// 1) take retour de readline
// 2) split avec les " " "\t" (a voir "\n")
// 3) 

void	ft_manag_parser(t_list list)
{
	ft_build_list_cmds(list); // a faire
	
}

void	ft_build_list_cmds(t_list list)
{
char	*cmds_brut;

	cmds_brut = readline("minishell :");
	if (!cmds_brut)
	{
		if (errno)
			perror("error prompt ");
		else
			ft_printf("Exit minishell\n");	// en cas de ctrl+D quand on est entrain de remplir le heredoc. je pense devoir gerer le crtl ailleurs.
	}
	else
		ft_list_manag(list, cmds_brut);		// types -> operateurs de redirection ( |, <, <<, >, >>) ou cmds ou arguments de la cmds.
}
ft_list_manag(t_list list, char *cmds_brut)
{

	
}