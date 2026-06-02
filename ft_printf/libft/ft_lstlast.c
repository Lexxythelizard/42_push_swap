/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:54:37 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:18:26 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the last node of the list */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
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
	t_list	*rtrn;
	
	(void)argc;
	lst = NULL;
	i = 1;
	while (argv[i])
		ft_lstadd_front(&lst, ft_lstnew(argv[i++]));
	rtrn = ft_lstlast(lst);
	if (!rtrn)
		ft_putendl_fd("(null)", 1);
	else
	{
		ft_putendl_fd(rtrn -> content, 1);
		ft_lstclear(&lst, &rvn_del);
	}
	return (0);
}
*/
