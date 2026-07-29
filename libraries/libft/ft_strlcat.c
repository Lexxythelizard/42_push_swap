/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/09 13:42:16 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

size_t	ft_strlcat(char *dst, const char *src, size_t size);

// --- define ---

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (((i + j + 1) < size) && (src[j]))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	j = 0;
	while (src[j])
		j++;
	if (size < i)
		return (size + j);
	return (i + j);
}
