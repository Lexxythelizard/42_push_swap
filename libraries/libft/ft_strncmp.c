/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/09 15:23:18 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Compares up to n bytes from s1 and s2. Returns the difference of the values 
   of the first bytes in s1 and s2 that differ or 0 if both strings 
   are equal */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if ((!s1 && !s2) || !n)
		return (0);
	if (!s1)
		return (-(unsigned char)(s2[0]));
	if (!s2)
		return ((unsigned char)(s1[0]));
	i = -1;
	while (++i < n)
		if (s1[i] != s2[i] || !(s1[i]) || !(s2[i]))
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	return (0);
}
