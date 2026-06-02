/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:29:04 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:46:34 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory and returns a new string which is the result of
   concatenating 's1' and 's2'. Returns NULL on error. */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	size;
	char	*rtrn;

	len1 = ft_strlen(s1) + 1;
	size = len1 + ft_strlen(s2);
	rtrn = malloc(size);
	if (!rtrn)
		return (NULL);
	ft_strlcpy(rtrn, s1, len1);
	ft_strlcat(rtrn, s2, size);
	return (rtrn);
}

/* --test program-- */

/*
int	main(int argc, char **argv)
{
	char	*rtrn;

	if (argc != 3)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	rtrn = ft_strjoin(argv[1], argv[2]);
	if (!rtrn)
		ft_putendl_fd("(null)", 1);
	else
	{
		ft_putendl_fd(rtrn, 1);
		free(rtrn);
	}
	return (0);
}
*/
