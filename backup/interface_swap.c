/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:16:29 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 15:53:05 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- def ---

void	sa(t_interface *c)
{
	s(&((c -> stacks)[0]));
}

void	sb(t_interface *c)
{
	s(&((c -> stacks)[1]));
}

void	ss(t_interface *c)
{
	sa(c);
	sb(c);
}
