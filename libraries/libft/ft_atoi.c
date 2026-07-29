/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/09 15:23:18 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

int	ft_atoi(const char *nptr);

// --- define ---

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		out;
	size_t	i;

	i = 0;
	out = 0;
	sign = 1;
	while (nptr[i]
		&& (((nptr[i] >= 9) && (nptr[i] <= 13)) || (nptr[i] == 32)))
		i++;
	if (nptr[i] == 45)
		sign = (-1);
	if ((nptr[i] == 45) || ((nptr[i] == 43)))
		i++;
	while ((nptr[i]) && (nptr[i] >= 48) && (nptr[i] <= 57))
	{
		out = (out * 10) + ((((int)(nptr[i])) - 48) * sign);
		i++;
	}
	return (out);
}
