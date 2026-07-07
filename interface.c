/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:37:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/07 16:41:15 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"

/* Initialises the interface, containing a filled stack a from argv and an
   empty stack b, the stack methods and an optional variable stats */

t_interface	*init(const char **argv)
{
	int			*nums;
	int			nums_len;
	t_interface	*rtrn;

	rtrn = ft_calloc(1, sizeof(t_interface));
	if (!rtrn)
		return (NULL);
	nums_len = count_numbers(argv);
	nums = get_int_list(argv);
	if (!nums)
		return (NULL);
	if (!(is_numbers_unique(nums, nums_len)))
	{
		free(nums);
		return (NULL);
	}
	stacks_init(rtrn, nums, nums_len);
	func_init(rtrn);
	free(nums);
	return (rtrn);
}

void	stacks_init(t_interface *c, int *nums, int len)
{
	// c -> stacks = ft_calloc(1, 16);
	stack_init(&(c -> stacks[0]), nums, len);
	stack_init(&(c -> stacks[1]), NULL, 0);
}

void	func_init(t_interface *c)
{
	// c -> funcs = ft_calloc(88);
	c -> funcs[0] = func_wrap(&sa, "sa");
	c -> funcs[1] = func_wrap(&sb, "sb");
	c -> funcs[2] = func_wrap(&ss, "ss");
	c -> funcs[3] = func_wrap(&pa, "pa");
	c -> funcs[4] = func_wrap(&pb, "pb");
	c -> funcs[5] = func_wrap(&ra, "ra");
	c -> funcs[6] = func_wrap(&rb, "rb");
	c -> funcs[7] = func_wrap(&rr, "rr");
	c -> funcs[8] = func_wrap(&rra, "rra");
	c -> funcs[9] = func_wrap(&rrb, "rrb");
	c -> funcs[10] = func_wrap(&rrr, "rrr");
}

/* Initialises the stats, to be called if a --bench flag is present */
void	stats_init(t_interface *c, int flag)
{
	c -> stats = ft_calloc(1, sizeof(t_stats));
	c -> stats -> disorder = compute_disorder((c -> stacks)[0]-> head);
	// c -> stats -> calls = ft_calloc(44);
	if (flag == 0)
		c -> stats -> strategy = "Simple " SIMPLE;
	else if (flag == 1)
		c -> stats -> strategy = "Medium " MEDIUM;
	else if (flag == 2)
		c -> stats -> strategy = "Complex " COMPLEX;
	else
	{
		if (c -> stats -> disorder < 0.2)
			c -> stats -> strategy = "Adaptive " SIMPLE;
		else if (c -> stats -> disorder < 0.5)
			c -> stats -> strategy = "Adaptive " MEDIUM;
		else
			c -> stats -> strategy = "Adaptive " COMPLEX;
	}
}

/* Creates an instance of t_func from a function pointer and a function name */
t_func	func_wrap(void (*f)(t_interface *), char *name)
{
	t_func	rtrn;

	// rtrn = ft_calloc(16);
	rtrn.f = f;
	rtrn.name = name;
	return (rtrn);
}
