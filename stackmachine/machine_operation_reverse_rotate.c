// --- include ---

#include "./machine.h"
#include "../libraries/libft/libft.h"

// --- DOC --

/*
TODO:   refactor and test
*/

// --- proto --- for tests

int	rra(t_stack_machine *machine);
int	rrb(t_stack_machine	*machine);
int	rrr(t_stack_machine *machine);

// --- define ---

int	rra(t_stack_machine *machine)
{
	t_stack *stack_a;
	int     ctrl;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	ctrl = reverse_rotate(stack_a);
	if (ctrl == 1)
		ft_putendl_fd(RRA_STR, 1); 
	return (ctrl);
}

int	rrb(t_stack_machine	*machine)
{
	t_stack *stack_a;
	int     ctrl;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	ctrl = reverse_rotate(stack_a);
	if (ctrl == 1)
		ft_putendl_fd(RRB_STR, 1); 
	return (ctrl);
}

int	rrr(t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	if ((stack_a -> len == 0) || (stack_b -> len == 0))
		return (0);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd(RRR_STR, 1);
	return (1);
}
