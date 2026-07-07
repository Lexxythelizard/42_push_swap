/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:47:00 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:15:30 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks if 'c' (interpreted as unsigned char) is alphabetical (A-Z or a-z).
   Returns 1 if true or 0 if false. */
int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

/* --test program-- */

/*
#include <ctype.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	if (ft_strlen(argv[1]) != 1)
	{
		ft_putendl_fd("Not a single character!", 2);
	}
	ft_putstr_fd("Original: ", 1);
	ft_putnbr_fd(isalpha((unsigned char)(*(argv[1]))), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("My version: ", 1);
	ft_putnbr_fd(ft_isalpha((unsigned char)(*(argv[1]))), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
