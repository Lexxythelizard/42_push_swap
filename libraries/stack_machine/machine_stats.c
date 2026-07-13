// --- include ---

#include "./stackmachine.h"

// --- DOC --

/*
TODO:   - reimplement from scratch
		- source out func_ functions
		- source out stats_ functions
*/

// --- proto --- for tests

int	stats_init_by_flag(t_stats *stats, int flag_val);
int	stats_init_by_entropy(t_stats *stats);
int	stats_init_empty(t_stats *stats);

// --- define ---

/* Initialises the stats, to be called if a --bench flag is present */
int	stats_init_by_flag(t_stats *stats, int flag_val)
{
	if (!stats)
		return (-1);
	flag_val %= BENCH_VAL;
	if (flag_val / ADAPTIVE_VAL)
		stats -> strategy = ADAPTIVE_STR;
	flag_val %= ADAPTIVE_VAL;
	if (flag_val == 0)
		return (ADAPTIVE_VAL);
	if (flag_val / COMPLEX_VAL)
		stats -> strategy = COMPLEX_STR;
	flag_val %= COMPLEX_VAL;
	if (flag_val == 0)
		return (COMPLEX_VAL);
	if (flag_val / MEDIUM_VAL)
		stats -> strategy = MEDIUM_STR;
	flag_val %= MEDIUM_VAL;
	if (flag_val == 0)
		return (MEDIUM_VAL);
	if (flag_val / SIMPLE_VAL)
		stats -> strategy = SIMPLE_STR;
	flag_val %= SIMPLE_VAL;
	if (flag_val == 0)
		return (SIMPLE_VAL);
	return (0);
}

int	stats_init_by_entropy(t_stats *stats)
{
	if (!stats)
		return (-1);
	if (stats -> entropy > COMPLEX_ENTRO)
		stats -> strategy = COMPLEX_STR;
	else if (stats -> entropy > MEDIUM_ENTRO)
		stats -> strategy = MEDIUM_STR;
	else if (stats -> entropy > SIMPLE_ENTRO)
		stats -> strategy = SIMPLE_STR;
	else
		stats -> strategy = DONE_STR;
	if (stats -> startegy == COMPLEX_STR)
		return (COMPLEX_VAL);
	if (stats -> startegy == MEDIUM_STR)
		return (MEDIUM_VAL);
	if (stats -> startegy == SIMPLE_STR)
		return (SIMPLE_VAL);
	return (0);
}

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
	stats -> strategy = DEF_STR;
	return (0);
}
