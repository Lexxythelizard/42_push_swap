/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:34:30 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:16:00 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks if 'c' (interpreted as unsigned char) is a digit (0-9). Returns 1 if
   true or 0 if false */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* --test program */

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
		return (-1);
	}
	ft_putstr_fd("Original: ", 1);
	ft_putnbr_fd(isdigit((unsigned char)(*(argv[1]))), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("My version: ", 1);
	ft_putnbr_fd(ft_isdigit((unsigned char)(*(argv[1]))), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
