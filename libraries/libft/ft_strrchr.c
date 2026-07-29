/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 22:23:59 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char	*ft_strrchr(const char *s, int c);

// --- define ---

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	while (s[i])
	{
		if (((unsigned char *)(s))[i] == (unsigned char)(c))
			ptr = (char *)(&(s[i]));
		i++;
	}
	if (((unsigned char *)(s))[i] == (unsigned char)(c))
		ptr = (char *)(&(s[i]));
	return (ptr);
}
