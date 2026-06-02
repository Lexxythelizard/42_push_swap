/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:15:38 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:22:49 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Appends at most size - ft_strlen(dst) - 1 bytes from src to dst, 
   null-terminating the result. Returns length of the string it tried to 
   create. */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	return (i + ft_strlcpy(dst + i, src, size - i));
}

/*	--test program-- */

/*
#include <bsd/string.h>

int	main(int argc, char **argv)
{
	char	*dest1;
	char	*dest2;
	int		n;
	int		len;

	if (argc != 4)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	n = ft_atoi(argv[3]);
	len = ft_strlen(argv[1]) + 1;
	if (len < n)
		len = n;
	dest1 = ft_calloc(len, 1);
	dest2 = ft_calloc(len, 1);
	ft_strlcpy(dest1, argv[1], len);
	ft_strlcpy(dest2, argv[1], len);
	ft_putendl_fd("Original: ", 1);
	ft_putstr_fd("Returns: ", 1);
	ft_putnbr_fd(strlcat(dest1, argv[2], n), 1);
	ft_putstr_fd("; String: ", 1);
	ft_putendl_fd(dest1, 1);
	ft_putendl_fd("My version: ", 1);
	ft_putstr_fd("Returns: ", 1);
	ft_putnbr_fd(ft_strlcat(dest2, argv[2], n), 1);
	ft_putstr_fd("; String: ", 1);
	ft_putendl_fd(dest2, 1);
	free(dest1);
	free(dest2);
	return (0);
}
*/
