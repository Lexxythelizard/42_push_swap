/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_put_hexa_uppercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:56:45 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/03 16:19:58 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	lxy_put_hexa_uppercase(unsigned int u, t_flags *flags)
{
	int	wrt0;
	int	wrt1;

	wrt0 = 0;
	wrt1 = 0;
	if ((flags -> hash) && (u))
		wrt0 = lxy_put_trigger_hashflag_upper();
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_unsigned_int_base(u, HEXDEC_UP);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}

int	lxy_put_long_hexa_uppercase(unsigned long lu, t_flags *flags)
{
	int	wrt0;
	int	wrt1;

	wrt0 = 0;
	wrt1 = 0;
	if ((flags -> hash) && (lu))
		wrt0 = lxy_put_trigger_hashflag_upper();
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_unsigned_long_base(lu, HEXDEC_UP);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}

int	lxy_put_long_long_hexa_uppercase(size_t zu, t_flags *flags)
{
	int	wrt0;
	int	wrt1;

	wrt0 = 0;
	wrt1 = 0;
	if ((flags -> hash) && (zu))
		wrt0 = lxy_put_trigger_hashflag_upper();
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_size_t_base(zu, HEXDEC_UP);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}
