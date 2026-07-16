#ifndef FUNCS_H
# define FUNCS_H

// --- makros ---

# define FUNC_NAME "default"

# define FUNC_VAL 7

// --- structs ---

typedef struct s_func
{
	void	(*f)(struct s_stack_machine *machine);
	char	*name;
}			t_func;

// --- prototypes ---

// --- end ---

#endif
