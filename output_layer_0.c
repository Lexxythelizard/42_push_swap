/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_layer_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:40:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/02 16:11:31 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"
#include "op_tracker.h"
#include "output.h"

// --- define ---

void print_bench(t_op_track *track, int fd)
{
	ft_printf("[bench] disorder:  %d.%d%%\n", (int)(track -> disorder), \
	(int)(track -> disorder * 100));
	ft_printf("[bench] strategy:  %s\n", track -> strategy);
	ft_printf("[bench] total_ops:  %d\n", track -> total_ops);
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d,  pa:  %d,  pb:  %d\n", \
	track -> sa, track -> sb, track -> ss, track -> pa, track -> pb);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d,  rra:  %d,  rrb:  %d  " \
    "rrr:  %d\n", track -> ra, track -> rb, track -> rr, track -> rra, \
	track -> rrb, track -> rrr);
}
