/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_put_abstraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:55:47 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/03 16:18:47 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	lxy_put_percent_sign(void)
{
	return (lxy_put_char(37));
}

int	lxy_put_trigger_hashflag(void)
{
	return (lxy_put_str("0x"));
}

int	lxy_put_trigger_hashflag_upper(void)
{
	return (lxy_put_str("0X"));
}

int	lxy_put_white_space(int n)
{
	int	written;

	written = n;
	while (n--)
	{
		if (lxy_put_char(32) == (-1))
			return (-1);
	}
	return (written);
}
