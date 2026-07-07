/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:56:49 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/07 12:40:09 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory for an array of nmemb elements of size bytes each. Each byte
   of the memory area is set to 0. Returns NULL on error or overflow. */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rtrn;

	if (size)
		if (nmemb > SIZE_MAX / size)
			return (NULL);
	rtrn = malloc(nmemb * size);
	ft_bzero(rtrn, nmemb * size);
	return (rtrn);
}

/* --test program-- */

/*
typedef int	t_type;

int	main(int argc, char **argv)
{
	void	*dest1;
	void	*dest2;
	int		n;
	int		i;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	n = ft_atoi(argv[1]) * (int) sizeof(t_type);
	dest1 = calloc(n, sizeof(t_type));
	dest2 = ft_calloc(n, sizeof(t_type));
	ft_putendl_fd("Original: ", 1);
	if (!dest1)
		ft_putendl_fd("(null)", 1);
	else
	{
		i = 0;
		while (i < n)
		{
			ft_putnbr_fd((int)(((char *)dest1)[i++]), 1);
			if (i != n)
				ft_putstr_fd(", ", 1);
		}
		ft_putchar_fd('\n', 1);
		free(dest1);
	}
	ft_putendl_fd("My version: ", 1);
	if (!dest2)
		ft_putendl_fd("(null)", 1);
	else
	{
		i = 0;
		while (i < n)
		{
			ft_putnbr_fd((int)(((char *)dest2)[i++]), 1);
			if (i != n)
				ft_putstr_fd(", ", 1);
		}
		ft_putchar_fd('\n', 1);
		free(dest2);
	}
	return (0);
}
*/
