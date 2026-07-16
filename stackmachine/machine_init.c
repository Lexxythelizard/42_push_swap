// --- include ---

#include "./stackmachine.h"

// --- DOC --

/*
TODO:   - reimplement from scratch
		- source out func_ functions
		- source out stats_ functions
*/

// --- proto --- for tests

t_stack_machine	*machine_init_new_empty(void);
void			machine_func_assign(t_stack_machine *machine);

// --- define ---

t_stack_machine	machine_init_new_empty(void)
{
	t_stack_machine	machine;

	stack_init_empty(&(machine.stack[0]));
	stack_init_empty(&(machine.stack[1]));
	stats_init_empty(&(machine.stats));
	func_assign_empty(&machine);
	return (machine);
}

void	machine_init_stack(t_stack_machine *machine, int *arr, int len)
{
	return ;
}

void	machine_func_assign(t_stack_machine *machine)
{
	machine -> funcs[SA] = func_init(&sa, SA_STR);
	machine -> funcs[SB] = func_init(&sb, SB_STR);
	machine -> funcs[SS] = func_init(&ss, SS_STR);
	machine -> funcs[PA] = func_init(&pa, PA_STR);
	machine -> funcs[PB] = func_init(&pb, PB_STR);
	machine -> funcs[RA] = func_init(&ra, RA_STR);
	machine -> funcs[RB] = func_init(&rb, RB_STR);
	machine -> funcs[RR] = func_init(&rr, RR_STR);
	machine -> funcs[RRA] = func_init(&rra, RRA_STR);
	machine -> funcs[RRB] = func_init(&rrb, RRB_STR);
	machine -> funcs[RRR] = func_init(&rrr, RRR_STR);
}
