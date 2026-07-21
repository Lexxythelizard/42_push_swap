// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	test, norminette
*/

// --- prototype ---

static int	push_element_on_top_to_stack_b(t_stack_machine *machine);
static int	rotate_smallest_element_to_top(t_stack_machine *machine);
static int	elements_in_stack_a(t_stack_machine *machine);
static int	push_all_elements_back_to_stack_b(t_stack_machine *machine);

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
	while (elements_in_stack_a(machine))
	{
		rotate_smallest_element_to_top(machine);
		push_element_on_top_to_stack_b(machine);
	}
	return (push_all_elements_back_to_stack_b(machine));
}

// --- utillieties ---

/*
just calles machine_operation_execute() --> pb
*/

static int	push_element_on_top_to_stack_b(t_stack_machine *machine)
{
	return (machine_operation_execute(machine, PB));
}

/*
get idx of min value
decide rotate / reverse rotate
rotate smallest element on top
*/	 
	
static int	rotate_smallest_element_to_top(t_stack_machine *machine)
{
	int		idx_min;
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	idx_min = stack_get_idx_min_val(stack_a);

	if (stack_a -> len == 1)
		return (0);

	if (idx_min <= (stack_a -> len / 2))
		return (
			machine_operation_execute_times_n(
				machine,
				RRA,
				idx_min));

	return (
		machine_operation_execute_times_n(
			machine,
			RA,
			(stack_a -> len - idx_min)));
}

/*
returns 1 / 0 :	elements in stack a / no elements in stack a
*/

static int	elements_in_stack_a(t_stack_machine *machine)
{
	return (machine -> stacks[0].len > 0);
}

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pa n times; n = length of stack b
*/

static int	push_all_elements_back_to_stack_b(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			PA,
			machine -> stacks[1].len));
}
