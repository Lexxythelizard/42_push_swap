// --- include ---

#include "./stackmachine.h"

// --- DOC --

/*
TODO:   reimplement from scratch
*/

// --- proto --- for tests

int	swap(t_stack *stack);
int	push(t_stack *from, t_stack *to);
int	rotate(t_stack *stack);
int	reverse_rotate(t_stack *stack);

// --- define ---

/* Swap first two elements of c */
int	swap(t_stack *stack)
{
	t_element	*new_first;
	t_element	*new_sec;

	if (!(stack -> first))
		return (-1);
	if (!(stack -> len <= 1))
		return (0);

	new_sec = stack_pop_first(stack);
	new_first = stack_pop_first(stack);

	stack_add_first(stack, new_sec);
	stack_add_first(stack, new_first);

	/*
	new_first = stack -> first -> next;
	new_sec = stack -> first;
	
	new_sec -> next = stack -> first -> next -> next;
	new_sec -> prev = new_first;

	new_first -> next = new_sec;
	new_first -> prev = NULL;

	stack -> first = new_first;
	if (!(new_sec -> next))
		stack -> last = new_sec;
	*/

	return (1);
}

/* Push first element of d on top of c */
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

/* rotate upwards one step */
int	rotate(t_stack *stack)
{
	t_element	*element;

	if (!stack) 
		return (-1);
	if (stack -> len == 1)
		return (stack -> len);

	element = stack_pop_last(stack);
	stack_add_first(stack, element);

	/*
	ptr = stack -> last;
	
	stack -> last -> prev -> next = NULL;

	stack -> last -> next = stack -> first;
	stack -> first -> prev = stack -> last;
	stack -> last = stack -> first;
	stack -> first = stack -> first -> next;
	stack -> first -> prev = NULL;
	stack -> last -> next = NULL;

	stack -> last -> next = stack -> first;

	stack -> last -> prev -> next = NULL;
	*/
	return (1);
}

/* rotate downwards one step */
int	reverse_rotate(t_stack *stack)
{
	t_element	*element;

	if (!stack) 
		return (-1);
	if (stack -> len == 1)
		return (stack -> len);

	element = stack_pop_first(stack);
	stack_add_last(stack, element);

	/*
	stack -> first -> prev = stack -> last;
	stack -> last -> next = stack -> first;
	stack -> first = stack -> last;
	stack -> last = stack -> last -> prev;
	stack -> last -> next = NULL;
	stack -> first -> prev = NULL;
	*/

	return (1);
}
