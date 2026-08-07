/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_mergesort_merge_to_side_x.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:10:58 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:10:59 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
	this file contains the functions:

		- mergesort_sub_merge_to_a()
		- mergesort_sub_merge_to_b()

	those functions are 'dumb' algotithm parts... they need 
	the exact number of elements which have to get merged in
	stack a and stack b

	rotate the destintion stack, so that the dest (merged chunk) 
	is on the bottom of destination stack

*/

// --- prototype ---

static int	top_a_smaller_than_top_b(t_stack_machine *machine);
static int	top_b_smaller_than_top_a(t_stack_machine *machine);

// --- define ---

void	mergesort_sub_merge_to_a(
			t_stack_machine *machine,
			int to_merge_in_a,
			int to_merge_in_b)
{
	while (to_merge_in_b || to_merge_in_a)
	{
		if ((to_merge_in_b) && (top_b_smaller_than_top_a(machine)))
		{
			machine_operation_execute(machine, PA);
			machine_operation_execute(machine, RA);
			to_merge_in_b--;
		}
		else if (to_merge_in_a)
		{
			machine_operation_execute(machine, RA);
			to_merge_in_a--;
		}
		else
		{
			machine_operation_execute(machine, PA);
			machine_operation_execute(machine, RA);
			to_merge_in_b--;
		}
	}
}

void	mergesort_sub_merge_to_b(
			t_stack_machine *machine,
			int to_merge_in_a,
			int to_merge_in_b)
{
	while (to_merge_in_a || to_merge_in_b)
	{
		if ((to_merge_in_a) && (top_a_smaller_than_top_b(machine)))
		{
			machine_operation_execute(machine, PB);
			machine_operation_execute(machine, RB);
			to_merge_in_a--;
		}
		else if (to_merge_in_b)
		{
			machine_operation_execute(machine, RB);
			to_merge_in_b--;
		}
		else
		{
			machine_operation_execute(machine, PB);
			machine_operation_execute(machine, RB);
			to_merge_in_a--;
		}
	}
}

// --- utility functions ---

/*
takes a pointer to instance of t_stack_machine
return 1 / 0 : statement true / not true or empty
*/

static int	top_a_smaller_than_top_b(t_stack_machine *machine)
{
	t_element	*top_a;
	t_element	*top_b;

	top_a = machine -> stacks[0].first;
	top_b = machine -> stacks[1].first;
	if ((!top_a) || (!top_b))
		return (0);
	return (top_a -> val < top_b -> val);
}

/*
takes a pointer to instance of t_stack_machine
return 1 / 0 : statement true / not true or empty
*/

static int	top_b_smaller_than_top_a(t_stack_machine *machine)
{
	t_element	*top_a;
	t_element	*top_b;

	top_a = machine -> stacks[0].first;
	top_b = machine -> stacks[1].first;
	if ((!top_a) || (!top_b))
		return (0);
	return (top_b -> val < top_a -> val);
}
