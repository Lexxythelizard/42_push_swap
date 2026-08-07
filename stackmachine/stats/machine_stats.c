/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_stats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:01:25 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:01:27 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include <stddef.h>
#include "./stats.h"

// --- DOC --

/*
	this file cntains a function which just initializes an 
	empty stats instance :)
*/

// --- define ---

/* Initialises the empty stats */

int	stats_init_empty(t_stats *stats)
{
	int	i;

	i = 0;
	if (!stats)
		return (-1);
	while (i++ < OPS_N)
		stats -> calls[(i - 1)] = 0;
	stats -> total_ops = 0;
	stats -> entropy = 0.0f;
	stats -> strategy = NULL;
	return (0);
}
