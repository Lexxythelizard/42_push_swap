/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_operation_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:05:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:05:36 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./machine.h"

// --- DOC --

/*
	this file contains the Operations {pa, pb}

		both are taking a pointer to an in stance of t_stack_machine 
		and calling the push on its members stack a and stack b

		functions writing pa / pb to standart output if success

		return:

			no operation possible	:	0
			success					:	1
			error					:	-1
*/

// --- define ---

/*
calls push to pop first element of stack b and put in on top of stack a
*/

int	pa(t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_a = &((machine -> stacks)[0]);
	stack_b = &((machine -> stacks)[1]);
	return (push(stack_b, stack_a));
}

/*
calls push to pop first element of stack a and put in on top of stack b
*/

int	pb(t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_a = &((machine -> stacks)[0]);
	stack_b = &((machine -> stacks)[1]);
	return (push(stack_a, stack_b));
}
