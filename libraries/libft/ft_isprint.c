/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:20:45 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:16:15 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks if 'c' (interpreted as unsigned char) is printable (value 32-126, i.e.
   including ' '). Returns 1 if true or 0 if false. */
int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
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
	ft_putnbr_fd(isprint(ft_atoi(argv[1])), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("My version: ", 1);
	ft_putnbr_fd(ft_isprint(ft_atoi(argv[1])), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
