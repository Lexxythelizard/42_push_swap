/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_operation_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:06:05 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:06:07 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./machine.h"

// --- DOC --

/*
    this file contains the Operations {sa, sb, ss}

        both are taking a pointer to an in stance of t_stack_machine 
        and calling the swap on its members stack a or stack b

        functions writing sa / sb / ss to standart output if success

        return:

            no operation possible   :   0
            success                 :   1
            error                   :   -1
*/

// --- define ---

/*
calls swap to pop first two elements of stack a 
and add them in reversed order
	--> swap stack a
*/

int	sa(t_stack_machine *machine)
{
	t_stack	*stack_a;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	return (swap(stack_a));
}

/*
calls swap to pop first two elements of stack b 
and add them in reversed order
	--> swap stack b
*/

int	sb(t_stack_machine *machine)
{
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_b = &(machine -> stacks[1]);
	return (swap(stack_b));
}

/*
calls swap to pop first two elements of stack a and stack b
and add them in reversed order
	--> swap stack a and stack b
*/

int	ss(t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	if ((stack_a -> len == 0) || (stack_b -> len == 0))
		return (0);
	swap(stack_a);
	swap(stack_b);
	return (1);
}
