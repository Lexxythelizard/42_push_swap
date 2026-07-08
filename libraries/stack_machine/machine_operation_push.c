/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_operation_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:18:26 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 20:39:08 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

// --- def ---

void	pa(t_stack_machine *machine)
{
	push(&((machine -> stacks)[0]), &((machine -> stacks)[1]));
}

void	pb(t_stack_machine *machine)
{
	push((&(machine -> stacks)[1]), &((machine -> stacks)[0]));
}
