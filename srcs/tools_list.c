/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:12:08 by pbret             #+#    #+#             */
/*   Updated: 2025/02/01 21:30:08 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// ft pour gerer l'initialisation de  la liste
void	ft_list_manag(char *cmds_brut)
{
	
}

// ft pour creer le 1er noeud de la liste avec le pointeur head qui pointe dessus
void	ft_init_list_head(t_node **list_elem)
{
	t_node	*fist_node;
	
	fist_node = malloc(sizeof(t_node));
	if (!fist_node)
	{
		perror("initialization list ");
		ft_master_free(list_elem);
		return ;
	}
	fist_node->cmds = NULL;
	fist_node->tokens = NULL;
	fist_node->env = NULL;
	fist_node->prev = NULL;
	fist_node->next = NULL;
	*list_elem = fist_node;
}
// ft pour ajouter un noeud a la fin de la liste.
void	ft_add_node_end(t_node **list_elem)
{
	t_node	*tmp_head;
	t_node	*new_node;
	
	if (!*list_elem)
	{
		ft_init_list_head(list_elem);
		return ;
	}
	new_node = malloc(sizeof (t_node));
	if (!new_node)
	{
		perror("initialization list ");
		ft_master_free(list_elem);
		return ;
	}
	tmp_head = *list_elem;
	while (tmp_head->next != NULL)
		tmp_head = tmp_head->next; 
	new_node->cmds = NULL;
	new_node->tokens = NULL;
	new_node->env = NULL;
	new_node->prev = tmp_head;
	new_node->next = NULL;
	tmp_head->next = new_node;
}
// ft pour ajouter un noeud au milieu de la liste.