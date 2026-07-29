/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/11 17:32:57 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	ft_lstclear(t_list **lst, void (*del)(void*));

// --- DOC ---

/*
void ft_lstclear(t_list **lst, void (*del)(void*)) 
ittarates through the list 
and del frees the content of a every note, 
setting its pointer (content) to NULL and finally frees the whole node

REQUIRES:

    #include "libft.h"

    typedef struct s_list
    {
        void *content;
        struct s_list *next;
    } t_list

PARAMS:

	lst: The address of a pointer to a node.
	del: The address of the function used to delete the content of the node

DESCRIPTION:

	Deletes and frees the given node and all its successors, 
	using the function ’del’ and free(3).
	Finally, set the pointer to the list to NULL.

GUARD:

    if lst is NULL return void
    if lst -> content is NULL, do nothing

RETURN:

    ---
*/

// --- define ---

// recursive

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (lst == NULL)
		return ;
	ptr = *lst;
	if (ptr == NULL)
		return ;
	if ((*ptr).next != NULL)
		ft_lstclear(&((*ptr).next), del);
	ft_lstdelone(ptr, del);
	*lst = NULL;
}

// iterativ
/*
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (lst == NULL)
		return ;
	ptr = *lst;
	if (ptr == NULL)
		return ;
	if ((*ptr).next == NULL)
		ft_lstclear((lst + 1), del);
	ft_lstdelone(ptr, del);
}
*/
