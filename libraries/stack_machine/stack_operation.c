// --- include ---

#include "./stackmachine.h"

// --- DOC --

/*
TODO:   test
*/

// --- proto --- for tests

int	swap(t_stack *stack);
int	push(t_stack *from, t_stack *to);
int	rotate(t_stack *stack);
int	reverse_rotate(t_stack *stack);

// --- define ---

/*
Swaps first two elements of stack,
return	0 / 1 : not swapable / success
return	-1 if error
*/

int	swap(t_stack *stack)
{
	t_element	*new_first;
	t_element	*new_sec;

	if (!stack)
		return (-1);
	if (stack -> len <= 1)
		return (0);
	new_sec = stack_pop_first(stack);
	new_first = stack_pop_first(stack);
	stack_add_first(stack, new_sec);
	stack_add_first(stack, new_first);
	return (1);
}

/*
Pushes the first element of stack 'from' to the top of stack 'to'
by calling pop and add
return	0 / 1	: not popable / success
return	-1		: if error
*/

int	push(t_stack *from, t_stack *to)
{
	t_element	*element;

	if ((!from) || (!to))
		return (-1);
	if (!(from -> len))
		return (0);

	// pop
	element = stack_pop_first(from);

	// add
	stack_add_first(to, element);
	return (1);
}

/*
rotates stack forward:
last element becomes first, first becomes second, ...
return	0 / 1	: empty / success
return	-1 		: if error
*/

int	rotate(t_stack *stack)
{
	t_element	*element;

	if (!stack) 
		return (-1);
	if (stack -> len <= 1)
		return (stack -> len);
	element = stack_pop_last(stack);
	stack_add_first(stack, element);
	return (1);
}

/*
rotates stack backward:
first element becomes last, second becomes first, ...
return	0 / 1	: empty / success
return	-1 		: if error
*/

int	reverse_rotate(t_stack *stack)
{
	t_element	*element;

	if (!stack) 
		return (-1);
	if (stack -> len <= 1)
		return (stack -> len);
	element = stack_pop_first(stack);
	stack_add_last(stack, element);
	return (1);
}
