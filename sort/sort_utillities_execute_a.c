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

int	push_all_elements_to_stack_a(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			PA,
			machine -> stacks[1].len));
}

int	swap_second_and_third_a(t_stack_machine *machine)
{
	if (!machine)
		return (-1);
	if (machine -> stacks[0].len < 3)
		return (0);
	machine_operation_execute(machine, RA);
	machine_operation_execute(machine, SA);
	machine_operation_execute(machine, RRA);
	return (1);
}

int	swap_first_and_third_a(t_stack_machine *machine)
{
	if (!machine)
		return (-1);
	if (machine -> stacks[0].len < 3)
		return (0);
	machine_operation_execute(machine, RRA);
	machine_operation_execute(machine, SA);
	machine_operation_execute(machine, RA);
	return (1);
}

