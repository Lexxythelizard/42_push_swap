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

// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
	see comments
*/

static int	rotate_element_to_the_top(
				t_stack_machine *machine,
				int	idx);

// --- define ---

/*
calls insertion sort on a certain range of stack b
meant to sort exactly one bucket:

	--> coplexity:	O((sqrt(n))²) --> O(n) per bucket

	if O(n) was calles sqrt(n) buckets times, we have the 
	requested time / operational complexity
*/

void	bucketsort_sub_sort_bucket_descending_with_min_extraction(
			t_stack_machine *machine,
			int *pre_sorted_bucket,
			int len)
{
	t_stack	*stack_b;
	int		i;
	int		idx_min;

	stack_b = &(machine -> stacks[1]);
	i = len - 1;
	while (i >= 0)
	{
		idx_min = stack_get_idx_of_val(stack_b, pre_sorted_bucket[i]);
		rotate_element_to_the_top(machine, idx_min);
		machine_operation_execute(machine, PA);		// pa
		i--;
	}
	machine_operation_execute_times_n(
		machine,
		PB,
		len);
}

static int	rotate_element_to_the_top(
				t_stack_machine *machine,
				int	idx)
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

/*
void	bucketsort_sub_sort_bucket_descending_with_insertion_sort(
			t_stack_machine *machine,
			int len)
{
	t_stack	*stack_b;
	int		sorted;
	int		pos;

	stack_b = &(machine -> stacks[1]);
	sorted = 1;
	while (sorted < len)
	{
		pos = sorted - 1;
		machine_operation_execute_times_n(machine, RB, pos);
		while (pos >= 0)
		{
			if (stack_is_first_and_sec_ascending(stack_b))
				machine_operation_execute(machine, SB);
			if (pos > 0)
				machine_operation_execute(machine, RRB);
			pos--;
		}
		sorted++;
	}
}
*/
