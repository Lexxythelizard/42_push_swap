/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:49:28 by rcollet           #+#    #+#             */
/*   Updated: 2026/06/04 17:30:33 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TODO: Handle malloc errors (preferably within the 25 lines) */

/* Initialises a t_stack instance from a list of numbers */
t_stack	*stack_init(int	*nums, size_t len)
{
	t_stack			*rtrn;
	t_stack_frame	*tmp;

	tmp = NULL;
	rtrn = malloc(16);
	if (!rtrn)
		return (NULL);
	if (nums)
		tmp = malloc(16);
	rtrn -> tail = tmp;
	while (tmp && len--)
	{
		tmp -> val = nums[len]
		tmp -> prev = malloc(16);
		if (!(tmp -> prev))
			return (clear_stack(&rtrn));
		tmp -> prev -> next = tmp; 
		tmp = tmp -> prev;	
	}
	rtrn -> head = tmp;
	rtrn -> head -> prev = NULL;
	rtrn -> tail -> next = NULL;
	return (rtrn);
}

/* Swap first two elements of c */
void	s(t_stack *c)
{
	if (!(c -> head) || !(c -> head -> next))
		return ;
	c -> head = c -> head -> next;
	c -> head -> prev -> next = c -> head -> next;
	c -> head -> next -> prev = c -> head -> prev;
	c -> head -> next = c -> head -> prev;
	c -> head -> next -> prev = c -> head;
	c -> head -> prev = NULL;
	if (c -> head == c -> tail)
		c -> tail = c -> head -> next;
}

/* Push first element of d on top of c */
void	p(t_stack *c, t_stack *d)
{
	if (!(d -> head))
		return ; 
	if (!(c -> head))
	{
		c -> head = d -> head;
		c -> tail = c -> head;
		d -> head = d -> head -> next;
		c -> head -> next = NULL;
	}
	else
	{
		c -> head -> prev = d -> head;
		d -> head = d -> head -> next;
		c -> head -> prev -> next = c -> head;
		c -> head = c -> head -> prev;
	}
	if (d -> head)
		d -> head -> prev = NULL;
	else
		d -> tail = NULL;
}

/* rotate upwards one step */
void	r(t_stack *c)
{
	if (!(c -> head) || !(c -> head -> next))
		return ;
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
	if (!(c -> head) || !(c -> head -> next))
		return ;
	c -> head -> prev = c -> tail;
	c -> tail -> next = c -> head;
	c -> head = c -> tail;
	c -> tail = c -> tail -> prev;
	c -> tail -> next = NULL;
	c -> head -> prev = NULL;
}
