/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/09 23:14:31 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

int	ft_memcmp(const void *s1, const void *s2, size_t n);

// --- define ---

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (!(n))
		return (0);
	while ((i + 1) < n)
	{
		c1 = ((unsigned char)((char *)(s1))[i]);
		c2 = ((unsigned char)((char *)(s2))[i]);
		if (c1 != c2)
			return ((int)(c1 - c2));
		i++;
	}
	c1 = ((unsigned char)((char *)(s1))[i]);
	c2 = ((unsigned char)((char *)(s2))[i]);
	return ((int)(c1 - c2));
}
