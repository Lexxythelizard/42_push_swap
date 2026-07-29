/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 17:42:09 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	*ft_memmove(void *dest, const void *src, size_t n);

// --- DOC ---

/*
*ft_memmove() acts like if it would store the memory in an array 
before copying it. 
Actually it checks if location of source is > location of dest 
to either coping forward or backward

GUARD:

	if n is 0 just return dest

RETURN:

	Pointer to dest
*/

// --- define ---

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!(n))
		return (dest);
	if (src < dest)
	{
		i = n - 1;
		while (i > 0)
		{
			((char *)(dest))[i] = ((char *)(src))[i];
			i--;
		}
		((char *)(dest))[i] = ((char *)(src))[i];
		return (dest);
	}
	while (i < n)
	{
		((char *)(dest))[i] = ((char *)(src))[i];
		i++;
	}
	return (dest);
}
