/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:36:37 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:20:58 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the integer 'n' to the specified file descriptor */

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < -9 || n > 9)
		ft_putnbr_fd((n / 10) * (1 - 2 * (n < 0)), fd);
	ft_putchar_fd((n % 10) * (1 - 2 * (n < 0)) + '0', fd);
}

/* --test program-- */

/*
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	ft_putnbr_fd(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
*/
