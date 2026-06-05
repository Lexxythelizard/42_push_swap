/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/05 15:36:25 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "ft_printf.h"
#include "push_swap.h"

// --- DOC ---

// --- proto ---

// --- define ---

/* executes one of the stack methods and puts down its name, changes the stats
   if needed. The methods are indexed as follows:
   0: sa
   1: sb
   2: ss
   3: pa
   4: pb
   5: ra
   6: rb
   7: rr
   8: rra
   9: rrb
   10: rrr */

void	exec(t_interface *stacks, int idx)
{
	if (stacks -> stats)
	{
		(stacks -> stats -> calls)[idx]++;
		stacks -> stats -> total_ops++;
	}
	((stacks -> func)[idx] -> f)(stacks)
	ft_putendl((stacks -> func)[idx] -> name, 1);
}

/* calls exec(stats, idx) n times */
void	exec_n(t_interface *stacks, int idx, int n)
{
	while (n--)
		exec(stacks, tracker, idx);
}
