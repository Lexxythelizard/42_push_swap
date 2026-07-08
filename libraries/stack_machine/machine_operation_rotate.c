/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_operation_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:19:39 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 20:39:41 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

// --- def ---

void	ra(t_stack_machine *machine)
{
	rotate(&((machine -> stacks)[0]));
}

void	rb(t_stack_machine *machine)
{
	rotate(&((machine -> stacks)[1]));
}

void	rr(t_stack_machine *machine)
{
	ra(machine);
	rb(machine);
}
