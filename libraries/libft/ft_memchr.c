/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 17:25:41 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	*ft_memchr(const void *s, int c, size_t n);

// --- define ---

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while ((i + 1) < n)
	{
		if (((unsigned char *)(s))[i] == (unsigned char)(c))
			return (&(((unsigned char *)(s))[i]));
		i++;
	}
	if (((unsigned char *)(s))[i] == (unsigned char)(c))
		return (&(((unsigned char *)(s))[i]));
	return (NULL);
}
