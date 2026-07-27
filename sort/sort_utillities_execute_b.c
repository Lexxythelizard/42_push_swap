// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	test, norminette
*/

// --- define ---

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pb n times; n = length of stack b
*/

int	push_all_elements_to_stack_b(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			PB,
			machine -> stacks[0].len));
}

int	swap_second_and_third_b(t_stack_machine *machine)
{
	if (!machine)
		return (-1);
	if (machine -> stacks[1].len < 3)
		return (0);
	machine_operation_execute(machine, RB);
	machine_operation_execute(machine, SB);
	machine_operation_execute(machine, RRB);
	return (1);
}

int	swap_first_and_third_b(t_stack_machine *machine)
{
	if (!machine)
		return (-1);
	if (machine -> stacks[1].len < 3)
		return (0);
	machine_operation_execute(machine, RRB);
	machine_operation_execute(machine, SB);
	machine_operation_execute(machine, RB);
	return (1);
}
