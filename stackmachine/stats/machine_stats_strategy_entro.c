// --- include ---

#include "./stats.h"

// --- DOC --

/*
	this file contains functions to assign a strategy to stats 
	by processing the entropy
	
	the flag key of the matching strategy will be returned
*/

// --- proto ---

static int	stats_assign_complex_if_complex(t_stats *stats);
static int	stats_assign_medium_if_medium(t_stats *stats);
static int	stats_assign_simple_if_simple(t_stats *stats);

// --- define ---

/*
Assigns stats -> strategy by stats -> entropy

returns:	int		flag value {4, 2, 1, 0}
*/

int	stats_assign_strategy_by_entropy(t_stats *stats)
{
	if (!stats)
		return (-1);
	if (stats_assign_complex_if_complex(stats))
		return (COMPLEX_VAL);
	if (stats_assign_medium_if_medium(stats))
		return (MEDIUM_VAL);
	if (stats_assign_simple_if_simple(stats))
		return (SIMPLE_VAL);
	return (0);
}

static int	stats_assign_complex_if_complex(t_stats *stats)
{
	if (stats -> entropy >= COMPLEX_ENTRO)
		stats -> strategy = COMPLEX_STR;
	return (stats -> entropy >= COMPLEX_ENTRO);
}

static int	stats_assign_medium_if_medium(t_stats *stats)
{
	if (stats -> entropy >= MEDIUM_ENTRO)
		stats -> strategy = MEDIUM_STR;
	return (stats -> entropy >= MEDIUM_ENTRO);
}

static int	stats_assign_simple_if_simple(t_stats *stats)
{
	if (stats -> entropy > NULL_ENTRO)
		stats -> strategy = SIMPLE_STR;
	return (stats -> entropy > NULL_ENTRO);
}

/*
static int	stats_assign_null_if_null(t_stats *stats, int *flag_val)
{
	if (stats -> entropy > COMPLEX_ENTRO)
		stats -> strategy == COMPLEX_STR;
	return (stats -> entropy > COMPLEX_ENTRO);
}
*/
