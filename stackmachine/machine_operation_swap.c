// --- include ---

#include "./machine.h"
#include "../libraries/libft/libft.h"

// --- DOC --

/*
TODO:   refactor and test
*/

// --- proto --- for tests

int	sa(t_stack_machine *machine);
int	sb(t_stack_machine *machine);
int	ss(t_stack_machine *machine);

// --- define ---

int	sa(t_stack_machine *machine)
{
	t_stack	*stack_a;
	int		ctrl;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	ctrl = swap(stack_a);
	if (ctrl == 1)
		ft_putendl_fd(SA_STR, 1);
	return (ctrl);
}

int	sb(t_stack_machine *machine)
{
	t_stack	*stack_b;
	int		ctrl;

	if (!machine)
		return (-1);
	stack_b = &(machine -> stacks[1]);
	ctrl = swap(stack_b);
	if (ctrl == 1)
		ft_putendl_fd(SB_STR, 1);
	return (ctrl);
}

int	ss(t_stack_machine *machine)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!machine)
		return (-1);
	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);
	if ((stack_a -> len == 0) || (stack_b -> len == 0))
		return (0);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd(SB_STR, 1);
	return (0);
}
