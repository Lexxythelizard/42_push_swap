/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:43:18 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/07 12:03:55 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Locates and returns a pointer to the first occurence of the string little in
   'big', where no more than len characters are searched */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little)
		return ((char *)big);
	if (!(*little))
		return ((char *)big);
	i = 0;
	j = 0;
	while (i + j < len && big[i + j])
	{
		if (big[i + j] == little[j])
		{
			j++;
			if (!(little[j]))
				return ((char *)(big + i));
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}

/* --test program-- */

/*
#include <bsd/string.h>

int	main(int argc, char **argv)
{
	char	*rtrn1;
	char	*rtrn2;
	int		n;

	if (argc != 4)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	n = ft_atoi(argv[3]);
	rtrn1 = strnstr(argv[1], argv[2], n);
	rtrn2 = ft_strnstr(argv[1], argv[2], n);
	ft_putstr_fd("Original: ", 1);
	if (!rtrn1)
		ft_putendl_fd("(null)", 1);
	else
		ft_putendl_fd(rtrn1, 1);
	ft_putstr_fd("My version: ", 1);
	if (!rtrn2)
		ft_putendl_fd("(null)", 1);
	else
		ft_putendl_fd(ft_strnstr(argv[1], argv[2], n), 1);
	return (0);
}
*/
