/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 22:17:54 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// --- DOC ---

/*
LIBRARY:

ft_strmapi iterate through a string creating a second one by 
by calling f() to get the character to cast in every itteration

PARAMS:

    s:  string  to iterate throug an map
    f:  pointer to function { unsigned int, ptr to char }

GUARD:

    if Pointer to funktion is NULL or string is NULL return NULL
	if memory allocation fails --- return NULL

RETURN:

    pointer to new string
	NULL if Guards are triggered
*/

// --- define ---

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	i = 0;
	if ((s == NULL) || (f == NULL))
		return (NULL);
	new = malloc(ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = f((unsigned int)(i), s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
