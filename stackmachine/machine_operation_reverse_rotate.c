// --- include ---

#include "./stack_machine.h"

// --- DOC --

/*
TODO:   refactor and test
*/

// --- proto --- for tests

void	rra(t_stack_machine *machine);
void	rrb(t_stack_machine	*machine);
void	rrr(t_stack_machine *machine);

// --- define ---

void	rra(t_stack_machine *machine)
{
	reverse_rotate(&((machine -> stacks)[0]));
}

void	rrb(t_stack_machine	*machine)
{
	reverse_rotate(&((machine -> stacks)[1]));
}

void	rrr(t_stack_machine *machine)
{
	rra(machine);
	rrb(machine);
}
