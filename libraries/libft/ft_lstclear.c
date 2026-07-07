/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:25:04 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:35:24 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Deletes and frees the given node and all its successors, using the function
   del to free the nodes' content and free. Sets the pointer to the list to 
   NULL. */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst)
	{
		if (*lst)
		{
			if ((*lst)->next)
				ft_lstclear(&((*lst)->next), del);
			ft_lstdelone(*lst, del);
			*lst = NULL;
		}
	}
}

/* --test program-- */

/* None, use valgrind on any of the other test programs in this section */
