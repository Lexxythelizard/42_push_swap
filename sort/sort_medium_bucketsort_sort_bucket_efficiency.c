/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_bucketsort_sort_bucket_effici          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 2026/08/06 17:28:36 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
	little efficientcy work arround four smaller stacks
*/

// --- define ---

/*
sorts buckets with two elements more efficient :)
*/

void	bucketsort_sub_sub_sort_two_ascending_and_two_descending(
			t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		a_ascending;
	int		b_ascending;

	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	a_ascending = stack_is_first_and_sec_ascending(stack_a);
	b_ascending = stack_is_first_and_sec_ascending(stack_b);
	if (!a_ascending && b_ascending)
		return ((void)(machine_operation_execute(machine, SS)));
	if (!a_ascending)
		return ((void)(machine_operation_execute(machine, SA)));
	if (b_ascending)
		return ((void)(machine_operation_execute(machine, SB)));
}

/*
sorts buckets with two elements more efficient :)
*/

void	bucketsort_sub_sub_sort_two_elements_descanding(
			t_stack_machine *machine)
{
	t_stack	*stack_b;

	stack_b = &(machine -> stacks[1]);
	if (stack_is_first_and_sec_ascending(stack_b))
		machine_operation_execute(machine, SB);
}

/*
sorts buckets with two elements more efficient :)
*/

void	bucketsort_sub_sub_sort_two_elements_ascanding(
			t_stack_machine *machine)
{
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	if (stack_is_first_and_sec_ascending(stack_a))
		return ;
	machine_operation_execute(machine, SA);
}

/*
sorts buckets with three elements more efficient :)
*/

void	bucketsort_sub_sub_sort_three_elements_descanding(
			t_stack_machine *machine)
{
	int	first;
	int	secon;
	int	third;

	first = machine -> stacks[1].first -> val;
	secon = machine -> stacks[1].first -> next -> val;
	third = machine -> stacks[1].first -> next -> next -> val;
	if ((first > secon) && (secon > third))
		return ;
	if ((first > secon) && (secon < third) && (third < first))
		return (anysort_sub_swap_second_and_third_b(
				machine));
	if ((first < secon) && (secon > third) && (third < first))
		return ((void)(machine_operation_execute(
				machine, SB)));
	if ((first > secon) && (secon < third) && (third > first))
		return (anysort_sub_swap_second_and_third_then_second_and_first_b(
				machine));
	if ((first < secon) && (secon > third) && (third > first))
		return (anysort_sub_swap_second_and_first_then_second_and_third_b(
				machine));
	if ((first < secon) && (secon < third))
		return (anysort_sub_swap_first_and_third_b(
				machine));
}

/*
sorts buckets with three elements more efficient :)
*/

void	bucketsort_sub_sub_sort_three_elements_ascanding(
			t_stack_machine *machine)
{
	int	first;
	int	secon;
	int	third;

	first = machine -> stacks[0].first -> val;
	secon = machine -> stacks[0].first -> next -> val;
	third = machine -> stacks[0].first -> next -> next -> val;
	if ((first < secon) && (secon < third))
		return ;
	if ((first < secon) && (secon > third) && (third > first))
		return (anysort_sub_swap_second_and_third_a(
				machine));
	if ((first > secon) && (secon < third) && (third > first))
		return ((void)(machine_operation_execute(
				machine, SB)));
	if ((first < secon) && (secon > third) && (third < first))
		return (anysort_sub_swap_second_and_third_then_second_and_first_a(
				machine));
	if ((first > secon) && (secon < third) && (third < first))
		return (anysort_sub_swap_second_and_first_then_second_and_third_a(
				machine));
	if ((first > secon) && (secon > third))
		return (anysort_sub_swap_first_and_third_a(
				machine));
}
