// --- include ---

#include "./stack_machine.h"

// --- DOC --

/*
TODO:   reimplement from scratch
*/

// --- proto --- for tests

void	ra(t_stack_machine *machine);
void	rb(t_stack_machine *machine);
void	rr(t_stack_machine *machine);

// --- define ---

void	ra(t_stack_machine *machine)
{
	rotate(&((machine -> stacks)[0]));
}

void	rb(t_stack_machine *machine)
{
	rotate(&((machine -> stacks)[1]));
}

void	rr(t_stack_machine *machine)
{
	ra(machine);
	rb(machine);
}
