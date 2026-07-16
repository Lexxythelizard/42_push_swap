// --- icludes ---

#include <stdlib.h>
#include "test_helper.h"
#include "../stackmachine/stats/stats.h"

// --- DOC ---

/*
	define all test functions needed to test all the stats functions
*/

// --- prototype ---

// this file

t_stats	create_stats_init_empty(void);

// --- define ---

t_stats	create_stats_init_empty(void)
{
	t_stats	new;

	stats_init_empty(&new);
	return (new);
}
