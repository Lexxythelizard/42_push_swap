/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:55:49 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:30:09 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Converts the string pointed to by 'nptr' to int and returns the result.
   Returns 0 on error. */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	rtrn;

	if (!nptr)
		return (0);
	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	sign = 1 - 2 * (nptr[i] == '-');
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	rtrn = 0;
	while (ft_isdigit(nptr[i]))
		rtrn = rtrn * 10 + (nptr[i++] - '0');
	return (rtrn * sign);
}

/* --test program-- */

/*
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	ft_putstr_fd("Original: ", 1);
	ft_putnbr_fd(atoi(argv[1]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("My version: ", 1);
	ft_putnbr_fd(ft_atoi(argv[1]), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/
