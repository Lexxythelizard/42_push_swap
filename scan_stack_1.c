/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:57:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/27 13:39:11 by lenivorb         ###   ########.fr       */
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
	
	if (!(stack))
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

int	get_index_min_val(t_stack *stack)
{
	t_stack_frame	*ptr;
	int				min;
	int				count;
	int				i;
	
	if ((!(stack)) || (!(stack -> head)))
		return (-1);
	ptr = stack -> head;
	min = ptr -> val;
	i = 0;
	count = 0;
	while (ptr -> next != NULL)
	{
		ptr = ptr -> next;
		i++;
		if (ptr -> val < min)
		{
			count = i;
			min = ptr -> val;
		}
	}
	return (count);
}

/*
gets the 'index' (difference to first value) of the greates value in stack
NOTE: please make sure to parse the first note/element in stack
*/

int	get_index_max_val(t_stack *stack)
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
