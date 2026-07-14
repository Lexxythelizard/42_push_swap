// --- include ---

#include "./stackmachine.h"

// --- DOC --

/*
	This file ocontains the very basic operations of stack:

		- pop :		first / last
		- add :		first / last

		all the functions updating
			- stack -> first
			- stack -> last
			- stack -> len
	
		pop functions return a single element with cut off connections

		t_element	: {val: [n];	prev: NULL;	next: NULL}
*/

// --- define ---

/*
pops first element of stack: updates stack
returns NULL if error
*/

t_element	*stack_pop_first(t_stack *stack)
{
	t_element	*ptr;

	ptr = NULL;
	if (!stack)
		return (ptr);
	if (stack -> len == 0)
		return (ptr);
	ptr = stack -> first;
	if (!(stack -> len))
		return (ptr);
	if (stack -> len == 1)
		stack_init_empty(stack);
	else
	{
		stack -> first = stack -> first -> next;
		stack -> first -> prev = NULL;
		stack -> len--;
	}
	ptr -> next = NULL;
	ptr -> prev = NULL;
	return (ptr);
}

/*
pops last element of stack: updates stack
returns NULL if error
*/

t_element	*stack_pop_last(t_stack *stack)
{
	t_element	*ptr;

	ptr = NULL;
	if ((!stack) || (!(stack -> len)))
		return (ptr);
	ptr = stack -> last;
	if (stack -> len == 1)
		stack_init_empty(stack);
	else
	{
		stack -> last = stack -> last -> prev;
		stack -> last -> next = NULL;
		stack -> len--;
	}
	ptr -> next = NULL;
	ptr -> prev = NULL;
	return (ptr);
}

/*
adds element to stack as new first: updates stack
returns new length 
returns -1 if error
*/

int	stack_add_first(t_stack *stack, t_element *new)
{
	if (!stack)
		return (-1);
	if (!new)
		return (0);
	if (!(stack -> len))
		return (stack_init_add(stack, new));
	new -> next = stack -> first;
	stack -> first -> prev = new;
	stack -> first = new;
	stack -> len++;
	return (stack -> len);
}

/*
adds element to stack as new last: updates stack
returns new length 
returns -1 if error
*/

int	stack_add_last(t_stack *stack, t_element *new)
{
	if (!stack)
		return (-1);
	if (!new)
		return (0);
	new -> prev = stack -> last;
	if (!(stack -> len))
		return (stack_init_add(stack, new));
	stack -> last = element_add_next(stack -> last, new);
	stack -> len++;
	return (stack -> len);
}

/*
adds element to stack as new first and new last and 
sets its length to one
returns new length (1) 
returns -1 if error

CAUTION:	Just use if stack is empty, otherwise
			elements are cut of...
*/

int	stack_init_add(t_stack *stack, t_element *new)
{
	if (!stack)
		return (-1);
	if (!new)
		return (0);
	stack -> first = new;
	stack -> last = new;
	stack -> len++;
	return (1);
}
