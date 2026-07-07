/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:39:26 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 16:20:10 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Fills the first n bytes of the memory area pointed to by 's' with the
   character c */
void	*ft_memset(void *s, int c, size_t n)
{
	if (!s)
		return (s);
	while (n)
		((char *)s)[--n] = c;
	return (s);
}

/* --test program-- */

/*
#include <string.h>

int	main(int argc, char **argv)
{
	int		n;
	void	*dest1;
	void	*dest2;

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
	n = ft_atoi(argv[2]);
	dest1 = ft_calloc(n + 1, 1);
	dest2 = ft_calloc(n + 1, 1);
	ft_putstr_fd("Original: ", 1);
	ft_putendl_fd(memset(dest1, (unsigned char)(*(argv[1])), n), 1);	
	ft_putstr_fd("My version: ", 1);
	ft_putendl_fd(ft_memset(dest2, (unsigned char)(*(argv[1])), n), 1);
	free(dest1);
	free(dest2);
	return (0);
}

*/
