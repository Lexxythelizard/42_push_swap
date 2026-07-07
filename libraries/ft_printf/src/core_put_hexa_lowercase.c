/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_put_hexa_lowercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:56:26 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/03 16:49:00 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	lxy_put_hexa_lowercase(unsigned int u, t_flags *flags)
{
	int	wrt0;
	int	wrt1;

	wrt0 = 0;
	wrt1 = 0;
	if ((flags -> hash) && (u))
		wrt0 = lxy_put_trigger_hashflag();
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_unsigned_int_base(u, HEXDEC_LO);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}

int	lxy_put_long_hexa_lowercase(unsigned long lu, t_flags *flags)
{
	int	wrt0;
	int	wrt1;

	wrt0 = 0;
	wrt1 = 0;
	if ((flags -> hash) && (lu))
		wrt0 = lxy_put_trigger_hashflag();
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_unsigned_long_base(lu, HEXDEC_LO);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}

int	lxy_put_long_long_hexa_lowercase(size_t zu, t_flags *flags)
{
	int	wrt0;
	int	wrt1;

	wrt0 = 0;
	wrt1 = 0;
	if ((flags -> hash) && (zu))
		wrt0 = lxy_put_trigger_hashflag();
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_size_t_base(zu, HEXDEC_LO);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}

int	lxy_put_pointer(void *p, t_flags *flags)
{
	int	wrt0;
	int	wrt1;

	wrt0 = 0;
	wrt1 = 0;
	if (!p)
		return (lxy_put_str(NIL));
	if (flags -> plus)
		wrt0 = lxy_put_char(43);
	else if (flags -> wsp)
		wrt0 = lxy_put_white_space(1);
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_trigger_hashflag();
	if (wrt1 < 0)
		return (-1);
	wrt0 += wrt1;
	wrt1 = 0;
	wrt1 = lxy_put_unsigned_long_base((unsigned long)(p), HEXDEC_LO);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}
