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

static int	push_element_on_top_to_stack_b(t_stack_machine *machine);
static int	more_than_two_elements_in_stack_a(t_stack_machine *machine);

// --- define ---

/*
while elements in stack a:
	find min and rotate to top
	push element on top to stack b
while elements in stack b:
	push to stack a
*/

int	min_extraction_adaption_sort(t_stack_machine *machine)
{
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	if (stack_a -> len <= 1)
		return (stack_a -> len);
	if (stack_a -> len == 3)
		return (anysort_sort_three(machine));
	min_extraction_sort_sub_sort_huge_stack_more_efficiently(machine);
	while (more_than_two_elements_in_stack_a(machine))
	{
		anysort_sub_rotate_smallest_element_to_top_of_stack_a(machine);
		push_element_on_top_to_stack_b(machine);
	}
	if (stack_a -> len == 2)
		anysort_sort_two(machine);
	anysort_push_all_elements_to_stack_a(machine);
	return (1);
}

// --- utilities ---

/*
just calls machine_operation_execute() --> pb
*/

static int	push_element_on_top_to_stack_b(t_stack_machine *machine)
{
	return (machine_operation_execute(machine, PB));
}

/*
returns 1 / 0 :	elements in stack a / no elements in stack a
*/

static int	more_than_two_elements_in_stack_a(t_stack_machine *machine)
{
	return (machine -> stacks[0].len > 0);
}
