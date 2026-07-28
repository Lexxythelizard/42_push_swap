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

// --- define ---

/*
calls insertion sort on a certain range of stack b
meant to sort exactly one bucket:

	--> coplexity:	O((sqrt(n))²) --> O(n) per bucket

	if O(n) was calles sqrt(n) buckets times, we have the 
	requested time / operational complexity
*/

void	bucket_insertion_sort_descending(
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
