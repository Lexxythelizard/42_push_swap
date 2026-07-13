// --- include ---

#include "./stackmachine.h"

// --- DOC ---

/*
	This File contains all the basic t_stack functions

	t_stack itself isn't meant to get (dynamicly) allocated
	it will get automaticly allocated as member of t_stack_machine
*/

// --- proto --- for tests

int	stack_init_empty(t_stack *stack);
int	stack_init(t_stack *stack, int *arr, int len);
int	stack_free(t_stack *stack);

// --- define ---

/*
takes a pointer to an instance of stack and set's its len to 0
and its members first and last to NULL
returns (len) 0 if success and -1 if error
*/

int	stack_init_empty(t_stack *stack)
{
	if (!stack)
		return (-1);
	stack -> len = 0;
	stack -> first = NULL;
	stack -> last = NULL;
	return (0);
}

/*
takes:
	a pointer to an instance of stack
	a pointer to first elment of int array
	length of int array 
allocates all elements in heap
if success:
	sets stack -> len to len
	sets stack -> first to first element
	sets stack -> last to last elemenz
returns (len) of stack
returns -1 if error
*/

int	stack_init(t_stack *stack, int *arr, int len)
{
	if ((!stack) || (!arr) || (len <= 0))
		return (-1);
	stack -> first = element_new_list(arr, len);
	stack -> last = stack -> first;
	if ((!stack) && (len >= 1))
		return (-1);
	while (stack -> last -> next)
		stack -> last = stack -> last -> next;
	stack -> len = len;
	return (len);
}

/*
takes a pointer to an instance of stack and
calls element_free on every element of stack
calls stack_init_empty on stack
returns number of freed elements
returns -1 if error
*/

int	stack_free(t_stack *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (-1);
	count = element_free_tail(stack -> first);
	stack_init_empty(stack);
	return (count);
}
