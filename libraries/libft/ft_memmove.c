/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:41:58 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:19:53 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies n bytes from 'src' to 'dest'. The memory areas may overlap. */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (dest);
	i = -1;
	if (dest < src)
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	else
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

/* --test program-- */

/*
#include <string.h>

int	main(int argc, char **argv)
{
	int		offset;
	int		nbr;
	char	*test1;
	char	*test2;

	if (argc != 3)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	offset = ft_atoi(argv[1]);
	nbr = ft_atoi(argv[2]);
	if (offset < -20 || offset + nbr > 32 || nbr > 32)
	{
		ft_putendl_fd("Trying to access outside of assigned memory.\n" \
		"Please choose an offset between -20 and 20 and a number\n" \
		"between 0 and 12 to make sure this doesn't happen!", 2);
		return (-1);
	}
	test1 = ft_calloc(53, 1);
	test2 = ft_calloc(53, 1);
	ft_memset(test1, '0', 52);
	ft_memcpy(test1 + 20, "Hello World!", 12);
	ft_memcpy(test2, test1, 52);
	memmove(test1 + 20 + offset, test1 + 20, nbr);
	ft_memmove(test2 + 20 + offset, test2 + 20, nbr);
	ft_putstr_fd("Original:   ", 1);
	ft_putendl_fd(test1, 1);
	ft_putstr_fd("My version: ", 1);
	ft_putendl_fd(test2, 1);
	free(test1);
	free(test2);
	return (0);
}
*/
