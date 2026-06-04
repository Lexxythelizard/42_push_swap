/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:57:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/04 18:02:28 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === scanning the stack ===

/*
gets the 'size of the stack'
NOTE: please make sure to parse the first note/element in stack
*/

int	get_stack_size(t_stack *stack)
{
	t_stack_frame	*ptr;
	int				count;
	
	if (!stack)
		return (-1);
	if (!(stack -> head))
		return (0);
	ptr = stack -> head;
	count = 1;
	while (ptr -> next != NULL)
	{
		ptr = ptr -> next;
		count++;
	}
	return (count);
}

/*
gets the 'index' (difference to first value) of the lowest value in stack
NOTE: please make sure to parse the first note/element in stack
*/

int	get_min_geq_n(t_stack_frame *stack, int n)
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

int	get_nth_min(t_stack *stack, int n)
{
	int				prev_min;
	int				rtrn;
	int				i;
	
	prev_min = INT_MAX;
	while (n--)
		prev_min = get_min_larger_n(stack -> head, prev_min + 1);
	return (prev_min);
}

int	get_nth_min_idx(t_stack	*stack, int n)
{
	t_stack_frame	*ptr;
	int				min;
	int				rtrn;
	int				i;
	
	if (!stack)
		return (-1);
	ptr = stack -> head;
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
/*
gets the 'index' (difference to first value) of the greates value in stack
NOTE: please make sure to parse the first note/element in stack
*/

int	get_idx_max(t_stack *stack)
{
	t_stack_frame	*ptr;
	int				max;
	int				count;
	int				i;
	
	if ((!(stack)) || (!(stack -> head)))
		return (-1);
	ptr = stack -> head;
	max = ptr -> val;
	i = 0;
	count = 0;
	while (ptr -> next != NULL)
	{
		ptr = ptr -> next;
		i++;
		if (ptr -> val > max)
		{
			count = i;
			max = ptr -> val;
		}
	}
	return (count);
}
