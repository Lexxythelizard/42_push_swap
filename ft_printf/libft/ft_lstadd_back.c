/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:08:19 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:33:22 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the node 'new' at the end of the list */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last -> next = new;
		}
		else
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
	t_list	*lst;
	t_list	*new;
	t_list	*h;

	if (argc != 3)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	lst = ft_lstnew(argv[1]);
	new = ft_lstnew(argv[2]);
	ft_lstadd_back(&lst, new);
	ft_putchar_fd('\'', 1);
	h = lst;
	while (h)
	{
		ft_putstr_fd(h -> content, 1);
		if (h -> next)
			ft_putstr_fd("\', \'", 1);
		h = h -> next;
	}
	ft_putendl_fd("\'", 1);
	ft_lstclear(&lst, &rvn_del);
	return (0);
}
*/
