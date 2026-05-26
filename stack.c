/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:49:28 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/26 13:02:30 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TODO: Handle malloc errors (preferably within the 25 lines) */

/* Initialises a t_stack instance from a list of numbers */
t_stack	*stack_init(int	*nums, size_t len)
{
	t_stack			*rtrn;
	t_stack_frame	*tmp;

	rtrn = malloc(16);
	rtrn -> head = NULL;
	rtrn -> tail = NULL;
	while (len--)
	{
		if (!tmp)
			tmp = malloc(16);
		else
		{
			tmp -> prev = malloc(16);
			tmp -> prev -> next = tmp; 
			tmp = tmp -> prev;
		}
		tmp -> val = nums[len]
		if (!head)
			rtrn -> tail = tmp;
	}
	rtrn -> head = tmp;
	rtrn -> head -> prev = NULL;
	rtrn -> tail -> next = NULL;
	return (rtrn);
}

/* Swap first two elements of c */
void	s(t_stack *c)
{
	c -> head = c -> head -> next;
	c -> head -> prev -> next = c -> head -> next;
	c -> head -> next -> prev = c -> head -> prev;
	c -> head -> next = c -> head -> prev;
	c -> head -> next -> prev = c -> head;
	c -> head -> prev = NULL;
}

/* Push first element of d on top of c */
void	p(t_stack *c, t_stack *d)
{
	c -> head -> prev = d -> head;
	d -> head = d -> head -> next;
	c -> head -> prev -> next = c -> head;
	c -> head = c -> head -> prev;
	d -> head -> prev = NULL;
}

/* rotate upwards one step */
void	r(t_stack *c)
{
	c -> tail -> next = c -> head;
	c -> head -> prev = c -> tail;
	c -> tail = c -> head;
	c -> head = c -> head -> next;
	c -> head -> prev = NULL;
	c -> tail -> next = NULL;
}

/* rotate downwards one step */
void	rr(t_stack *c)
{
	c -> head -> prev = c -> tail;
	c -> tail -> next = c -> head;
	c -> head = c -> tail;
	c -> tail = c -> tail -> prev;
	c -> tail -> next = NULL;
	c -> head -> prev = NULL;
}
