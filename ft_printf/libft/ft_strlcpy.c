/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:39:39 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/07 12:45:45 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies up to size - 1 bytes from src to dst and null-terminates the result.
   Returns length of string it tried to create. */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (ft_strlen(src));
	i = 0;
	if (size)
		dst[0] = src[0];
	while (src[i++])
		if (i < size)
			dst[i] = src[i];
	if (size && i > size)
		dst[size - 1] = '\0';
	return (i - 1);
}

/* --test program-- */

/*
#include <bsd/string.h>

int	main(int argc, char **argv)
{
	char	*dest1;
	char	*dest2;
	int		n;

	if (argc != 3)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	n = ft_atoi(argv[2]);
	dest1 = ft_calloc(n, 1);
	dest2 = ft_calloc(n, 1);
	ft_putendl_fd("Original: ", 1);
	ft_putstr_fd("Returns: ", 1);
	ft_putnbr_fd(strlcpy(dest1, argv[1], n), 1);
	ft_putstr_fd("; String: ", 1);
	ft_putendl_fd(dest1, 1);
	ft_putendl_fd("My version: ", 1);
	ft_putstr_fd("Returns: ", 1);
	ft_putnbr_fd(ft_strlcpy(dest2, argv[1], n), 1);
	ft_putstr_fd("; String: ", 1);
	ft_putendl_fd(dest2, 1);
	free(dest1);
	free(dest2);
	return (0);
}
*/
