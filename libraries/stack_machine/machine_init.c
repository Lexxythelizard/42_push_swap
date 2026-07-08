/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:37:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 20:38:52 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

int	machine_init_empty(t_stack_machine *machine)
{
	if (!machine)
		return (0);
	machine -> stack[0].first = NULL;
	machine -> stack[0].last = NULL;
	machine -> stack[1].first = NULL;
	machine -> stack[1].last = NULL;
	machine -> stats = init_empty_stats();
	if (!(machine -> stats))
		return (-1);
	func_init(machine);
}

int	machine_stack_init(t_stack_machine *machine, int *nums, int len)
{
	if (!machine)
		return (0);
	if ((!nums) && (len))
		return (-1);
	if ((!nums) && (!len))
	{
		machine -> stack[0].first = NULL;
		machine -> stack[0].last = NULL;
		return (1);
	}
	if (stack_init(&(machine -> stacks[0]), nums, len) < 0)
	{
		free_stack(&(machine -> stacks[0]));
		return (-1);
	}
	return (1);
}

void	func_init(t_stack_machine *machine)
{
	machine -> funcs[0] = func_wrap(&sa, "sa");
	machine -> funcs[1] = func_wrap(&sb, "sb");
	machine -> funcs[2] = func_wrap(&ss, "ss");
	machine -> funcs[3] = func_wrap(&pa, "pa");
	machine -> funcs[4] = func_wrap(&pb, "pb");
	machine -> funcs[5] = func_wrap(&ra, "ra");
	machine -> funcs[6] = func_wrap(&rb, "rb");
	machine -> funcs[7] = func_wrap(&rr, "rr");
	machine -> funcs[8] = func_wrap(&rra, "rra");
	machine -> funcs[9] = func_wrap(&rrb, "rrb");
	machine -> funcs[10] = func_wrap(&rrr, "rrr");
}

/* Initialises the stats, to be called if a --bench flag is present */
void	stats_init(t_stack_machine *machine, int flag)
{
	machine -> stats = ft_machineallomachine(1, sizeof(t_stats));
	machine -> stats -> disorder = compute_disorder((machine -> stacks)[0]. head);
	if (flag == 0)
		machine -> stats -> strategy = "Simple " SIMPLE;
	else if (flag == 1)
		machine -> stats -> strategy = "Medium " MEDIUM;
	else if (flag == 2)
		machine -> stats -> strategy = "Complex " COMPLEX;
	else
	{
		if (machine -> stats -> disorder < 0.2)
			machine -> stats -> strategy = "Adaptive " SIMPLE;
		else if (machine -> stats -> disorder < 0.5)
			machine -> stats -> strategy = "Adaptive " MEDIUM;
		else
			machine -> stats -> strategy = "Adaptive " COMPLEX;
	}
}

/* Creates an instance of t_func from a function pointer and a function name */
t_func	func_wrap(void (*f)(t_interface *), char *name)
{
	t_func	rtrn;

	rtrn.f = f;
	rtrn.name = name;
	return (rtrn);
}
