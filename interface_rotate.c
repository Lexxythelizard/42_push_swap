/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:19:39 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/07 15:28:42 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- def ---

void	ra(t_interface *c)
{
	r((c -> stacks)[0]);
}

void	rb(t_interface *c)
{
	r((c -> stacks)[1]);
}

void	rr(t_interface *c)
{
	ra(c);
	rb(c);
}
