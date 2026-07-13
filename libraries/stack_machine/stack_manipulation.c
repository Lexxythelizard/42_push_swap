// --- include ---

#include "./stack_machine.h"

// --- DOC ---

/*TODO:	test functions*/

// --- proto --- for tests

void	stack_init_empty(t_stack *stack);
int		stack_init(t_stack *stack, int *arr, int len);
int		free_stack(t_stack *stack);

// --- define ---

void	stack_init_empty(t_stack *stack)
{
	stack -> first = NULL;
	stack -> last = NULL;
}

int	stack_init(t_stack *stack, int *arr, int len)
{

	i = 0;
	if ((!stack) || (!nums) || (len <= 0))
		return (-1);
	stack -> first = element_new_list(arr, len);
	stack -> last = stack -> first;
	if ((!stack) && (len >= 1))
		return (-1);
	while (stack -> last -> next)
		stack -> last = stack -> last -> next;
	return (len);
}

int	free_stack(t_stack *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (-1);
	count = element_free_tail(stack -> first);
	stack_init_empty(stack);
	return (count);
}
