#ifndef MACHINE_H
# define MACHINE_H

// --- include ---

# include "./stack/stack.h"
# include "./stats/stats.h"
# include "./funcs/funcs.h"

// --- makros ---

// --- structs ---

typedef struct s_stack_machine
{
	t_stack	stacks[2];
	t_stats	stats;
	t_func	funcs[OPS_N];	
}			t_stack_machine;

// --- prototypes ---

// machine_machine.c

int	machine_init_new_empty(t_stack_machine *machine);
int	machine_free(t_stack_machine *machine);

// machine_assign.c

int	machine_stack_init(t_stack_machine *machine, int *arr, int len);
int	machine_func_assign(t_stack_machine *machine);
int	machine_assign_entropy(t_stack_machine *machine, float entro);
int	machine_assign_strategy(t_stack_machine *machine, int flag_val);

// machine_operation_swap.c

int sa(t_stack_machine *machine);
int	sb(t_stack_machine *machine);
int	ss(t_stack_machine *machine);

// machine_operation_push.c

int	pa(t_stack_machine *machine);
int	pb(t_stack_machine *machine);

// machine_operation_rotate.c

int	ra(t_stack_machine *machine);
int	rb(t_stack_machine *machine);
int	rr(t_stack_machine *machine);

// machine_operation_reverse_rotate.c

int	rra(t_stack_machine *machine);
int	rrb(t_stack_machine *machine);
int	rrr(t_stack_machine *machine);

// --- end ---

#endif
