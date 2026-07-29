/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 16:54:01 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	ft_lstadd_back(t_list **lst, t_list *new);

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

    Adds the node ’new’ at the end of the list.

GUARD:

    if lst is NULL, or new is NULL: return (void);

RETURN:

    ---
*/

// --- define ---

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if ((lst == NULL) || (new == NULL))
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while ((*ptr).next != NULL)
		ptr = (*ptr).next;
	(*ptr).next = new;
}
