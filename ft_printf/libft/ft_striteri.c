/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:26:36 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:49:35 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = -1;
	if (s && f)
		while (s[++i])
			f(i, s + i);
}

/* --test program-- */

/*
static void	rvn_fun(unsigned int n, char *c);

// Replaces each even-indexed character with its lowercase version and each
// odd-indexed character with its uppercase version
static void	rvn_fun(unsigned int n, char *c)
{
	if (n % 2)
		*c = ft_toupper(*c);
	else
		*c = ft_tolower(*c);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	ft_striteri(argv[1], &rvn_fun);
	ft_putendl_fd(argv[1], 1);
	return (0);
}
*/
