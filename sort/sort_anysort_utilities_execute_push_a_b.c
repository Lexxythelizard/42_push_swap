/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_anysort_utilities_execute_push_a_b.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:08:41 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:08:42 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	test, norminette
*/

// --- define ---

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pa n times; n = length of stack a
*/

int	anysort_push_all_elements_to_stack_a(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			PA,
			machine -> stacks[1].len));
}

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pb n times; n = length of stack b
*/

int	anysort_push_all_elements_to_stack_b(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			PB,
			machine -> stacks[0].len));
}
