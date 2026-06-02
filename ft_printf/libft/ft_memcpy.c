/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:20:58 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:19:38 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies n bytes from memory area src to 'dest'. The memory areas MUST NOT 
   overlap. */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
		return (dest);
	while (n--)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest); 
}

/* --test program-- */

/*
#include <string.h>

int	main(int argc, char **argv)
{
	int		n;
	char	*dest1;
	char	*dest2;

	if (argc != 3)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	n = ft_atoi(argv[2]);
	dest1 = ft_calloc(n + 1, 1);
	dest2 = ft_calloc(n + 1, 1);
	memcpy(dest1, argv[1], n);
	ft_memcpy(dest2, argv[1], n);
	ft_putstr_fd("Original: ", 1);
	ft_putendl_fd(dest1, 1);
	ft_putstr_fd("My version: ", 1);
	ft_putendl_fd(dest2, 1);
	free(dest1);
	free(dest2);
	return (0);
}
*/
