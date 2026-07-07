/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:09:19 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:36:34 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates through the list 'lst', applies the function 'f' to each node's
   content and creates a new list resulting of the successive applications of
   the function f. The del function is used to delete the content of a node if
   needed. */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rtrn;
	t_list	*curr;

	rtrn = NULL;
	while (lst && f && del)
	{
		if (!rtrn)
		{
			rtrn = ft_lstnew(f(lst -> content));
			curr = rtrn;
		}
		else
		{
			ft_lstadd_back(&curr, ft_lstnew(f(lst -> content)));
			curr = curr -> next;
		}
		if (!curr)
		{
			ft_lstclear(&rtrn, del);
			return (NULL);
		}
		lst = lst -> next;
	}
	return (rtrn);
}

/* --test program-- */

/*
static void *rvn_fun(void *s);
static void	rvn_del1(void *s);
static void rvn_del2(void *s);

// Replaces a string with null bytes
static void	rvn_del1(void *s)
{
	if (s)
		while (*((char *)s))
			*((char *)(s++)) = '\0';
}

// Replaces a string with null bytes and frees the pointer
static void rvn_del2(void *s)
{
	rvn_del1(s);
	free(s);
}

//Allocates memory and appends "bla" to each string
static void	*rvn_fun(void *s)
{
	void	*rtrn;
	rtrn = ft_strjoin((char *)s, "bla");
	return (rtrn);	 
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*rtrn;
	size_t	i;

	(void)argc;
	lst = NULL;
	i = 1;
	while (argv[i])
		ft_lstadd_front(&lst, ft_lstnew(argv[i++]));
	rtrn = ft_lstmap(lst, &rvn_fun, &rvn_del1);
	ft_lstclear(&lst, &rvn_del1);
	if (!rtrn)
		ft_putendl_fd("(null)", 1);
	else
	{
		lst = rtrn;
		ft_putchar_fd('\'', 1);
		while (rtrn)
		{
			ft_putstr_fd(rtrn -> content, 1);
			if (rtrn -> next)
				ft_putstr_fd("\', \'", 1);
			rtrn = rtrn -> next;
		}
		ft_putendl_fd("\'", 1);
		ft_lstclear(&lst, &rvn_del2);
	}
	return (0);
}
*/
