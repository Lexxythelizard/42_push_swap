/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_put_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:57:29 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/30 17:47:59 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	lxy_put_unsigned_int(unsigned int u, t_flags *flags)
{
	(void)(flags);
	return (lxy_put_unsigned_int_base(u, DECDEC));
}

int	lxy_put_unsigned_long(unsigned long lu, t_flags *flags)
{
	(void)(flags);
	return (lxy_put_unsigned_long_base(lu, DECDEC));
}

int	lxy_put_size_t(size_t zu, t_flags *flags)
{
	(void)(flags);
	return (lxy_put_size_t_base(zu, DECDEC));
}

int	lxy_put_undecimal(unsigned int udec, t_flags *flags)
{
	(void)(flags);
	return (lxy_put_unsigned_int_base(udec, DECDEC));
}
