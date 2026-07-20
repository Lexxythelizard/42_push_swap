#ifndef FUNCS_H
# define FUNCS_H

// --- makros ---

# define SA_STR "sa"
# define SB_STR "sb"
# define SS_STR "ss"
# define PA_STR "pa"
# define PB_STR "pb"
# define RA_STR "ra"
# define RB_STR "rb"
# define RR_STR "rr"
# define RRA_STR "rra"
# define RRB_STR "rrb"
# define RRR_STR "rrr"

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

// --- proto for define ---

struct	s_stack_machine;

// --- structs ---

typedef struct s_func
{
	int		(*func)(struct s_stack_machine *machine);
	char	*name;
}			t_func;

// --- prototypes ---

int	func_init_empty(t_func *func_obj);
int	func_init(t_func *func_obj,
		int (*f)(struct s_stack_machine *machine), char *name);

// --- end ---

#endif
