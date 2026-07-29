/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 16:56:35 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	ft_putnbr_fd(int n, int fd);

// --- DOC ---

/*

*/

// --- scrats notes (delete later) ---

/*
	... notes...
*/

// --- define ---

void	ft_putnbr_fd(int n, int fd)
{
	int		divisor;
	char	c;

	divisor = 1;
	if (n < 0)
		write(fd, "-", 1);
	else
		n *= (-1);
	while (((int)(n / divisor)) <= (-10))
		divisor *= 10;
	while (divisor >= 10)
	{
		c = (char)(((int)(n / divisor) *(-1)) + 48);
		write(fd, &c, 1);
		n %= divisor;
		divisor /= 10;
	}
	c = (char)(((int)(n / divisor) *(-1)) + 48);
	write(fd, &c, 1);
}
