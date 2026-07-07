/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:41:51 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:25:30 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of nodes in the list */
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
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
	int		i;
	t_list	*lst;

	(void)argc;
	lst = NULL;
	i = 1;
	while (argv[i])
		ft_lstadd_front(&lst, ft_lstnew(argv[i++]));
	ft_putnbr_fd(ft_lstsize(lst), 1);
	ft_putchar_fd('\n', 1);
	ft_lstclear(&lst, &rvn_del);
	return (0);
}
*/
