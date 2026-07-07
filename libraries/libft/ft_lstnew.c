/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:37:39 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:18:35 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory and returns a new node, the 'content' variable is
   initialized to content and the 'next' variable is initialized to NULL.
   Returns NULL on error. */
t_list	*ft_lstnew(void *content)
{
	t_list	*rtrn;

	rtrn = malloc(16);
	if (!rtrn)
		return (NULL);
	rtrn -> content = content;
	rtrn -> next = NULL;
	return (rtrn);
}

/* --test program-- */

/*
int	main(int argc, char **argv)
{
	t_list	*rtrn;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	rtrn = ft_lstnew(argv[1]);
	if (!rtrn)
		ft_putendl_fd("(null)", 1);
	else
	{
		ft_putendl_fd(rtrn -> content, 1);
		free(rtrn);
	}
	return (0);
}
*/
