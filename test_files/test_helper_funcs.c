// --- icludes ---

#include <stdlib.h>
#include "test_helper.h"
#include "../stackmachine/funcs/funcs.h"

// --- DOC ---

/*
	define all test functions needed to test all the stats functions
*/

// --- prototype ---

// this file

t_func	create_funcs_init_empty(void);

// --- define ---

t_func	create_funcs_init_empty(void)
{
	t_func	new;

	func_init_empty(&new);
	return (new);
}
