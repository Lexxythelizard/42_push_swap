/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:45:56 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:55:36 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory and returns a substring of s, starting at start and having
   maximum length len. Returns NULL on error */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*rtrn;

	slen = ft_strlen(s);
	if (start > slen)
	{
		start = 0;
		len = 0;
	}
	else if (start + len > slen)
		len = slen - start;
	rtrn = malloc(len + 1);
	if (!rtrn)
		return (NULL);
	ft_strlcpy(rtrn, s + start, len + 1);
	rtrn[len] = '\0';
	return (rtrn);
}

/* --test program-- */

/*
int	main(int argc, char **argv)
{
	char	*rtrn;

	if (argc != 4)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	rtrn = ft_substr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
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
