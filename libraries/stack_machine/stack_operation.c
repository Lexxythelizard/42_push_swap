/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:49:28 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 20:43:54 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

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
		return ;
	ptr = from -> first;
	if (from -> first == from -> last)
	{
		from -> first = NULL;
		from -> last = NULL;
	}
	else
		from -> first = from -> first -> next;
	ptr -> next = to -> first;
	if (to -> first)
		to -> first -> prev = ptr;
	to -> first = ptr;
	if (!(to -> last))
		to -> last = ptr;
}

/* rotate upwards one step */
void	rotate(t_stack *stack)
{
	if (!(stack -> first) || !(stack -> first -> next))
		return ;
	if (stack -> first -> next == stack -> last)
	{
		swap(stack);
		return ;
	}
	stack -> last -> next = stack -> first;
	stack -> first -> prev = stack -> last;
	stack -> last = stack -> first;
	stack -> first = stack -> first -> next;
	stack -> first -> prev = NULL;
	stack -> last -> next = NULL;
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
