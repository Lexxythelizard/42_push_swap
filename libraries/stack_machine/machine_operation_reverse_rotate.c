/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_operation_reverse_rotate.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:21:06 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 20:39:27 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

// --- def ---

void	rra(t_stack_machine *machine)
{
	reverse_rotate(&((machine -> stacks)[0]));
}

void	rrb(t_stack_machine	*machine)
{
	reverse_rotate(&((machine -> stacks)[1]));
}

void	rrr(t_stack_machine *machine)
{
	rra(machine);
	rrb(machine);
}
