/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:06:31 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:15:48 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks if 'c' (interpreted as unsigned char) is an 
   ASCII character (value 0-127). Returns 1 if true or 0 if false. */
int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
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
	ft_putstr_fd("Original: ", 1);
	ft_putnbr_fd(isascii(ft_atoi(argv[1])), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("My version: ", 1);
	ft_putnbr_fd(ft_isascii(ft_atoi(argv[1])), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
