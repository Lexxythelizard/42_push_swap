/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:03:46 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:45:25 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory and returns a pointer to a new string which is a duplicate
   of 's'. Returns NULL on error. */
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*rtrn;

	len = ft_strlen(s);
	rtrn = malloc(len + 1);
	if (!rtrn)
		return (NULL);
	ft_strlcpy(rtrn, s, len + 1);
	return (rtrn);
}

/* --test program-- */

/*
#include <string.h>

int	main(int argc, char **argv)
{
	char	*dup1;
	char	*dup2;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	dup1 = strdup(argv[1]);
	dup2 = ft_strdup(argv[1]);
	ft_putstr_fd("Original: ", 1);
	if (!dup1)
		ft_putendl_fd("(null)", 1);
	else
	{
		ft_putendl_fd(dup1, 1);
		free(dup1);
	}
	ft_putstr_fd("My version: ", 1);
	if (!dup2)
		ft_putendl_fd("(null)", 1);
	else
	{
		ft_putendl_fd(dup2, 1);
		free(dup2);
	}
	return (0);
}
*/
