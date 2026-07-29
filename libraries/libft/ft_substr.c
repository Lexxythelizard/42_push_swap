/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 21:28:34 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char	*ft_substr(char const *s, unsigned int start, size_t len);

// --- DOC ---

/*
DESCRIPTION:

void ft_substr(char const *s, unsigned int start, size_t len)
Allocates memory using malloc and returns a substring from the string ’s’.
The substring starts at index ’start’ and has a maximum length of ’len

PARAMS:

    s	  : string to read from.
    start : index of starting point
	len	  : max len of substr

GUARD:

	if s is NULL return NULL
    if malloc fails return NULL;
	if strlen new > size --> strlen new = size

RETURN:

    pointer to new allocated substr;
	if start > strlen return '\0'

*/

// --- define ---

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_new;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= ((size_t)(start)))
	{
		sub = malloc(1);
		if (sub == NULL)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	len_new = ft_strlen(&(s[start]));
	if (len_new > len)
		len_new = len;
	sub = malloc(len_new + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, &s[start], (len + 1));
	return (sub);
}
