/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:49:28 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 20:43:31 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

// --- define ---

/* TODO: Handle malloc errors (preferably within the 25 lines) */

t_element	*new_element(int val, t_element *prev)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new -> val = val;
	new -> prev = prev;
	new -> next = NULL;
	return (new);
}

/* Initialises a t_stack instance from a list of numbers */
int	stack_init(t_stack *stack, int	*nums, size_t len)
{
	t_element	*ptr0;
	t_element	*ptr1;

	if ((!stack) || (!nums) || (len))
		return (-1);
	ptr0 = new_element(nums[0], NULL);
	if (!ptr0)
		return (-1);
	stack -> first = ptr0;
	stack -> last = ptr0;
	ptr1 = stack -> first;
	while (i < len)
	{
		ptr = new_element(nums[i], stack -> last);
		if (!ptr)
			return (-1);
		ptr1 -> next = ptr0;
		ptr1 = ptr1 -> next;
		stack -> last = ptr0;
		i++;
	}
	return (1);
}

void	stack_init_empty(t_stack *stack)
{
	stack -> first = NULL;
	stack -> last = NULL;
}

/* Frees an instance of t_stack */
void	free_stack(t_stack *stack)
{
	t_element	*ptr;

	ptr = stack -> head;
	while (ptr -> next)
	{
		ptr = ptr -> next;
		free(ptr -> prev);
	}
	free(ptr);
	free(stack);
}
