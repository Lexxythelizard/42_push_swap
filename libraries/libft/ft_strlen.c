/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:40:45 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:23:12 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Calculates the length of the string pointed to by s, excluding the 
   terminating null byte */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

/* --test program-- */

/*
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	ft_putstr_fd("Original: ", 1);
	ft_putnbr_fd((int)strlen(argv[1]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("My version: ", 1);
	ft_putnbr_fd((int)ft_strlen(argv[1]), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
