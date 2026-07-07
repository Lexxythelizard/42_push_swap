/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_scan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:39:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/02 15:25:47 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../ft_printf.h"
#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	is_flag(unsigned char c)
{
	return ((c == 35) || (c == 32) || (c == 43));
}

int	is_percent(unsigned char c)
{
	return (c == 37);
}

int	is_equal(const char *s1, const char *s2, int size)
{
	int	i;

	i = 0;
	while ((i < size) && (s1[i]) && (s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (i == size);
}
