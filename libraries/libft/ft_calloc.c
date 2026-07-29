/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 22:53:19 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	*ft_calloc(size_t nmemb, size_t size);

// --- DOC ---

/*
guard: checks if the allocated memory will end in an overflow
dimensioning nmemb * size
guard: checks if the memory was available
setting every byte to ZERO

return:

	if guard:	NULL
	else:		pointer to allocated memory

OVERFLOW GUARD:

	IF	| a * b == c | <--> | c / a == b | <--> | c / b == a |
	EX	| 2 * 4 == 8 | <--> | 8 / 2 == 4 | <--> | 8 / 4 == 2 |

	IF	| a * b >  c | <--> | c / a <  b | <--> | c / b <  a |
	EX	| 2 * 5 >  8 | <--> | 8 / 2 <  5 | <--> | 8 / 5 <  2 |

	==> 
	IF	| nmemb * size > SIZE_MAX | <--> | SIZE_MAX / nmemb < size |

NOTE:

	overflows of nmemb or size not covered!
*/

// --- define ---

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*arr;
	unsigned char	*str;
	size_t			dim;
	size_t			i;

	if ((nmemb) && (((size_t)(SIZE_MAX / nmemb)) < size))
		return (NULL);
	dim = (nmemb * size);
	if (!(dim))
		dim = 1;
	i = 0;
	arr = malloc(dim);
	if (arr == NULL)
		return (NULL);
	str = arr;
	while (i < dim)
	{
		str[i] = 0;
		i++;
	}
	return (arr);
}
