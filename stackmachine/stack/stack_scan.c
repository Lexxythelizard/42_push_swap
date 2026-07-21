// --- include ---

#include <limits.h>
#include "./stack.h"

// --- DOC --

/*
TODO:   test, norminette, comment
*/

// --- proto --- for tests

int	stack_is_first_and_sec_ascending(t_stack *stack);

// --- define ---

/*
Returns 1 if the two values on top of the stack are in descending order or
0 otherwise
*/

int	stack_is_first_and_sec_ascending(t_stack *stack)
{
	if (!stack)
		return (-1);
	if (stack -> len <= 1)
		return (1);
	return (stack -> first -> val < stack -> first -> next -> val);
}

/*
returns the in val in stack
returns INT_MAX by default
so no error catching
*/

int	stack_get_min_val(t_stack *stack)
{
	int			min;
	t_element	*cursor;

	if (!stack)
		return (0);
	if ((stack -> len <= 0) || (stack -> first == NULL))
		return (0);
	min = INT_MAX;
	cursor = stack -> first;
	while (cursor)
	{
		if (cursor -> val < min)
			min = cursor -> val;
		cursor = cursor -> next;
	}
	return (min);
}

/*
returns idx of min value
returns -1 if error
*/

int	stack_get_idx_min_val(t_stack *stack)
{
	int			idx;
	int			min;
	t_element	*cursor;

	if (!stack)
		return (-1);
	if (stack -> len == 0)
		return (-1);
	if (stack -> len == 1)
		return (0);
	idx = 0;
	min = stack_get_min_val(stack);
	cursor = stack -> first;
	while (cursor)
	{
		if (cursor -> val == min)
			return (idx);
		idx++;
		cursor = cursor -> next;
	}
	return (-1);
}
