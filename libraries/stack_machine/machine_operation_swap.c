/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_operation_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:16:29 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 20:40:00 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

// --- def ---

void	sa(t_stack_machine *machine)
{
	swap(&((machine -> stacks)[0]));
}

void	sb(t_stack_machine *machine)
{
	swap(&((machine -> stacks)[1]));
}

void	ss(t_stack_machine *machine)
{
	sa(machine);
	sb(machine);
}
