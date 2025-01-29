/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:45:16 by pbret             #+#    #+#             */
/*   Updated: 2025/01/16 12:21:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Itère sur la liste ’lst’ et applique la fonction ’f’au contenu de chaque élém.
Crée une nouvelle liste résultant des applications successives de’f’.
La fonction ’del’ est là pour détruire lecontenu d’un élément si nécessaire.
-------------------------------------------------------------------------------
Declaration	'newlst' future nouvelle liste chainee
			'tmp' stock temporairement le nouveau noeud
			'tmp_content' stock le contenu du noeud modifier par (*f)
Check si les pointeurs lst ou des fonctions ne soient pas nul -> return NULL
Boucle tant que 'lst' existe :
1]	le pointeur 'tmp_content' prend (la resultante de (*f)) et (du contenu de lst)
	'tmp' pointe vers le nouveau noeud cree avec le contenu de 'lst' via ft_lstnew
2]	si l'alloc a fail -> supression du contenu avec (*del)
	supression de la nouvelle liste chainee ((del) du contenu + free)
	return NULL
3]	Lier le nouveau noeud (tmp) a la la nouvelle liste chainee (newlst)
	Next noeud -> le pointeur 'lst' devient le pointeur du contenur du noeud suivant
	Totalite de 'lst' a ete traite avec succes, la fonciton renvoie un pointeur
	vers la nouvelle liste chainee
-------------------------------------------------------------------------------
LEXIQUE
element = node = noeud
'->' = operateur de deferencement vers un membre du prochain noeud
membre = une partir d'un noeud
ex: la struct t_list a comment membres "content" et "next"
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;
	void	*tmp_content;

	if (lst == 0 || (*f) == 0 || (*del) == 0)
		return (NULL);
	newlst = 0;
	while (lst)
	{
		tmp_content = (*f)(lst -> content);
		tmp = ft_lstnew(tmp_content);
		if (!tmp)
		{
			(*del)(tmp_content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}	
		ft_lstadd_back(&newlst, tmp);
		lst = lst -> next;
	}
	return (newlst);
}
