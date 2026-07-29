/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 21:22:42 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char	*ft_strjoin(char const *s1, char const *s2);

// --- DOC ---

/*
DESCRIPTION:

ft_join joins to string and turn out a trun out a new string 
concatinating s1 and s2
by using malloc, ft_strlcpy, ft_strlcat

PARAMS:

    s1:  'prefix'
    s2:  'suffix'

GUARD:

    if s1 or s2 is NULL return NULL
	if memory allocation fails returns NULL

RETURN:

    pointer to new string
    NULL if Guards are triggered

*/

// --- define ---

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	dim;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	dim = (ft_strlen(s1) + ft_strlen(s2) + 1);
	concat = malloc(dim);
	if (concat == NULL)
		return (NULL);
	ft_strlcpy(concat, s1, dim);
	ft_strlcat(concat, s2, dim);
	return (concat);
}
