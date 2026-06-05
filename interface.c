/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:37:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/06/05 15:36:57 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialises the interface, containing a filled stack a from argv and an
   empty stack b, the stack methods and an optional variable stats */

t_interface	*init(int argc, char **argv)
{
	int			*nums;
	t_interface	*rtrn;
	
	rtrn = ft_calloc(16);
	if (!rtrn)
		return (NULL);
	nums = get_int_list(argv);
	if (!nums)
		return (NULL);
	rtrn -> stacks = ft_calloc(16);
	rtrn -> stacks[0] = stack_init(nums, argc - 1);
	rtrn -> stacks[1] = stack_init(NULL, 0);
	rtrn -> funcs = ft_calloc(88);
	rtrn -> funcs[0] = func_wrap(&sa, "sa");
	rtrn -> funcs[1] = func_wrap(&sb, "sb");
	rtrn -> funcs[2] = func_wrap(&ss, "ss");
	rtrn -> funcs[3] = func_wrap(&pa, "pa");
	rtrn -> funcs[4] = func_wrap(&pb, "pb");
	rtrn -> funcs[5] = func_wrap(&ra, "ra");
	rtrn -> funcs[6] = func_wrap(&rb, "rb");
	rtrn -> funcs[7] = func_wrap(&rr, "rr");
	rtrn -> funcs[8] = func_wrap(&rra, "rra");
	rtrn -> funcs[9] = func_wrap(&rrb, "rrb");
	rtrn -> funcs[10] = func_wrap(&rrr, "rrr");
	free(nums);
	return (rtrn);
}

/* Initialises the stats, to be called if a --bench flag is present */
void	stats_init(t_interface *c, int flag)
{
	c -> stats = ft_calloc(32);
	c -> stats -> disorder = compute_disorder((c -> stacks)[0] -> head);
	c -> stats -> calls = ft_calloc(44);
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
t_func	*func_wrap(void (*f)(t_interface *), char *name)
{
	t_func	*rtrn;

	rtrn = ft_calloc(16);
	rtrn -> f = f;
	rtrn -> name = name;
	return (rtrn);
}
