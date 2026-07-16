// --- include ---

#include "./stats.h"

// --- DOC --

/*
TODO:   - test
*/

// --- proto --- for tests

int	stats_assign_strategy_by_entropy(t_stats *stats);

static int	stats_assign_complex_if_complex(t_stats *stats);
static int	stats_assign_medium_if_medium(t_stats *stats);
static int	stats_assign_simple_if_simple(t_stats *stats);

// --- define ---

/*
comment
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
	if (stats -> entro > COMPLEX_ENTRO)
		stats -> strategy == COMPLEX_STR;
	return (stats -> entro > COMPLEX_ENTRO);
}

static int	stats_assign_medium_if_medium(t_stats *stats)
{
	if (stats -> entro > MEDIUM_ENTRO)
		stats -> strategy == MEDIUM_STR;
	return (stats -> entro > MEDIUM_ENTRO);
}

static int	stats_assign_simple_if_simple(t_stats *stats)
{
	if (stats -> entro > SIMPLE_ENTRO)
		stats -> strategy == SIMPLE_STR;
	return (stats -> entro > SIMPLE_ENTRO);
}

/*
static int	stats_assign_null_if_null(t_stats *stats, int *flag_val)
{
	if (stats -> entro > COMPLEX_ENTRO)
		stats -> strategy == COMPLEX_STR;
	return (stats -> entro > COMPLEX_ENTRO);
}
*/
