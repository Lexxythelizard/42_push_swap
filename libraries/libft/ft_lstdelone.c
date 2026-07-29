/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/11 16:37:03 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	ft_lstdelone(t_list *lst, void (*del)(void*));

// --- DOC ---

/*
void ft_lstdelone(t_list *lst, void (*del)(void*)) frees the content of a note
and setting its pointer (content) to NULL(?)

REQUIRES:

    #include "libft.h"

    typedef struct s_list
    {
        void *content;
        struct s_list *next;
    } t_list

PARAMS:

    lst: The node to free.
	del: The address of the function used to delete the content.

DESCRIPTION:

    Takes a node as parameter and frees its content
	using the function ’del’. 
	Free the node itself but does NOT free the next node

GUARD:

    if lst is NULL return void
	if lst -> content is NULL, do nothing

RETURN:

    ---

*/

// --- define ---

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del((*lst).content);
	free(lst);
	lst = NULL;
}
