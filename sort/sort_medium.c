/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:13:00 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:13:03 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./sort.h"

// --- define ---

void	sort_medium(t_stack_machine *machine)
{
	int		len;
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	len = stack_a -> len;
	if (len == stack_count_ascending_in_range(stack_a, 0, len))
		return ;
	bucket_sort_adaption(machine);
	return ;
}
