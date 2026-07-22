// --- icludes ---

#include <limits.h>
#include "./sort.h"

// --- DOC ---

/*
TODO:	reimplement from scratch
*/

// --- prototype ---

void	merge_sort(t_stack_machine *machine);
void	merge_level(t_stack_machine *machine);
void	merge(t_stack_machine *machine);

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

void	merge_level(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

/*coordinates the two merge functions like a pendulum*/

void	merge(t_stack_machine *machine)
{
	(void)(machine);
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
