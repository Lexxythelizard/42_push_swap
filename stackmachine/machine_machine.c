// --- include ---

#include "./machine.h"

// --- DOC --

/*
TODO:   - test
*/

// --- proto --- for tests

int	machine_init_new_empty(t_stack_machine *machine);
int	machine_free(t_stack_machine *machine);

// --- define ---

int	machine_init_new_empty(t_stack_machine *machine)
{
	int	i;

	i = 0;
	if (!machine)
		return (-1);
	stack_init_empty(&(machine -> stacks[0]));
	stack_init_empty(&(machine -> stacks[1]));
	stats_init_empty(&(machine -> stats));
	while (i++ < OPS_N)
		func_init_empty(&(machine -> funcs[(i - 1)]));
	return (1);
}

int	machine_free(t_stack_machine *machine)
{
	int	count;

	count = 0;
	if (!machine)
		return (-1);
	count += stack_free(&(machine -> stacks[0]));
	count += stack_free(&(machine -> stacks[1]));
	machine_init_new_empty(machine);
	return (count);
}
