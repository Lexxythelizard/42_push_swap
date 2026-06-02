/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:38:52 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:21:08 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the string pointed to by 's' to the specified file descriptor 'fd' */
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*(s++), fd);
}

/* --test program-- */

/*
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	ft_putstr_fd(argv[1], ft_atoi(argv[2]));
	return (0);
}
*/
