// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	test and comment
*/

// --- prototype ---

static int	top_a_smaller_than_top_b(t_stack_machine *machine);
static int	top_b_smaller_than_top_a(t_stack_machine *machine);

// --- define ---

void	merge_to_a(
			t_stack_machine *machine,
			int to_merge_in_a,
			int to_merge_in_b)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	while (to_merge_in_b)
	{
		if (top_b_smaller_than_top_a(machine))
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

void	merge_to_b(
			t_stack_machine *machine,
			int to_merge_in_a,
			int to_merge_in_b)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	while (to_merge_in_a)
	{
		if (top_a_smaller_than_top_b(machine))
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
