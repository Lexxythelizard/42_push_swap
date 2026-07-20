// --- include ---

#include "./machine.h"
#include "../libraries/libft/libft.h"

// --- DOC --

/*
TODO:   refactor and test
*/

// --- proto --- for tests

int	pa(t_stack_machine *machine);
int	pb(t_stack_machine *machine);

// --- define ---

int	pa(t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		ctrl;

	if (!machine)
		return (-1);
	stack_a = &((machine -> stacks)[0]);
	stack_b = &((machine -> stacks)[1]);
	ctrl = push(stack_b, stack_a);
	if (ctrl == 1)
		ft_putendl_fd(PA_STR, 1);
	return (ctrl);
}

int	pb(t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		ctrl;

	if (!machine)
		return (-1);
	stack_a = &((machine -> stacks)[0]);
	stack_b = &((machine -> stacks)[1]);
	ctrl = push(stack_b, stack_a);
	if (ctrl == 1)
		ft_putendl_fd(PB_STR, 1);
	return (ctrl);
}
