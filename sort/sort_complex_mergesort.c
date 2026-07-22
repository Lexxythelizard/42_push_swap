// --- icludes ---

#include <limits.h>
#include "./sort.h"

// --- DOC ---

/*
TODO:	reimplement from scratch
*/

// --- prototype ---

void	merge_sort(
			t_stack_machine *machine);

void	merge_level_n(
			t_stack_machine *machine,
			int merge_level);

void	merge(
		t_stack_machine *machine);

// --- define ---

void	merge_sort(t_stack_machine *machine)
{
	int	merge_steps;

	split_stack(machine);
	sort_pairs(machine);
	return ;
}

// --- merge functions ---

/*
merges one level like merge size 4, then double merge size...
consider merging this two functions
*/

void	merge_level_n(
			t_stack_machine *machine,
			int merge_level)
{
	int	unmerged_a;
	int	unmerged_b;

	unmerged_a = machine -> stacks[0].len;
	unmerged_b = machine -> stacks[1].len;

	// call merge in a loop

	while ((unmerged_a) || (unmerged_b))
	{
		merge(machine, merge_level, &unmerged_a, &unmerged_b);
	}
	// increment merge level

	return ;
}

/*
coordinates the two merge functions like a pendulum
*/

void	merge(
			t_stack_machine *machine,
			int merge_level,
			int *unmerged_a,
			int *unmerged_b)
{
	int	merge_size;
	int	to_merge_in_a;
	int	to_merge_in_b;

	merge_size = 4;
	while (merge_level--)
		merge_size *= 2;

	to_merge_in_a = int_min_of_two((merge_size / 2), *unmerged_a);
	to_merge_in_b = int_min_of_two((merge_size / 2), *unmerged_b);

	if (*unmerged_b >= unmerged_a)
		merge_to_a(machine, to_merge_in_a, to_merge_in_b);
	else
		merge_to_b(machine, to_merge_in_a, to_merge_in_b);

	*unmerged_a -= to_merge_in_a;
	*unmerged_b -= to_merge_in_b;

	return ;
}

int     get_merge_levels(t_stack_machine *machine)
{
    int len;
    int level;
    int merge_size;

    len = machine -> stacks[0].len;
    level = 0;
    merge_size = 4;
    while ((level < 30) && (merge_size < len))
    {   
        merge_size *= 2;
        level++;
    }   
    return (level);
}
