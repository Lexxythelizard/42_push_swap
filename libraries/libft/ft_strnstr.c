/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/09 13:49:08 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char		*ft_strnstr(const char *big, const char *little, size_t len);
static int	lxy_strncmp(const char *s1, const char *s2, size_t n);
static int	lxy_strlen(const char *str);

// --- define ---

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_l;
	size_t	len_b;
	size_t	i;

	i = 0;
	len_l = lxy_strlen(little);
	len_b = lxy_strlen(big);
	if (!(len_l))
		return ((char *)(&(big[i])));
	while ((i < len) && (i < len_b))
	{
		if (len_l > (len - i))
			return (NULL);
		if (!(lxy_strncmp(&(big[i]), little, len_l)))
			return ((char *)(&(big[i])));
		i++;
	}
	return (NULL);
}

// --- utility ---

static int	lxy_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!(n))
		return (0);
	while ((i + 1) < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return ((int)(s1[i] - s2[i]));
}

static int	lxy_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
