/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:40:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/09 13:50:46 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "./push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/stack_machine/stack_machine.h"

// --- define ---

/* Prints out the bench statistics */
void	print_bench(t_stats *stats)
{
	ft_printf("[bench] disorder:  %d.%d%%\n", (int)(stats -> disorder), \
	(int)(stats -> disorder * 100));
	ft_printf("[bench] strategy:  %s\n", stats -> strategy);
	ft_printf("[bench] total_ops:  %u\n", stats -> total_ops);
	ft_printf("[bench] sa:  %u  sb:  %u  ss:  %u,  pa:  %u,  pb:  %u\n", \
	(stats -> calls)[0], (stats -> calls)[1], (stats -> calls)[2], \
	(stats -> calls)[3], (stats -> calls)[4]);
	ft_printf("[bench] ra:  %u  rb:  %u  rr:  %u,  rra:  %u,  rrb:  %u  " \
	"rrr:  %u\n", (stats -> calls)[5], (stats -> calls)[6], \
	(stats -> calls)[7], (stats -> calls)[8], (stats -> calls)[9], \
	(stats -> calls)[10]);
}
