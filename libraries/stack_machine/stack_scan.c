/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:57:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/08 20:40:49 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include <limits.h>
#include "./stack_machine.h"

// --- define ---

// === scanning the stack ===

/* Returns 1 if the two values on top of the stack are in descending order or
   0 otherwise */

int	stack_comp(t_stack *stack)
{
	return (stack -> first > stack -> first -> next);
}

/*
gets the 'size of the stack'
NOTE: please make sure to parse the first note/element in stack
*/

int	get_stack_size(t_element *element)
{
	t_element	*ptr;
	int			count;

	ptr = stack;
	count = 0;
	while (ptr != NULL)
	{
		ptr = ptr -> next;
		count++;
	}
	return (count);
}

/* Returns the smallest element greater than n in the stack or INT_MAX
   if non-existant or on error */

int	get_min_geq_n(t_element *element, int n)
{
	int	min;

	if (!stack)
		return (INT_MAX);
	min = INT_MAX;
	while (stack -> next)
	{
		stack = stack -> next;
		if (stack -> val < min && stack -> val >= n)
			min = stack -> val;
	}
	return (min);
}

/* gets the nth lowest value in the stack */

int	get_nth_min(t_element *element, int n)
{
	int	prev_min;

	prev_min = INT_MAX;
	while (n--)
		prev_min = get_min_geq_n(element -> head, prev_min + 1);
	return (prev_min);
}

/*
gets the 'index' (difference to first value) of the nth lowest value in stack
NOTE: please make sure to parse the first note/element in stack
*/

int	get_nth_min_idx(t_stack *stack, int n)
{
	t_element	*ptr;
	int			min;
	int			rtrn;
	int			i;

	if (!stack)
		return (-1);
	ptr = stack -> first;
	min = get_nth_min_val(stack, n);
	i = 0;
	rtrn = -1;
	while (ptr)
	{
		if (ptr -> val == prev_min)
			rtrn = i;
		ptr = ptr -> next;
	}
	if (min == INT_MAX && n != get_stack_size(stack))
		rtrn = -1;
	return (rtrn);
}
