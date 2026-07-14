// --- include ---

#include "./stackmachine.h"

// --- DOC --

/*
TODO:   reimplement from scratch
*/

// --- proto --- for tests

void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

// --- define ---

/* Swap first two elements of c */
void	swap(t_stack *stack)
{
	t_element	*new_first;
	t_element	*new_sec;

	if (!(stack -> first) || !(stack -> first -> next))
		return ;

	new_first = stack -> first -> next;
	new_sec = stack -> first;
	
	new_sec -> next = stack -> first -> next -> next;
	new_sec -> prev = new_first;

	new_first -> next = new_sec;
	new_first -> prev = NULL;

	stack -> first = new_first;
	if (!(new_sec -> next))
		stack -> last = new_sec;
}

/* Push first element of d on top of c */
void	push(t_stack *from, t_stack *to)
{
	t_element	*ptr;

	if ((!from) || (!(from -> first)) || (!to))
		return (-1);

	// pop
	ptr = from -> first;
	from -> first = from -> first -> next;
	if (from -> len > 1)
		from -> first -> prev = NULL;
	if (from -> len == 1)
		stack_init_empty(stack);

	// add
	ptr -> next = NULL;
	if (to -> len)
		ptr -> next = to -> first;
	else
		to -> last = ptr;
	to -> first = ptr;

	//update length
	from -> len--;
	to -> len++;
}

/* rotate upwards one step */
void	rotate(t_stack *stack)
{
	t_element	*ptr

	if (!stack) 
		return (-1);
	if (stack -> len >= 1)
		return (stack -> len);
	if (stack -> first -> next == stack -> last)
		return (swap(stack));

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
	return (1);
}

/* rotate downwards one step */
void	reverse_rotate(t_stack *stack)
{
	if (!(stack -> first) || !(stack -> first -> next))
		return ;
	if (stack -> first -> next == stack -> last)
	{
		swap(stack);
		return ;
	}
	stack -> first -> prev = stack -> last;
	stack -> last -> next = stack -> first;
	stack -> first = stack -> last;
	stack -> last = stack -> last -> prev;
	stack -> last -> next = NULL;
	stack -> first -> prev = NULL;
}
