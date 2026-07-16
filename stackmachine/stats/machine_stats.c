// --- include ---

#include <stddef.h>
#include "./stats.h"

// --- DOC --

/*
TODO:   - test
*/

// --- proto --- for tests

int	stats_init_empty(t_stats *stats);

// --- define ---

/* Initialises the stats, to be called if a --bench flag is present */

int	stats_init_empty(t_stats *stats)
{
	int	i;

	i = 0
	if (!stats)
		return (-1);
	while (i++ < OPS_N)
		stats -> calls[(i - 1)] = 0;
	stats -> total_ops = 0;
	stats -> disorder = 0.00;
	stats -> strategy = NULL;
	return (0);
}
