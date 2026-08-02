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

// --- prototype ---

static int	is_current_value_smaller_than_next(t_element *element);

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
	t_element	*cursor;

	if (!stack)
		return (-1);
	idx = 0;
	cursor = stack -> first;
	while (cursor)
	{
		if (cursor -> val == val)
			return (idx);
		idx++;
		cursor = cursor -> next;
	}
	return (-1);
}

int	stack_count_descending_in_range(
		t_stack *stack,
		int start,
		int range)
{
	int			count;
	int			ctrl;
	t_element	*cursor;

	count = 0;
	if ((start >= stack -> len) || ((range + start) > stack -> len))
		return (-1);
	cursor = stack -> first;
	while ((count++ < start) && (cursor))
		cursor = cursor -> next;
	count = 0;
	while ((count < range) && (cursor))
	{
		count++;
		ctrl = is_current_value_smaller_than_next(cursor);
		if (ctrl == (-1))
			return (-1);
		if (ctrl)
			break ;
		cursor = cursor -> next;
	}
	return (count);
}

int	stack_count_ascending_in_range(
		t_stack *stack,
		int start,
		int range)
{
	int			count;
	int			ctrl;
	t_element	*cursor;

	count = 0;
	if ((start >= stack -> len) || ((range + start) > stack -> len))
		return (-1);
	cursor = stack -> first;
	while ((count++ < start) && (cursor))
		cursor = cursor -> next;
	count = 0;
	while ((count < range) && (cursor))
	{
		count++;
		ctrl = (!(is_current_value_smaller_than_next(cursor)));
		if (ctrl == (-1))
			return (-1);
		if (ctrl)
			break ;
		cursor = cursor -> next;
	}
	return (count);
}

// --- utility ---

static int	is_current_value_smaller_than_next(t_element *element)
{
	if (!element)
		return (-1);
	if (!(element -> next))
		return (0);
	return (element -> val < element -> next -> val);
}
