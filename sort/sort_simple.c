/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:13:22 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:13:24 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	rewrite comments
*/

// --- define ---

void	sort_simple(t_stack_machine *machine)
{
	int		len;
	t_stack	*stack_a;

	len = machine -> stacks[0].len;
	stack_a = &(machine -> stacks[0]);
	if (len == stack_count_ascending_in_range(stack_a, 0, len))
		return ;
	if (len == 4)
		return ((void)(anysort_sort_four(machine)));
	if (len == 5)
		return ((void)(anysort_sort_five(machine)));
	min_extraction_adaption_sort(machine);
	return ;
}
