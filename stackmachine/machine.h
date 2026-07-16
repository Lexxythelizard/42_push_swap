#ifndef MACHINE_H
# define MACHINE_H

// --- include ---

# include "./stack/stack.h"
# include "./stats/stats.h"
# include "./funcs/funcs.h"

// --- makros ---

// --- structs ---

typedef struct s_stack_machine
{
	t_stack	stacks[2];
	t_stats	stats;
	t_func	funcs[11];	
}			t_stack_machine;

// --- prototypes ---

// --- end ---

#endif
