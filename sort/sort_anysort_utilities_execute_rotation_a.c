/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   filename.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: intranam <intranam@student.42berlin.d	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam		  #+#	#+#			 */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam		 ###   ########.fr	   */
/*																			*/
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

int	push_all_elements_to_stack_a(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			PA,
			machine -> stacks[1].len));
}

/*
get idx of min value
decide rotate / reverse rotate
rotate smallest element on top
*/

int	anysort_sub_rotate_smallest_element_to_top_of_stack_a(
		t_stack_machine *machine)
{
	int		idx_min;
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	idx_min = stack_get_idx_min_val(stack_a);
	if (stack_a -> len == 1)
		return (0);
	if (idx_min <= (stack_a -> len / 2))
		return (
			machine_operation_execute_times_n(
				machine,
				RA,
				idx_min));
	return (
		machine_operation_execute_times_n(
			machine,
			RRA,
			(stack_a -> len - idx_min)));
}

int	anysort_sub_rotate_element_to_the_top_of_stack_a_by_idx(
		t_stack_machine *machine,
		int idx)
{
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	if (idx <= stack_a -> len / 2)
		return (
			machine_operation_execute_times_n(
				machine,
				RA,
				idx));
	return (
		machine_operation_execute_times_n(
			machine,
			RRA,
			(stack_a -> len - idx)));
}
