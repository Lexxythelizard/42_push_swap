/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:09:49 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:35:50 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates through the list lst and applies the function f to the content of
   each node */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

/* --test program-- */

/*
static void	rvn_print(void *s);
static void	rvn_del(void *s);

// Replaces a string with null bytes
static void	rvn_del(void *s)
{
	if (s)
		while (*((char *)s))
			*((char *)(s++)) = '\0';
}

// Prints a string to stdout, followed by a newline
static void	rvn_print(void *s)
{
	ft_putendl_fd((char *)s, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*lst;

	if (argc == 1)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	i = 1;
	lst = NULL;
	while (argv[i])
		ft_lstadd_front(&lst, ft_lstnew(argv[i++]));
	ft_lstiter(lst, &rvn_print);
	ft_lstclear(&lst, &rvn_del);
	return (0);
}
*/
