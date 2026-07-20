// --- include ---

#include "./machine.h"
#include "../libraries/libft/libft.h"

// --- DOC --

/*
    this file contains the Operations {sa, sb, ss}

        both are taking a pointer to an in stance of t_stack_machine 
        and calling the swap on its members stack a or stack b

        functions writing sa / sb / ss to standart output if success

        return:

            no operation possible   :   0
            success                 :   1
            error                   :   -1
*/

// --- define ---

/*
calls swap to pop first two elements of stack a 
and add them in reversed order
	--> swap stack a
*/

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

/*
calls swap to pop first two elements of stack b 
and add them in reversed order
	--> swap stack b
*/

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

/*
calls swap to pop first two elements of stack a and stack b
and add them in reversed order
	--> swap stack a and stack b
*/

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
