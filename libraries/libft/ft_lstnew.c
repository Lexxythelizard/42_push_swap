/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/11 13:13:48 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

t_list	*ft_lstnew(void *content);

// --- DOC ---

/*
ft_lstnew(void *content) initializing a new node using

	typedef struct s_list
	{
		void *content;
		struct s_list *next;
	} t_list

GUARD:

	if allocation fails returning NULL

RETURN:

	Pointer to new node
*/

// --- define ---

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(2 * sizeof(void *));
	if (new_node == NULL)
		return (NULL);
	(*new_node).content = content;
	(*new_node).next = NULL;
	return (new_node);
}
