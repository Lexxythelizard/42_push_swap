/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_benchmarks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:09:47 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:09:48 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "./sort.h"
#include "../stackmachine/machine.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- define ---

/*
Prints out the bench statistics
*/

void	print_bench(t_stack_machine *machine)
{
	t_stats	*stats;
	int		pre_comma;
	int		post_comma;

	stats = &(machine -> stats);
	pre_comma = (int)(stats -> entropy * 100);
	post_comma = (int)(stats -> entropy * 10000) % 100;
	ft_printf("[bench] disorder:  %d.%d%%\n", pre_comma, post_comma);
	ft_printf("[bench] strategy:  %s\n", stats -> strategy);
	ft_printf("[bench] total_ops:  %u\n", stats -> total_ops);
	ft_printf("[bench] sa:  %u  sb:  %u  ss:  %u,  pa:  %u,  pb:  %u\n",
		(stats -> calls)[SA], (stats -> calls)[SB], (stats -> calls)[SS],
		(stats -> calls)[PA], (stats -> calls)[PB]);
	ft_printf("[bench] ra:  %u  rb:  %u  rr:  %u",
		(stats -> calls)[RA], (stats -> calls)[RB], (stats -> calls)[RR]);
	ft_printf(",  rra:  %u,  rrb:  %u,  rrr:  %u\n",
		(stats -> calls)[RRA], (stats -> calls)[RRB], (stats -> calls)[RRR]);
}
