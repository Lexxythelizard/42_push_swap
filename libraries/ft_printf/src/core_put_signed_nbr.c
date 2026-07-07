/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_put_signed_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:57:06 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/30 18:19:02 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- Prototype ---

static int	lxy_put_prefix(t_flags *flags, int neg);

// --- define ---

int	lxy_put_signed_int(int i, t_flags *flags)
{
	int				wrt0;
	int				wrt1;
	unsigned int	pass;

	if (i == INT_MIN)
		pass = ((unsigned int)((i + 1) * (-1))) + 1;
	else if (i < 0)
		pass = ((unsigned int)(i * (-1)));
	else
		pass = (unsigned int)(i);
	wrt0 = lxy_put_prefix(flags, (i < 0));
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_unsigned_int_base(pass, DECDEC);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}

int	lxy_put_signed_long(long l, t_flags *flags)
{
	int				wrt0;
	int				wrt1;
	unsigned long	pass;

	if (l == LONG_MIN)
		pass = (((unsigned long)(LONG_MAX)) + 1);
	else if (l < 0)
		pass = ((unsigned long)(l * (-1)));
	else
		pass = (unsigned long)(l);
	wrt0 = lxy_put_prefix(flags, (l < 0));
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_unsigned_int_base(pass, DECDEC);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}

int	lxy_put_ssize_t(ssize_t z, t_flags *flags)
{
	int				wrt0;
	int				wrt1;
	unsigned long	pass;

	if (z == SSZ_MIN)
		pass = (((size_t)(SSZ_MAX)) + 1);
	else if (z < 0)
		pass = ((size_t)(z * (-1)));
	else
		pass = (size_t)(z);
	wrt0 = lxy_put_prefix(flags, (z < 0));
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_unsigned_int_base(pass, DECDEC);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}

int	lxy_put_decimal(int dec, t_flags *flags)
{
	int				wrt0;
	int				wrt1;
	unsigned int	pass;

	if (dec == INT_MIN)
		pass = ((unsigned int)((dec + 1) * (-1))) + 1;
	else if (dec < 0)
		pass = ((unsigned int)(dec * (-1)));
	else
		pass = (unsigned int)(dec);
	wrt0 = lxy_put_prefix(flags, (dec < 0));
	if (wrt0 < 0)
		return (-1);
	wrt1 = lxy_put_unsigned_int_base(pass, DECDEC);
	if (wrt1 < 0)
		return (-1);
	return (wrt0 + wrt1);
}

static int	lxy_put_prefix(t_flags *flags, int neg)
{
	if (neg)
		return (lxy_put_char(45));
	if (flags -> plus)
		return (lxy_put_char(43));
	if (flags -> wsp)
		return (lxy_put_white_space(1));
	return (0);
}
