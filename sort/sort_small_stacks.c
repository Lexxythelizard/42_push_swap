// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	test, norminette
*/

// --- define ---

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pa n times; n = length of stack a
*/

int	sort_two(t_stack_machine *machine)
{
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	if (stack_a -> len <= 1)
		return (-1);
	if (stack_is_first_and_sec_ascending(stack_a))
		return (0);
	return (
		machine_operation_execute(machine, SA));
}

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pb n times; n = length of stack b
*/

int	sort_three(t_stack_machine *machine)
{
	t_stack	*stack_a;
	int		first;
	int		secon;
	int		third;

	stack_a = &(machine -> stacks[0]);
	if (stack_a -> len <= 2)
		return (-1);

	first = stack_a -> first -> val;
	secon = stack_a -> first -> next -> val;
	third = stack_a -> first -> next -> next -> val;

	if ((first <= secon) && (secon <= third))
		return (0);
	if ((first <= third) && (third <= secon))
		swap_second_and_third_a(machine);					// RA SA RRA
	if ((secon <= first) && (first <= third))
		return (machine_operation_execute(machine, SA));	// SA
	if ((secon <= third) && (third <= first))
		return (machine_operation_execute(machine, RA));	// RA
	if ((third <= first) && (first <= secon))
		return (machine_operation_execute(machine, RRA));	// RRA
	if ((third <= secon) && (secon <= first))
		swap_first_and_third_a(machine);					// RRA SA RA
		//1 2 3 --> 3 1 2 --> 1 3 2 --> 3 2 1
	return (0);
}
