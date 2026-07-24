// --- include ---

#include <limits.h>
#include "./stack.h"

// --- DOC --

/*
TODO:   test, norminette, comment
*/

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

int	stack_get_idx_of_val(t_stack *stack, int val)
{
	int			idx;
	int			min;
	t_element	*cursor;

	if (!stack)
		return (-1);
	idx = 0;
	cursor = stack -> first;
	while (cursor)
	{
		if (cursor -> val == val)
			return (idx) ;
		cursor = cursor -> next;
	}
	return (-1);
}
