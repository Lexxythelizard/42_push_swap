/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 18:22:06 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/09 13:47:38 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/stack_machine/stack_machine.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

void	run_sort(t_interface *stacks, int flag)
{
	int	run_bench;

	run_bench = (int)(flag / 16);
	flag %= 16;
	if ((int)(flag / 8))
		sort_adaptive(stacks);
	else if ((int)(flag / 4))
		sort_adaptive(stacks);
	else if ((int)(flag / 2))
		sort_adaptive(stacks);
	else if (flag == 1)
		sort_adaptive(stacks);
	if (run_bench)
		print_bench(stacks -> stats);
}
