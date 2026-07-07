/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:48:22 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:52:15 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory and returns a copy of the string pointed to by 's1' with 
   characters from 'set' removed from beginning and end. Returns NULL on
   error. */
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1 + start);
	while (len && ft_strchr(set, s1[start + len - 1]))
		len--;
	return (ft_substr(s1, start, len)); 
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
	rtrn = ft_strtrim(argv[1], argv[2]);
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
