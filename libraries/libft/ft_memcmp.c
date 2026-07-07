/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 19:19:14 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:19:23 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Compares the first n bytes of the memory areas pointed to by s1 and s2.
   Returns the difference of the values of the first bytes that differ or 0
   if the memory is equal */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if ((!s1 && !s2) || !n)
		return (0);
	i = -1;
	if (!s1)
	{
		while (++i < n)
			if (0 != ((unsigned char *)s2)[i])
				return (-((unsigned char *)s2)[i]);
		return (0);
	}
	if (!s2)
	{
		while (++i < n)
			if (((unsigned char *)s1)[i] != 0)
				return (((unsigned char *)s1)[i]);
		return (0);
	}
	while (++i < n)
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

/* --test program-- */

/*
#include <string.h>

int	main(int argc, char **argv)
{
	int	n;

	if (argc != 4)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	n = ft_atoi(argv[3]);
	ft_putstr_fd("Original: ", 1);
	ft_putnbr_fd(memcmp(argv[1], argv[2], n), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("My version: ", 1);
	ft_putnbr_fd(ft_memcmp(argv[1], argv[2], n), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
