// --- include ---

#include "./funcs.h"
#include <stddef.h>

// --- DOC --

/*
	this file contains functions to init t_func instances
*/

// --- define ---

/*
inits an empty instance of t_func
*/

int	func_init_empty(t_func *func_obj)
{
	if (!func_obj)
		return (-1);
	func_obj -> func = NULL;
	func_obj -> name = NULL;
	return (0);
}

/*
inits an instance of t_func from a function pointer and a function name
*/

int	func_init(t_func *func_obj,
	int (*f)(struct s_stack_machine *machine), char *name)
{
	if (!func_obj)
		return (-1);
	if ((!f) || (!name))
		return (0);
	func_obj -> func = f;
	func_obj -> name = name;
	return (1);
}
