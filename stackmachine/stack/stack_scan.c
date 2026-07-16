// --- include ---

#include <limits.h>
#include "./stack.h"

// --- DOC --

/*
TODO:   reimplement from scratch
*/

// --- proto --- for tests

int	stack_is_first_and_sec_ascending(t_stack *stack);

// --- define ---

/* Returns 1 if the two values on top of the stack are in descending order or
   0 otherwise */

int	stack_is_first_and_sec_ascending(t_stack *stack)
{
	if (!stack)
		return (-1);
	if (stack -> len <= 1)
		return (1);
	return (stack -> first -> val < stack -> first -> next -> val);
}
