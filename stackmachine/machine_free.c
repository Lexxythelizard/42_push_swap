// --- include ---

#include "./machine.h"

// --- DOC --

/*
TODO:	reimplement from scratch
*/

// --- proto --- for tests

void	free_machine(t_stack_machine *machine);

// --- define ---

void	free_machine(t_stack_machine *machine)
{
	int	i;

	free_stack(&(machine -> stacks[0]));
	free_stack(&(machine -> stacks[1]));
	free(machine -> stacks);
	if (machine -> stats)
	{
		free(machine -> stats -> calls);
		free(machine -> stats);
	}
	i = 0;
	while (i < 11)
		free(&((machine -> funcs)[i++]));
}
