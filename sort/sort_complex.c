/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:10:01 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:10:02 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	write comments
*/

// --- define ---

void	sort_complex(t_stack_machine *machine)
{
	int	len;

	len = machine -> stacks[0].len;
	if (len == 3)
		return ((void)(anysort_sort_three(machine)));
	if (len == 4)
		return ((void)(anysort_sort_four(machine)));
	if (len == 5)
		return ((void)(anysort_sort_five(machine)));
	merge_sort(machine);
	return ;
}
