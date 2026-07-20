// --- include ---

#include "./machine.h"
#include "../libraries/libft/libft.h"

// --- DOC --

/*
    this file contains the Operations {ra, rb, rr}

        both are taking a pointer to an in stance of t_stack_machine 
        and calling the rotate on its members stack a or stack b

        functions writing ra / rb / rr to standart output if success

        return:

            no operation possible   :   0
            success                 :   1
            error                   :   -1
*/

// --- define ---

/*
calls rotate to pop the last element of stack a 
and add it on top of it
    --> rotate stack a
*/

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

/*
calls rotate to pop the last element of stack b 
and add it on top of it
    --> rotate stack b
*/

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

/*
calls rotate to pop the last element of stack a and stack b
and add it on top of stack a and stack b
    --> rotate stack a and stack b
*/

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
