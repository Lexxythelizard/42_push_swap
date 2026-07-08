/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/08 20:37:56 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

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

void	exec(t_stack_machine *machine, int idx)
{
	if (machine -> stats)
	{
		(machine -> stats -> calls)[idx]++;
		machine -> stats -> total_ops++;
	}
	((machine -> funcs)[idx].f)(machine);
	ft_putendl_fd((machine -> funcs)[idx].name, 1);
}

/* calls exec(stats, idx) n times */
void	exec_n(t_stack_machine *machine, int idx, int n)
{
	while (n--)
		exec(machine, idx);
}
