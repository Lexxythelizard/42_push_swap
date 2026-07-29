/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 22:47:01 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char	*ft_strdup(const char *s);

// --- DOC ---
/*

DESCRIPTION:

	The  strdup() function returns a pointer to a new string 
	which is a duplicate of the string s.
    Memory for the new string is obtained with malloc(3), 
	and can be freed with free(3).

PARAMS:

    s:     string

GUARD:

    if memory allocation fails returns NULL

RETURN:

    pointer to new string
    NULL if Guard was triggered

NOTE:

	Behaves like the original:
	--> ft_strdup(NULL) --> segfault or undefined

*/

// --- define ---

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	dup = malloc((len + 1));
	if (dup == NULL)
		return (NULL);
	while (i <= len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
