/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:18:00 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/06 23:06:18 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds and returns a pointer to the LAST occurence of the character c 
   in 's' or NULL if not found */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (c % 256 == 0)
		return ((char *)(s + i));
	while (i--)
		if ((unsigned char)(s[i]) == c % 256)
			return ((char *)(s + i));
	return (NULL);
}

/* --test program-- */

/*
#include <string.h>

int	main(int argc, char **argv)
{
	char	*rtrn1;
	char	*rtrn2;

	if (argc != 3)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putendl_fd("Not a single character!", 2);
		return (-1);
	}
	rtrn1 = strrchr(argv[1], *(argv[2]));
	rtrn2 = ft_strrchr(argv[1], *(argv[2]));
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
