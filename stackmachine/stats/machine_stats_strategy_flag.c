// --- include ---

#include "./stats.h"

// --- DOC --

/*
	this file contains the function(s) to assign the strategy by 
	processing the flag value

	after assigning the flag value the matching key will be returned
*/

// --- proto --- for tests

static int	stats_assign_adaptive_if_adaptive(t_stats *stats, int *flag_val);
static int	stats_assign_complex_if_complex(t_stats *stats, int *flag_val);
static int	stats_assign_medium_if_medium(t_stats *stats, int *flag_val);
static int	stats_assign_simple_if_simple(t_stats *stats, int *flag_val);

// --- define ---

/*
assign strategy by flag value:
bench value have no effect on the result:
	example 20 % BENCH_VAL = COMPLEX_VAL
	example 18 % BENCH_VAL = MEDIUM_VAL
	...

returns the matching flag key after {8, 4, 2, 1, 0} 
after assigning the strategy
*/

int	stats_assign_strategy_by_flag(t_stats *stats, int flag_val)
{
	if (!stats)
		return (-1);
	flag_val %= BENCH_VAL;
	if (flag_val == 0)
		return (0);
	if (stats_assign_adaptive_if_adaptive(stats, &flag_val))
		return (ADAPTIVE_VAL);
	if (stats_assign_complex_if_complex(stats, &flag_val))
		return (COMPLEX_VAL);
	if (stats_assign_medium_if_medium(stats, &flag_val))
		return (MEDIUM_VAL);
	if (stats_assign_simple_if_simple(stats, &flag_val))
		return (SIMPLE_VAL);
	return (0);
}

static int	stats_assign_adaptive_if_adaptive(t_stats *stats, int *flag_val)
{
	if (*flag_val / ADAPTIVE_VAL)
		stats -> strategy = ADAPTIVE_STR;
	*flag_val %= ADAPTIVE_VAL;
	return (*flag_val == 0);
}

static int	stats_assign_complex_if_complex(t_stats *stats, int *flag_val)
{
	if (*flag_val / COMPLEX_VAL)
		stats -> strategy = COMPLEX_STR;
	*flag_val %= COMPLEX_VAL;
	return (*flag_val == 0);
}

static int	stats_assign_medium_if_medium(t_stats *stats, int *flag_val)
{
	if (*flag_val / MEDIUM_VAL)
		stats -> strategy = MEDIUM_STR;
	*flag_val %= MEDIUM_VAL;
	return (*flag_val == 0);
}

static int	stats_assign_simple_if_simple(t_stats *stats, int *flag_val)
{
	if (*flag_val / SIMPLE_VAL)
		stats -> strategy = SIMPLE_STR;
	*flag_val %= SIMPLE_VAL;
	return (*flag_val == 0);
}
