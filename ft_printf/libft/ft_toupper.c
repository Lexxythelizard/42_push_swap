/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:43:18 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:24:58 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Converts lowercase characters to uppercase */
int	ft_toupper(int c)
{
	return (c - 32 * ('a' <= c && c <= 'z'));
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
		return (-1);
	}
	ft_putstr_fd("Original: ", 1);
	ft_putchar_fd(toupper(*(argv[1])), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("My version: ", 1);
	ft_putchar_fd(ft_toupper(*(argv[1])), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
