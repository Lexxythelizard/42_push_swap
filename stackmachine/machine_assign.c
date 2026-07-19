// --- include ---

#include "./machine.h"

// --- DOC --

/*
	This file contains the following assign functions:

		- machine_stack_init()
		- machine_func_assign
		- machine_assign_entropy
		- machine_assign_strategy

	all the following functions calling other functions, like stack_init,
	func_init, etc...
	even if they appear a little redundant, they are made for easier 
	handling of the t_stack_machine instance
*/

// --- define ---

/*
this function initializes stack_a of the stack machine
by calling stack_init
returns lengths of initialised stack and -1 if error occures

please make sure to pass a pointer to an empty instance of stack machine
*/

int	machine_stack_init(t_stack_machine *machine, int *arr, int len)
{
	t_stack	*stack_a;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	return (stack_init(stack_a, arr, len));
}

/*
this function initializes the functions by calling func_init
assings opeartions:

	sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

returns 1 if succes and -1 if error occures
*/

int	machine_func_assign(t_stack_machine *machine)
{
	if (!machine)
		return (-1);
	func_init(&(machine -> funcs[SA]), &sa, SA_STR);
	func_init(&(machine -> funcs[SB]), &sb, SB_STR);
	func_init(&(machine -> funcs[SS]), &ss, SS_STR);
	func_init(&(machine -> funcs[PA]), &pa, PA_STR);
	func_init(&(machine -> funcs[PB]), &pb, PB_STR);
	func_init(&(machine -> funcs[RA]), &ra, RA_STR);
	func_init(&(machine -> funcs[RB]), &rb, RB_STR);
	func_init(&(machine -> funcs[RR]), &rr, RR_STR);
	func_init(&(machine -> funcs[RRA]), &rra, RRA_STR);
	func_init(&(machine -> funcs[RRB]), &rrb, RRB_STR);
	func_init(&(machine -> funcs[RRR]), &rrr, RRR_STR);
	return (1);
}

/*
this function assigns the entropy value to the instance of stack machine
returns 1 if succes and -1 if error occures
*/

int	machine_assign_entropy(t_stack_machine *machine, float entro)
{
	if (!machine)
		return (-1);
	if ((entro < 0.0) || (entro > 1.00))
		return (-1);
	machine -> stats.entropy = entro;
	return (1);
}

/*
this function assigns the strategy to the instance of stack machine
by orchestering the functions:
	- stats_assign_strategy_by_flag
	- stats_assign_strategy_by_entropy

returns one of the flag keys {4, 2, 1, 0} if success
and -1 if error occures
*/

int	machine_assign_strategy(t_stack_machine *machine, int flag_val)
{
	if (!machine)
		return (-1);
	flag_val = stats_assign_strategy_by_flag(&(machine -> stats), flag_val);
	if (flag_val == ADAPTIVE_VAL)
		return (stats_assign_strategy_by_entropy(&(machine -> stats)));
	return (flag_val);
}
