/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:53:11 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:38:32 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds and returns a pointer to the first occurence of the byte c in the
   memory area pointed to by 's' or NULL if not found within the 
   first n bytes */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (++i < n)
		if (((unsigned char *)s)[i] == c % 256)
			return ((void *)(s + i));
	return (NULL);
}

/* --test program-- */

/*
#include <string.h>

int	main(int argc, char **argv)
{
	void	*rtrn1;
	void	*rtrn2;
	int		n;

	if (argc != 4)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putendl_fd("Not a single character!", 2);
		return (-1);
	}
	n = ft_atoi(argv[3]);
	rtrn1 = memchr(argv[1], *(argv[2]), n);
	rtrn2 = ft_memchr(argv[1], *(argv[2]), n);
	ft_putstr_fd("Original: ", 1);
	if (!rtrn1)
		ft_putendl_fd("(null)", 1);
	else
		ft_putendl_fd(rtrn1, 1);
	ft_putstr_fd("My version: ", 1);
	if (!rtrn2)
		ft_putendl_fd("(null)", 1);
	else
		ft_putendl_fd(rtrn2, 1);
	return (0);
}
*/
