/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:33:52 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:23:42 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Compares up to n bytes from s1 and s2. Returns the difference of the values 
   of the first bytes in s1 and s2 that differ or 0 if both strings 
   are equal */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if ((!s1 && !s2) || !n)
		return (0);
	if (!s1)
		return (-(unsigned char)(s2[0]));
	if (!s2)
		return ((unsigned char)(s1[0]));
	i = -1;
	while (++i < n)
		if (s1[i] != s2[i] || !(s1[i]) || !(s2[i]))
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
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
	ft_putnbr_fd(strncmp(argv[1], argv[2], n), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("My version: ", 1);
	ft_putnbr_fd(ft_strncmp(argv[1], argv[2], n), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
