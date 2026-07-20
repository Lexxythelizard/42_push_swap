// --- include ---

#include "./machine.h"
#include "../libraries/libft/libft.h"

// --- DOC --

/*
TODO:   reimplement from scratch
*/

// --- proto --- for tests

int	ra(t_stack_machine *machine);
int	rb(t_stack_machine *machine);
int	rr(t_stack_machine *machine);

// --- define ---

int	ra(t_stack_machine *machine)
{
	t_stack	*stack_a;
	int		ctrl;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	ctrl = rotate(stack_a);
	if (ctrl == 1)
		ft_putendl_fd(RA_STR, 1); 
	return (ctrl);
}

int	rb(t_stack_machine *machine)
{
	t_stack	*stack_b;
	int		ctrl;

	if (!machine)
		return (-1);
	stack_b = &(machine -> stacks[1]);
	ctrl = rotate(stack_b);
	if (ctrl == 1)
		ft_putendl_fd(RB_STR, 1); 
	return (ctrl);
}

int	rr(t_stack_machine *machine)
{
    t_stack	*stack_a;
    t_stack	*stack_b;

    if (!machine)
        return (-1);
	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	if ((stack_a -> len == 0) || (stack_b -> len == 0))
		return (0);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd(RR_STR, 1);
	return (1);
}
