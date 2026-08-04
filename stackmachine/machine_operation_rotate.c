/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./machine.h"

// --- DOC --

/*
    this file contains the Operations {ra, rb, rr}

        both are taking a pointer to an in stance of t_stack_machine 
        and calling the rotate on its members stack a or stack b

        functions writing ra / rb / rr to standart output if success

        return:

            no operation possible   :   0
            success                 :   1
            error                   :   -1
*/

// --- define ---

/*
calls rotate to pop the last element of stack a 
and add it on top of it
    --> rotate stack a
*/

int	ra(t_stack_machine *machine)
{
	t_stack	*stack_a;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	return (rotate(stack_a));
}

/*
calls rotate to pop the last element of stack b 
and add it on top of it
    --> rotate stack b
*/

int	rb(t_stack_machine *machine)
{
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_b = &(machine -> stacks[1]);
	return (rotate(stack_b));
}

/*
calls rotate to pop the last element of stack a and stack b
and add it on top of stack a and stack b
    --> rotate stack a and stack b
*/

int	rr(t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	if ((stack_a -> len == 0) || (stack_b -> len == 0))
		return (0);
	rotate(stack_a);
	rotate(stack_b);
	return (1);
}
