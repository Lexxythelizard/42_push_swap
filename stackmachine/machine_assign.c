// --- include ---

#include "./machine.h"

// --- DOC --

/*
TODO:   - test
*/

// --- proto --- for tests

int	machine_stack_init(t_stack_machine *machine, int *arr, int len);
int	machine_func_assign(t_stack_machine *machine);
int	machine_assign_entropy(t_stack_machine *machine, float entro);
int	machine_assign_strategy(t_stack_machine *machine, int flag_val);

void	sa(t_stack_machine *machine);
void	sb(t_stack_machine *machine);
void	ss(t_stack_machine *machine);
void	pa(t_stack_machine *machine);
void	pb(t_stack_machine *machine);
void	ra(t_stack_machine *machine);
void	rb(t_stack_machine *machine);
void	rr(t_stack_machine *machine);
void	rra(t_stack_machine *machine);
void	rrb(t_stack_machine *machine);
void	rrr(t_stack_machine *machine);

// --- define ---

int	machine_stack_init(t_stack_machine *machine, int *arr, int len)
{
	t_stack	*stack_a;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	return (stack_init(stack_a, arr, len));
}

int	machine_func_assign(t_stack_machine *machine)
{
	if (!machine)
		return (-1);
	func_init(&(machine -> funcs[SA]),&sa, SA_STR);
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

int	machine_assign_entropy(t_stack_machine *machine, float entro)
{
	if (!machine)
		return (-1);
	if ((entro < 0.0) || (entro > 1.00))
		return (-1);
	machine -> stats.entropy = entro;
	return (1);
}

int	machine_assign_strategy(t_stack_machine *machine, int flag_val)
{
	if (!machine)
		return (-1);
	flag_val = stats_assign_strategy_by_flag(&(machine -> stats), flag_val);
	if (flag_val == ADAPTIVE_VAL)
		return (stats_assign_strategy_by_entropy(&(machine -> stats)));
	return (flag_val);
}

// --- for testing ---

void	sa(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	sb(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	ss(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	pa(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	pb(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	ra(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	rb(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	rr(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	rra(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	rrb(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}

void	rrr(t_stack_machine *machine)
{
	(void)(machine);
	return ;
}
