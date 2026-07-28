// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
TODO: test
*/

// --- prototypes ---

// --- define ---

/*
comment
*/

void	bucket_insertion_sort_descending(
			t_stack_machine *machine,
			int	len)
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
