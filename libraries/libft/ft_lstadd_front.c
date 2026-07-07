/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:55:00 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:17:46 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Uses type t_list */
#include "libft.h"

/* Adds the node 'new' to the beginning of the list 'lst' */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new -> next = *lst;
		*lst = new;
	}
}

/* --test program-- */

/*
static void	rvn_del(void *s);

// Replaces a string with null bytes
static void	rvn_del(void *s)
{
	if (s)
		while (*((char *)s))
			*((char *)(s++)) = '\0';
}

int	main(int argc, char **argv)
{
	t_list	*new;
	t_list	*lst;

	if (argc != 3)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	new = ft_lstnew(argv[2]);
	lst = ft_lstnew(argv[1]);
	ft_lstadd_front(&lst, new);
	ft_putchar_fd('\'', 1);
	while (new)
	{
		ft_putstr_fd(new -> content, 1);
		if (new -> next)
			ft_putstr_fd("\', \'", 1);
		new = new -> next;
	}
	ft_putendl_fd("\'", 1);
	ft_lstclear(&lst, &rvn_del);
	return (0);
}
*/
