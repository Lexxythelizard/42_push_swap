/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:40:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/02 18:33:25 by rcollet          ###   ########.fr       */
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
	ft_printf("[bench] total_ops:  %u\n", track -> total_ops);
	ft_printf("[bench] sa:  %u  sb:  %u  ss:  %u,  pa:  %u,  pb:  %u\n", \
	(track -> calls)[0], (track -> calls)[1], (track -> calls)[2], \
	(track -> calls)[3], (track -> calls)[4]);
	ft_printf("[bench] ra:  %u  rb:  %u  rr:  %u,  rra:  %u,  rrb:  %u  " \
    "rrr:  %u\n", (track -> calls)[5], (track -> calls)[6], \
	(track -> calls)[7], (track -> calls)[8], (track -> calls)[9], \
	(track -> calls)[10]);
}
