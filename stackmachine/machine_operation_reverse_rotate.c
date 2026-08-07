/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_operation_reverse_rotate.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:05:45 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:05:48 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./machine.h"

// --- DOC --

/*
    this file contains the Operations {rra, rrb, rrr}

        both are taking a pointer to an in stance of t_stack_machine 
        and calling the reverse rotate on its members stack a or stack b

        functions writing rra / rrb / rrr to standart output if success

        return:

            no operation possible   :   0
            success                 :   1
            error                   :   -1
*/

// --- define ---

/*
calls reverse_rotate to pop the first element of stack a 
and add it to the end of it
    --> reverse rotate stack a
*/

int	rra(t_stack_machine *machine)
{
	t_stack	*stack_a;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	return (reverse_rotate(stack_a));
}

/*
calls reverse_rotate to pop the first element of stack b 
and add it to the end of it
    --> reverse rotate stack b
*/

int	rrb(t_stack_machine	*machine)
{
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_b = &(machine -> stacks[1]);
	return (reverse_rotate(stack_b));
}

/*
calls reverse_rotate to pop the first element of stack a and stack b
and add it to the end of stack a and stack b
    --> reverse rotate stack a and stack b
*/

int	rrr(t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	if ((stack_a -> len == 0) || (stack_b -> len == 0))
		return (0);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (1);
}
