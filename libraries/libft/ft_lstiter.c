/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 14:56:36 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	ft_lstiter(t_list *lst, void (*f)(void *));

// --- DOC ---

/*


PARAMS

	lst: The address of a pointer to a node.
	f: The address of the function to apply to each node’s content

DESCRIPTION:

	Iterates through the list ’lst’ and applies the
	function ’f’ to the content of each node.

RETURN:

	---
*/

// --- define ---

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	ptr = lst;
	if ((ptr == NULL) || (f == NULL))
		return ;
	f((*ptr).content);
	while ((*ptr).next != NULL)
	{
		ptr = (*ptr).next;
		f((*ptr).content);
	}
}
