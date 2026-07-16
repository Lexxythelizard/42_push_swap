// --- include ---

#include "./stack_machine.h"

// --- DOC --

/*
TODO:   refactor and test
*/

// --- proto --- for tests

void	sa(t_stack_machine *machine);
void	sb(t_stack_machine *machine);
void	ss(t_stack_machine *machine);

// --- define ---

void	sa(t_stack_machine *machine)
{
	swap(&((machine -> stacks)[0]));
}

void	sb(t_stack_machine *machine)
{
	swap(&((machine -> stacks)[1]));
}

void	ss(t_stack_machine *machine)
{
	sa(machine);
	sb(machine);
}
