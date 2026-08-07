/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_mergesort_efficiency.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:10:47 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:10:50 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
	little efficientcy work arround four smaller stacks
*/

// --- prototype ---

static void	mergesort_three_elements(
				t_stack_machine *machine);

static void	mergesort_four_elements(
				t_stack_machine *machine);

static void	mergesort_five_elements(
				t_stack_machine *machine);

static void	mergesort_six_elements(
				t_stack_machine *machine);

// --- define ---

/*
sorts stacks with 0 < len < 7 more efficient :)
*/

void	mergesort_a_smaller_stack_more_efficient(
			t_stack_machine *machine)
{
	int	len;

	len = machine -> stacks[0].len;
	if (len <= 1)
		return ;
	if (len == 2)
		return (
			(void)(anysort_sort_two(
				machine)));
	if (len == 3)
		return (
			(void)(mergesort_three_elements(
				machine)));
	if (len == 4)
		return (
			(void)(mergesort_four_elements(
				machine)));
	if (len == 5)
		return (
			(void)(mergesort_five_elements(
				machine)));
	if (len == 6)
		return (
			(void)(mergesort_six_elements(
				machine)));
}

// --- utility functions ---

/*
name says everything
*/

static void	mergesort_six_elements(
				t_stack_machine *machine)
{
	int	top_a;
	int	bottom_a;
	int	top_b;

	mergesort_sub_split_stack(machine);
	mergesort_three_elements(machine);
	machine_operation_execute(machine, PA);
	if (!(stack_is_first_and_sec_ascending(&(machine -> stacks[1]))))
		machine_operation_execute(machine, SB);
	top_a = machine -> stacks[1].first -> val;
	bottom_a = machine -> stacks[1].last -> val;
	top_b = machine -> stacks[0].first -> val;
	machine_operation_execute(machine, PB);
	if (top_b > bottom_a)
		machine_operation_execute(machine, RB);
	if ((top_b > top_a) && (top_b < bottom_a))
		machine_operation_execute(machine, SB);
	mergesort_sub_merge_to_a(machine, 3, 3);
}

/*
name says everything
*/

static void	mergesort_five_elements(
				t_stack_machine *machine)
{
	t_stack	*stack_b;

	stack_b = &(machine -> stacks[1]);
	mergesort_sub_split_stack(machine);
	if (!(stack_is_first_and_sec_ascending(stack_b)))
		machine_operation_execute(machine, SB);
	mergesort_three_elements(machine);
	mergesort_sub_merge_to_a(machine, 3, 2);
}

/*
name says everything
*/

static void	mergesort_four_elements(
				t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	mergesort_sub_split_stack(machine);
	if ((!(stack_is_first_and_sec_ascending(stack_a)))
		&& (!(stack_is_first_and_sec_ascending(stack_b))))
		machine_operation_execute(machine, SS);
	else if (!(stack_is_first_and_sec_ascending(stack_a)))
		machine_operation_execute(machine, SA);
	else if (!(stack_is_first_and_sec_ascending(stack_b)))
		machine_operation_execute(machine, SB);
	mergesort_sub_merge_to_a(machine, 2, 2);
}

/*
name says everything
*/

static void	mergesort_three_elements(
				t_stack_machine *machine)
{
	int	top_a;
	int	bottom_a;
	int	top_b;

	mergesort_sub_split_stack(machine);
	anysort_sort_two(machine);
	top_a = machine -> stacks[0].first -> val;
	bottom_a = machine -> stacks[0].last -> val;
	top_b = machine -> stacks[1].first -> val;
	machine_operation_execute(machine, PA);
	if (top_b > bottom_a)
		machine_operation_execute(machine, RA);
	if ((top_b > top_a) && (top_b < bottom_a))
		machine_operation_execute(machine, SA);
	if (top_a > top_b)
		return ;
}
