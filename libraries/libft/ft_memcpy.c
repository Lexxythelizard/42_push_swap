/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/09 22:45:20 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	*ft_memcpy(void *dest, const void *src, size_t n);

// --- DOC ---

/*
*ft_memcpy() copying byte by byte 

RETURN:

    Pointer to s

NOTE:

	Undefined behavior if memory overlaps and 
	location of src < location of dest
	use ft_memmove() in unknown cases
*/

// --- define ---

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char *)(dest))[i] = ((char *)(src))[i];
		i++;
	}
	return (dest);
}
