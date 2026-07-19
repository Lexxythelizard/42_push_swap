// --- include ---

#include "./machine.h"

// --- DOC --

/*
	This file contains the basic machine manipulation function:

		- machine_init_new_empty
		- machine_free
*/

// --- proto --- for tests

int	machine_init_new_empty(t_stack_machine *machine);
int	machine_free(t_stack_machine *machine);

// --- define ---

/*
initialize the instance of stack_machine, 
by setting all its member values to 0 / NULL
should be the first function you call on stackmachine 
after declaring it

returns 1 if succes and -1 if error
*/

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

/*
frees alle elements of both stacks and sets machine back to empty
returns number of freed elements
returns -1 if error
*/

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
