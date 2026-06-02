/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:46:46 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:35:39 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Takes a node as parameter and frees its content using the function 'del'.
   Frees the node itself but does NOT free the next node. */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst -> content);
		lst -> content = NULL;
		lst -> next = NULL;
		free(lst);
	}
}

/* --test program-- */

/* None, use valgrind on any of the other programs in this section. */
