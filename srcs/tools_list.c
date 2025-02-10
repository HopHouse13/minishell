/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:12:08 by pbret             #+#    #+#             */
/*   Updated: 2025/02/10 20:00:40 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// ft pour gerer l'initialisation de  la liste
void	ft_list_manag(char *cmds_brut)
{
	
}

// ft pour creer le 1er noeud de la liste avec le pointeur head qui pointe dessus
void	ft_init_list_head(t_list **list)
{
	t_list	*fist_node;
	
	fist_node = malloc(sizeof(t_list));
	if (!fist_node)
	{
		perror("initialization list ");
		ft_master_free(list);
		return ;
	}
	fist_node->cmds = NULL;
	fist_node->tokens = NULL;
	fist_node->prev = NULL;
	fist_node->next = NULL;
	*list = fist_node;
}
// ft pour ajouter un noeud a la fin de la liste.
void	ft_add_node_end(t_list **list)
{
	t_list	*tmp_head;
	t_list	*new_node;
	
	if (!*list)
	{
		ft_init_list_head(list);
		return ;
	}
	new_node = malloc(sizeof (t_list));
	if (!new_node)
	{
		perror("initialization list ");
		return ;
	}
	tmp_head = *list;
	while (tmp_head->next != NULL)
		tmp_head = tmp_head->next;
	new_node->cmds = NULL;
	new_node->tokens = NULL;
	new_node->prev = tmp_head;
	new_node->next = NULL;
	tmp_head->next = new_node;
}
// ft pour ajouter un noeud au milieu de la liste.