/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_utils_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:39:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/02 15:44:32 by lenivorb         ###   ########.fr       */
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

/*
%: 37,	X: 88,	c: 99,	d: 100,	i: 105,	l: 108,
p: 112,	s: 115,	u: 117,	x: 120,	z: 122
*/

int	get_specifier_lenght(const char *s)
{
	if (is_specifier_single(s[0]))
		return (1);
	if (is_specifier_prefix(s[0]))
	{
		return (2 * ((is_equal(s, "ld", 2)) || (is_equal(s, "lu", 2))
				|| (is_equal(s, "lx", 2)) || (is_equal(s, "lX", 2))
				|| (is_equal(s, "zd", 2)) || (is_equal(s, "zu", 2))
				|| (is_equal(s, "zx", 2)) || (is_equal(s, "zX", 2))));
	}
	return (0);
}

int	is_specifier(const char *s)
{
	if (is_specifier_single(s[0]))
		return (1);
	if (is_specifier_prefix(s[0]))
	{
		return ((is_equal(s, "ld", 2)) || (is_equal(s, "lu", 2))
			|| (is_equal(s, "lx", 2)) || (is_equal(s, "lX", 2))
			|| (is_equal(s, "zd", 2)) || (is_equal(s, "zu", 2))
			|| (is_equal(s, "zx", 2)) || (is_equal(s, "zX", 2)));
	}
	return (0);
}

int	is_specifier_single(unsigned char c)
{
	return ((c == 37) || (c == 88) || (c == 99)
		|| (c == 100) || (c == 105) || (c == 112)
		|| (c == 115) || (c == 117) || (c == 120));
}

int	is_specifier_prefix(unsigned char c)
{
	return ((c == 108) || (c == 120) || (c == 122));
}
