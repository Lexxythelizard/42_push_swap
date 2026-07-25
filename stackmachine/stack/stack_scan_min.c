// --- include ---

#include <limits.h>
#include "./stack.h"

// --- DOC --

/*
TODO:   test, norminette, comment
*/

// --- define ---

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

/*
returns the in val in stack
returns INT_MAX by default
so no error catching
*/

int	stack_get_min_val_in_range(t_stack *stack, int start, int stop)
{
	int			min;
	int			idx;
	t_element	*cursor;

	if (!stack)
		return (0);
	if ((stack -> len < start) || (stack -> len < stop))
		return (0);
	min = INT_MAX;
	idx = 0;
	cursor = stack -> first;
	while ((idx < start) && (cursor))
	{
		cursor = cursor -> next;
		idx++;
	}
	while ((cursor) && (idx <= stop))
	{
		if (cursor -> val < min)
			min = cursor -> val;
		cursor = cursor -> next;
		idx++;
	}
	return (min);
}

/*
returns idx of min value in a given range
returns -1 if error
*/

int	stack_get_idx_min_in_range(t_stack *stack, int start, int stop)
{
	int			idx;
	int			min;
	t_element	*cursor;

	if (!stack)
		return (-1);
	if (stack -> len == 0)
		return (-1);
	if ((stack -> len < start) || (stack -> len < stop))
		return (-1);
	idx = 0;
	min = stack_get_min_val_in_range(stack, start, stop);
	cursor = stack -> first;
	while ((cursor) && (idx < stop))
	{
		if (cursor -> val == min)
			return (idx);
		idx++;
		cursor = cursor -> next;
	}
	return (-1);
}
