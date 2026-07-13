// --- include ---

#include "./stack_machine.h"

// --- DOC --

/*
TODO:   refactor and test
*/

// --- proto --- for tests

void	pa(t_stack_machine *machine);
void	pb(t_stack_machine *machine);

// --- define ---


// --- def ---

void	pa(t_stack_machine *machine)
{
	push(&((machine -> stacks)[0]), &((machine -> stacks)[1]));
}

void	pb(t_stack_machine *machine)
{
	push((&(machine -> stacks)[1]), &((machine -> stacks)[0]));
}
