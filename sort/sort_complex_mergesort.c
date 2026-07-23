// --- icludes ---

#include <limits.h>
#include "./sort.h"

// --- DOC ---

/*
	This file contains the functions which are orchestering the merge sort:

		- splits the stack
		- sort pairs
		- merge sort to size 2 --> 4 --> 8 --> 16 --> 32 --> ... --> INT_MAX
*/

// --- prototype ---

static int	get_number_of_rounds(t_stack_machine *machine, int chunk_size);
static int	get_to_merge(int unmerged, int chunk_size);

// --- define ---

/*
performes the merge sort
*/

void	merge_sort(t_stack_machine *machine)
{
	int	all_elements;
	int	current_merge_size;

	all_elements = machine -> stacks[0].len;
	current_merge_size = 4;

	split_stack(machine);
	sort_pairs(machine);

	while (current_merge_size < all_elements)
	{
		merge_to(machine, current_merge_size);
		current_merge_size *= 2;
	}
	merge_to(machine, current_merge_size);
}

// --- merge functions ---

void	merge_to(
			t_stack_machine *machine,
			int merge_to_size)
{
	int	i;
	int	chunk_size;
	int	rounds;
	int	unmerged_a;
	int	unmerged_b;

	i = 0;
	chunk_size = merge_to_size / 2;
	rounds = get_number_of_rounds(machine, chunk_size);
	unmerged_a = machine -> stacks[0].len;
	unmerged_b = machine -> stacks[1].len;
	while (i++ < rounds)
	{
		if (i % 2)
		{
			merge_to_a(
				machine,
				get_to_merge(unmerged_a, chunk_size),
				get_to_merge(unmerged_b, chunk_size));
		}
		else
		{
			merge_to_b(
				machine,
				get_to_merge(unmerged_a, chunk_size),
				get_to_merge(unmerged_b, chunk_size));
		}
		unmerged_a -= int_min_of_two(unmerged_a, chunk_size);
		unmerged_b -= int_min_of_two(unmerged_b, chunk_size);
	}
	return ;
}

// --- utilities ---

static int	get_number_of_rounds(t_stack_machine *machine, int chunk_size)
{
	int	len_a;
	int	len_b;

	len_a = machine -> stacks[0].len;
	len_b = machine -> stacks[1].len;
	return (
		int_max_of_two(
			((len_a / chunk_size) + (len_a % chunk_size)),
			((len_b / chunk_size) + (len_b % chunk_size))));
}

static int	get_to_merge(int unmerged, int chunk_size)
{
	return (int_min_of_two(unmerged, chunk_size));
}
