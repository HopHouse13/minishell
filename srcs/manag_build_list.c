/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_build_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:26:19 by pbret             #+#    #+#             */
/*   Updated: 2025/02/03 19:09:01 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// 1) take retour de readline
// 2) split avec les " " "\t" (a voir "\n")
// 3) 




cmds_brut = readline("minishell :");
if (!cmds_brut)
{
	if (errno)
		perror("error main ");
	else
		ft_printf("Exit minishell\n");	// en cas de ctrl+D quand on est entrain de remplir le heredoc. je pense devoir gerer le crtl ailleurs.
}
else
	if (ft_checks_cmds(&cmds_brut))		// controle de la syntaxe (l'ordre des elements est il correction selon leurs types? 
		ft_list_manag(&cmds_brut);		// types -> operateurs de redirection ( |, <, <<, >, >>) ou cmds ou arguments de la cmds.