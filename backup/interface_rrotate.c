/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:21:06 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 15:52:24 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- def ---

void	rra(t_interface *c)
{
	rr_(&((c -> stacks)[0]));
}

void	rrb(t_interface	*c)
{
	rr_(&((c -> stacks)[1]));
}

void	rrr(t_interface *c)
{
	rra(c);
	rrb(c);
}
