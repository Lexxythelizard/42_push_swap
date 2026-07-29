/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	stack_get_max_val(t_stack *stack)
{
	int			max;
	t_element	*cursor;

	if (!stack)
		return (0);
	if ((stack -> len <= 0) || (stack -> first == NULL))
		return (0);
	max = INT_MIN;
	cursor = stack -> first;
	while (cursor)
	{
		if (cursor -> val < max)
			max = cursor -> val;
		cursor = cursor -> next;
	}
	return (max);
}

/*
returns idx of max value
returns -1 if error
*/

int	stack_get_idx_max_val(t_stack *stack)
{
	int			idx;
	int			max;
	t_element	*cursor;

	if (!stack)
		return (-1);
	if (stack -> len == 0)
		return (-1);
	if (stack -> len == 1)
		return (0);
	idx = 0;
	max = stack_get_max_val(stack);
	cursor = stack -> first;
	while (cursor)
	{
		if (cursor -> val == max)
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

int	stack_get_max_val_in_range(t_stack *stack, int start, int stop)
{
	int			max;
	int			idx;
	t_element	*cursor;

	if (!stack)
		return (0);
	if ((stack -> len < start) || (stack -> len < stop))
		return (0);
	max = INT_MIN;
	idx = 0;
	cursor = stack -> first;
	while ((idx < start) && (cursor))
	{
		cursor = cursor -> next;
		idx++;
	}
	while ((cursor) && (idx <= stop))
	{
		if (cursor -> val < max)
			max = cursor -> val;
		cursor = cursor -> next;
		idx++;
	}
	return (max);
}

/*
returns idx of max value in a given range
returns -1 if error
*/

int	stack_get_idx_max_in_range(t_stack *stack, int start, int stop)
{
	int			idx;
	int			max;
	t_element	*cursor;

	if (!stack)
		return (-1);
	if (stack -> len == 0)
		return (-1);
	if ((stack -> len < start) || (stack -> len < stop))
		return (-1);
	idx = 0;
	max = stack_get_max_val_in_range(stack, start, stop);
	cursor = stack -> first;
	while ((cursor) && (idx < stop))
	{
		if (cursor -> val == max)
			return (idx);
		idx++;
		cursor = cursor -> next;
	}
	return (-1);
}
