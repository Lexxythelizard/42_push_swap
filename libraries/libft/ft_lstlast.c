/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/10 17:59:15 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

t_list	*ft_lstlast(t_list *lst);

// --- DOC ---

/*
t_list *ft_lstlast(t_list *lst) itarating through list
until it finds the note with the NULL pointer

REQUIRES:

    #include "libft.h"

    typedef struct s_list
    {
        void *content;
        struct s_list *next;
    } t_list

PARAMS:

    lst: The beginning of the list.

DESCRIPTION:

    Counts the number of nodes in the list.

GUARD:

    if first element lst is NULL, return NULL

RETURN:

    Pointer to last node of the list
	NULL if Guard was triggerd
*/

// --- define ---

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	if (ptr == NULL)
		return (NULL);
	while ((*ptr).next != NULL)
		ptr = (*ptr).next;
	return (ptr);
}
