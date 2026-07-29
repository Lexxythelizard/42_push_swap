/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 16:55:41 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

int	ft_lstsize(t_list *lst);

// --- DOC ---

/*
ft_lstsize(t_list *lst) itarating through list and counting the nodes

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

    if allocation fails returning NULL

RETURN:

    Pointer to new node
*/

// --- define ---

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	count = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr = (*ptr).next;
	}
	return (count);
}
