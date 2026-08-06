/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_min_extraction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 2026/08/05 14:55:36 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	test, norminette
*/

// --- prototype ---

static int	push_the_three_smallest_elements_to_stack_b(
				t_stack_machine *machine);

static int	rotate_next_smallest_element_to_top(
				t_stack_machine *machine,
				int *pre_sorted);

// --- define ---

/*
while elements in stack a:
	find min and rotate to top
	push element on top to stack b
while elements in stack b:
	push to stack a
*/

int	min_extraction_sort_sub_sort_huge_stack_more_efficiently(
		t_stack_machine *machine)
{
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	if (stack_a -> len <= 1)
		return (stack_a -> len);
	while (stack_a -> len > 33)
	{
		push_the_three_smallest_elements_to_stack_b(machine);
		bucketsort_sub_sub_sort_three_elements_descanding(machine);
	}
	if (stack_a -> len == 2)
		anysort_sort_two(machine);
	anysort_push_all_elements_to_stack_a(machine);
	return (1);
}

// --- utilities ---

static int	push_the_three_smallest_elements_to_stack_b(
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
	while (i < 3)
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
