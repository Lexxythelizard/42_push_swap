/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_put_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:55:08 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/03 16:47:34 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	lxy_put_char(char c)
{
	return ((int)(write(STDOUT, &c, 1)));
}

int	lxy_put_str(const char *s)
{
	int	len;

	if (!s)
		return ((int)(write(STDOUT, NSTR, lxy_strlen(NSTR))));
	len = lxy_strlen(s);
	if (len < 0)
		return (-1);
	return ((int)(write(STDOUT, s, len)));
}
