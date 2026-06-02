/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:44:49 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:14:55 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* erases the data in the n bytes of memory starting at the location pointed to
   by s, by filling it with null bytes */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* --test program-- */

/*
#include <strings.h>

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = ft_strdup("Hello World!");
	s2 = ft_strdup("Hello World!");
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	ft_putendl_fd("Original: ", 1);
	i = 0;
	bzero(s1, ft_atoi(argv[1]));
	ft_bzero(s2, ft_atoi(argv[1]));
	while (i < 12)
	{
		ft_putnbr_fd((int)(s1[i++]), 1);
		if (i != 12)
			ft_putstr_fd(", ", 1);
	}
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("My version: ", 1);
	i = 0;
	while (i < 12)
	{
		ft_putnbr_fd((int)(s2[i++]), 1);
		if (i != 12)
			ft_putstr_fd(", ", 1);
	}
	ft_putchar_fd('\n', 1);
	free(s1);
	free(s2);
	return (0);
}
*/
