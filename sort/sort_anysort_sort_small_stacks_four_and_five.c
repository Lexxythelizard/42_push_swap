/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_anysort_sort_small_stacks_four_and_f          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:07:53 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:07:55 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	test, norminette
*/

// --- proto ---

static int	push_the_two_smallest_elements_to_stack_b(
				t_stack_machine *machine);

static int	rotate_next_smallest_element_to_top(
				t_stack_machine *machine,
				int *pre_sorted);

// --- define ---

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pa n times; n = length of stack a
*/

int	anysort_sort_four(t_stack_machine *machine)
{
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	if (stack_a -> len <= 3)
		return (-1);
	anysort_sub_rotate_smallest_element_to_top_of_stack_a(machine);
	machine_operation_execute(machine, PB);
	anysort_sort_three(machine);
	machine_operation_execute(machine, PA);
	return (0);
}

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pb n times; n = length of stack b
*/

int	anysort_sort_five(t_stack_machine *machine)
{
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	if (stack_a -> len <= 4)
		return (-1);
	push_the_two_smallest_elements_to_stack_b(machine);
	anysort_sort_three(machine);
	bucketsort_sub_sub_sort_two_elements_descanding(machine);
	machine_operation_execute(machine, PA);
	machine_operation_execute(machine, PA);
	return (0);
}

static int	push_the_two_smallest_elements_to_stack_b(
				t_stack_machine *machine)
{
	int	*pre_sorted;

	if (!machine)
		return (-1);
	if (machine -> stacks[0].len < 3)
		return (-1);
	pre_sorted = arr_int_get_presorted(machine);
	if (!pre_sorted)
		return (-1);
	rotate_next_smallest_element_to_top(machine, pre_sorted);
	machine_operation_execute(machine, PB);
	rotate_next_smallest_element_to_top(machine, pre_sorted);
	machine_operation_execute(machine, PB);
	free(pre_sorted);
	return (1);
}

static int	rotate_next_smallest_element_to_top(
				t_stack_machine *machine,
				int *pre_sorted)
{
	t_stack	*stack_a;
	int		steps_ra;
	int		steps_rra;
	int		i;
	int		idx;

	idx = 0;
	i = 0;
	stack_a = &(machine -> stacks[0]);
	steps_ra = stack_a -> len;
	steps_rra = stack_a -> len;
	while (i < 2)
	{
		idx = stack_get_idx_of_val(stack_a, pre_sorted[i]);
		if (idx >= 0)
		{
			steps_ra = int_min_of_two(steps_ra, idx);
			steps_rra = int_min_of_two(steps_rra, ((stack_a -> len) - idx));
		}
		i++;
	}
	if (steps_ra < steps_rra)
		return (machine_operation_execute_times_n(machine, RA, steps_ra));
	return (machine_operation_execute_times_n(machine, RRA, steps_rra));
}
