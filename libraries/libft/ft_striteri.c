/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 20:57:05 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// --- DOC ---

/*
ft_striteri iterate through a string and changing its members 
by calling f() on them

PARAMS:

	s:	string  to iterate
	f:	pointer to function { unsigned int, ptr to char }

GUARD:

	if Pointer to funktion is NULL or string is NULL return (void)

RETURN:

	---
*/

// --- define ---

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if ((s == NULL) || (f == NULL))
		return ;
	while (s[i])
	{
		f(i, &(s[i]));
		i++;
	}
}
