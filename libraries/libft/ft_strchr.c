/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 20:34:46 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char	*ft_strchr(const char *s, int c);

// --- define ---

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)(s);
	while (*ptr)
	{
		if (((unsigned char)(*ptr)) == (unsigned char)(c))
			return ((char *)(ptr));
		ptr++;
	}
	if (((unsigned char)(*ptr)) == (unsigned char)(c))
		return ((char *)(ptr));
	return (NULL);
}
