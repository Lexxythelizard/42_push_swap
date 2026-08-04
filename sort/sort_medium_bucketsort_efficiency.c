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
	little efficientcy work arround four smaller stacks
*/

// --- prototype ---

static void	bucketsort_four_to_five_elements(
				t_stack_machine *machine,
				int **bucket_map);

static void	bucketsort_six_elements(
				t_stack_machine *machine,
				int **bucket_map);

static void	bucketsort_seven_elements(
				t_stack_machine *machine,
				int **bucket_map);

static void	bucketsort_eight_elements(
				t_stack_machine *machine,
				int **bucket_map);

// --- define ---

/*
sorts stacks with 0 < len < 7 more efficient :)
*/

void	bucketsort_a_smaller_stack_more_efficient(
			t_stack_machine *machine,
			int **bucket_map)
{
	int	len;

	len = machine -> stacks[0].len;
	if ((len <= 1) || (len >= 9))
		return ;
	if (len == 2)
		return ((void)(anysort_sort_two(machine)));
	if (len == 3)
		return ((void)(anysort_sort_three(machine)));
	bucketsort_four_to_five_elements(machine, bucket_map);
	bucketsort_six_elements(machine, bucket_map);
	bucketsort_seven_elements(machine, bucket_map);
	bucketsort_eight_elements(machine, bucket_map);
}

// --- utility functions ---

/*
name says everything
*/

static void	bucketsort_four_to_five_elements(
				t_stack_machine *machine,
				int **bucket_map)
{
	int	len;

	len = machine -> stacks[0].len;
	if ((len < 4) || (len > 5))
		return ;
	bucketsort_sub_push_bucket_to_b(machine, bucket_map, 0, 2);
	bucketsort_sub_sub_sort_two_ascending_and_two_descending(machine);
	if (len == 5)
		anysort_sort_three(machine);
	anysort_push_all_elements_to_stack_a(machine);
}

/*
name says everything
*/

static void	bucketsort_six_elements(
				t_stack_machine *machine,
				int **bucket_map)
{
	int	len;

	len = machine -> stacks[0].len;
	if (len != 6)
		return ;
	bucketsort_sub_push_bucket_to_b(machine, bucket_map, 0, 2);
	anysort_sub_rotate_smallest_element_to_top_of_stack_a(machine);
	machine_operation_execute(machine, PB);
	bucketsort_sub_sub_sort_three_elements_descanding(machine);
	anysort_sort_three(machine);
	anysort_push_all_elements_to_stack_a(machine);
}

/*
name says everything
*/

static void	bucketsort_seven_elements(
				t_stack_machine *machine,
				int **bucket_map)
{
	int	len;
	int	i;

	len = machine -> stacks[0].len;
	if (len != 7)
		return ;
	i = (-1);
	while (i++ < 1)
	{
		bucketsort_sub_push_bucket_to_b(machine, bucket_map, i, 2);
		bucketsort_sub_sub_sort_two_elements_descanding(machine);
	}
	anysort_sort_three(machine);
	anysort_push_all_elements_to_stack_a(machine);
}

/*
name says everything
*/

static void	bucketsort_eight_elements(
				t_stack_machine *machine,
				int **bucket_map)
{
	int	len;
	int	i;

	len = machine -> stacks[0].len;
	if (len != 8)
		return ;
	i = (-1);
	while (i++ < 1)
	{
		bucketsort_sub_push_bucket_to_b(machine, bucket_map, i, 2);
		bucketsort_sub_sub_sort_two_elements_descanding(machine);
	}
	bucketsort_sub_push_bucket_to_b(machine, bucket_map, 2, 2);
	bucketsort_sub_sub_sort_two_ascending_and_two_descending(machine);
	anysort_push_all_elements_to_stack_a(machine);
}
