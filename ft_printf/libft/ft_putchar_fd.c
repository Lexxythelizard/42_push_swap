/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:23:53 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:20:33 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the character 'c' to the specified file descriptor 'fd' */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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
	if (ft_strlen(argv[1]) != 1)
	{
		ft_putendl_fd("Not a single character!", 2);
		return (-1);
	}
	ft_putchar_fd(*(argv[1]), ft_atoi(argv[2]));
	return (0);
}
*/
