/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 16:57:41 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// --- DOC ---

/*
void ft_lstadd_back(t_list **lst, t_list *new) itarating through list
until it finds the note with the NULL pointer and appending new to it.

REQUIRES:

    #include "libft.h"

    typedef struct s_list
    {
        void *content;
        struct s_list *next;
    } t_list

PARAMS:

    lst: The address of a pointer to the first node of a list.
    new: The address of a pointer to the node to be added.

DESCRIPTION:

    Iterates through the list ’lst’, applies the function 
’f’ to each node’s content, and creates a new list resulting 
of the successive applications of the function ’f’. 
The ’del’ function is used to delete the content of a node if needed.

GUARD:

    if lst is NULL, or new is NULL: return (void);

RETURN:

    ---

*/

// --- scrats notes (delete later) ---

// --- define ---

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*current;

	if ((lst == NULL) || (f == NULL) || (del == NULL))
		return (NULL);
	first = ft_lstnew(f((*lst).content));
	current = first;
	if (current == NULL)
		return (NULL);
	if ((*current).content == NULL)
		ft_lstdelone(first, del);
	while ((*lst).next != NULL)
	{
		lst = (*lst).next;
		ft_lstadd_back(&current, ft_lstnew(f((*lst).content)));
		current = (*current).next;
		if ((current == NULL) || ((*current).content == NULL))
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
	}
	return (first);
}
