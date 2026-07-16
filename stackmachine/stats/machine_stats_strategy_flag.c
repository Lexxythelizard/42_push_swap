// --- include ---

#include "./stats.h"

// --- DOC --

/*
TODO:   - test
*/

// --- proto --- for tests

int	stats_assign_strategy_by_flag(t_stats *stats, int flag_val);

static int	stats_assign_adaptive_if_adaptive(t_stats *stats, int flag_val);
static int	stats_assign_complex_if_complex(t_stats *stats, int flag_val);
static int	stats_assign_medium_if_medium(t_stats *stats, int flag_val);
static int	stats_assign_simple_if_simple(t_stats *stats, int flag_val);

// --- define ---

/*
comment
*/

int	stats_assign_strategy_by_flag(t_stats *stats, int flag_val)
{
	if (!stats)
		return (-1);
	flag_val %= BENCH_VAL;
	if (stats_assign_adaptive_if_adaptive(stats, &flag_val)); 
		return (ADAPTIVE_VAL);
	if (stats_assign_adaptive_if_adaptive(stats, &flag_val)); 
		return (COMPLEX_VAL);
	if (stats_assign_adaptive_if_adaptive(stats, &flag_val)); 
		return (MEDIUM_VAL);
	if (stats_assign_adaptive_if_adaptive(stats, &flag_val)); 
		return (SIMPLE_VAL);
	return (0);
}

static int	stats_assign_adaptive_if_adaptive(t_stats *stats, int *flag_val)
{
	if (*flag_val / ADAPTIVE_VAL)
		stats -> strategy == ADAPTIVE_STR;
	*flag_val %= ADAPTIVE_VAL;
	return (*flag_val == 0);
}

static int	stats_assign_complex_if_complex(t_stats *stats, int *flag_val)
{
	if (*flag_val / COMPLEX_VAL)
		stats -> strategy == COMPLEX_STR;
	*flag_val %= COMPLEX_VAL;
	return (*flag_val == 0);
}

static int	stats_assign_medium_if_medium(t_stats *stats, int *flag_val)
{
	if (*flag_val / MEDIUM_VAL)
		stats -> strategy == MEDIUM_STR;
	*flag_val %= MEDIUM_VAL;
	return (*flag_val == 0);
}

static int	stats_assign_simple_if_simple(t_stats *stats, int *flag_val)
{
	if (*flag_val / SIMPLE_VAL)
		stats -> strategy == SIMPLE_STR;
	*flag_val %= SIMPLE_VAL;
	return (*flag_val == 0);
}
