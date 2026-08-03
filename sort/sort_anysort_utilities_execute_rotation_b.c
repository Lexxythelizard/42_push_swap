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

#include "./sort.h"

// --- DOC ---

/*
TODO:	test, norminette
*/

// --- define ---

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pb n times; n = length of stack b
*/

int	push_all_elements_to_stack_b(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			PB,
			machine -> stacks[0].len));
}

int	anysort_sub_rotate_largest_element_to_top_of_stack_b(
		t_stack_machine *machine)
{
	int		idx_min;
	t_stack	*stack_b;

	stack_b = &(machine -> stacks[1]);
	idx_min = stack_get_idx_min_val(stack_b);
	if (stack_b -> len == 1)
		return (0);
	if (idx_min <= (stack_b -> len / 2))
		return (
			machine_operation_execute_times_n(
				machine,
				RB,
				idx_min));
	return (
		machine_operation_execute_times_n(
			machine,
			RRB,
			(stack_b -> len - idx_min)));
}

int	anysort_sub_rotate_element_to_the_top_of_stack_b_by_idx(
		t_stack_machine *machine,
		int idx)
{
	t_stack	*stack_b;

	stack_b = &(machine -> stacks[1]);
	if (idx <= stack_b -> len / 2)
		return (
			machine_operation_execute_times_n(
				machine,
				RB,
				idx));
	return (
		machine_operation_execute_times_n(
			machine,
			RRB,
			(stack_b -> len - idx)));
}
