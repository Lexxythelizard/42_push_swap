/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:18:26 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 15:44:24 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- def ---

void	pa(t_interface *c)
{
	p(&((c -> stacks)[0]), &((c -> stacks)[1]));
}

void	pb(t_interface *c)
{
	p((&(c -> stacks)[1]), &((c -> stacks)[0]));
}
