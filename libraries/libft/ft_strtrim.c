/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 22:24:27 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char		*ft_strtrim(char const *s1, char const *set);
static int	lxy_is_chr_in_str(const char *str, char c);

// --- DOC ---

/*
DESCRIPTION:

ft_strtrim allocates memory malloc() and returns a copy of 
’s1’ with characters from ’set’ removed from the beginning and the end
by using ft_strlcpy 
utility : lxy_is_chr_in_str(const char *str, const char c)

PARAMS:

    s1:		string
    set:	set of characters to look for

GUARD:

    if s1 or set is NULL return NULL
    if memory allocation fails returns NULL

RETURN:

    pointer to new string
    NULL if Guard was triggered

*/

// --- define ---

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	stop;
	size_t	len_trimmed;
	char	*trimmed;

	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	start = 0;
	stop = ft_strlen(s1);
	if (stop)
		stop--;
	while (lxy_is_chr_in_str(set, s1[start]))
		start++;
	while ((stop > 0) && (lxy_is_chr_in_str(set, s1[stop])))
		stop--;
	len_trimmed = stop - start + 1;
	if (!(s1[0]))
		len_trimmed = 0;
	if (stop < start)
		len_trimmed = 0;
	trimmed = malloc(len_trimmed + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, &(s1[start]), (len_trimmed + 1));
	return (trimmed);
}

// --- utilities ---

/*
lxy_is_chr_in_str() just lookes if it encounters 
char c in string str:

return:

	int		0 : 1		True / False
*/

static int	lxy_is_chr_in_str(const char *str, const char c)
{
	char	*ptr;

	ptr = (char *)(str);
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}
