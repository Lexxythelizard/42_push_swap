/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/11 13:15:38 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	ft_lstadd_front(t_list **lst, t_list *new);

// --- DOC ---

/*
ft_lstnew(void *content) initializing a new node using

    typedef struct s_list
    {
        void *content;
        struct s_list *next;
    } t_list

PARAMS:

	lst: The address of a pointer to the first node ofa list.
	new: The address of a pointer to the node to be added

DESCRIPTION:

	Adds the node ’new’ at the beginning of the list.

GUARD:

    if allocation fails returning NULL

RETURN:

    Pointer to new node
*/

// --- define ---

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((lst == NULL) || (new == NULL))
		return ;
	(*new).next = *lst;
	*lst = new;
}
