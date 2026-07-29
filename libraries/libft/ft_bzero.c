/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/09 22:53:00 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	ft_bzero(void *s, size_t n);

// --- DOC ---

/*
*ft_bzero() iterate forward n times in steps of one byte 
and setting the memory to 0.

Usefull to clear sensitiv data.
RETURN:

    ---
*/

// --- define ---

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)(s))[i] = 0;
		i++;
	}
}
