/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:57:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/27 12:58:58 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// === Check for duplicate values: unclear what you want me todo.... ===
//	--> implemented four versions

/*
	- chould check if there are double values 
	- works with any node, checks in both direction if it finds duplicates 
	- O(n)
*/

int	lxy_has_duplicate_values(t_stack_frame *node)
{
	t_stack_frame	*ptr;

	ptr = node;
	while (ptr -> next != NULL)
	{
		ptr = ptr -> next;
		if (ptr -> value == node -> value)
			return (1);
	}
	ptr = node;
	while (ptr -> prev != NULL)
	{
		ptr = ptr -> prev;
		if (ptr -> value == node -> value)
			return (1);
	}
	return (0);
}

/*
make sure to parse the first node / element in stack as argument
itterates through the list from up to down to check 
if there are any duplicates

nested while loop	--> O(n^2)
*/

int	lxy_is_doupled_values(t_stack_frame *first_node)
{
	t_stack_frame	*ptr_a;
	t_stack_frame	*ptr_b;

	ptr_a = first_node;
	if (!(ptr_a))
		return (-1);
	while (ptr_a -> next != NULL)
	{
		ptr_b = ptr_a -> next;
		if (ptr_b -> value == ptr_a -> value)
			return (1);
		while (ptr_b -> next != NULL)
		{
			ptr_b = ptr_b -> next;
			if (ptr_b -> value == ptr_a -> value)
				return (1);
		}
		ptr_a = ptr_a -> next;
	}
	return (0)
}

t_stack_frame	*lxy_get_duplicate_down(t_stack_frame *node)
{
	t_stack_frame	*ptr;

	ptr = node;
	while (ptr -> next != NULL)
	{
		ptr = ptr -> next;
		if (ptr -> value == node -> value)
			return (ptr);
	}
	return (node);
}

t_stack_frame	*lxy_get_duplicate_up(t_stack_frame *node)
{
	t_stack_frame	*ptr;

	ptr = node;
	while (ptr -> prev != NULL)
	{
		ptr = ptr -> prev;
		if (ptr -> value == node -> value)
			return (ptr);
	}
	return (node);
}
