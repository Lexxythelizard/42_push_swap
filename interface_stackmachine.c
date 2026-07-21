// --- include ---

#include "./push_swap.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

int	machine_set(t_stack_machine *machine, const char **argv, int argc);

// --- define ---

/* TODO: write comment, norminette check */

int	machine_set(t_stack_machine *machine, const char **argv, int argc)
{
	int		*arr;
	int		len;
	int		flag_val;
	int		bench;
	float	entro;

	len = count_valid_numbers(argv, argc);
	arr = get_int_list(argv, argc);
	flag_val = get_flag_values(argv, argc);
	bench = 0;
	entro = calculate_entropy(arr, len);

	machine_init_new_empty(machine);
	machine_func_assign(machine);
	machine_assign_entropy(machine, entro);
	machine_stack_init(machine, arr, len);
	bench = 16 * (flag_val / 16);

	free(arr);

	return (bench + machine_assign_strategy(machine, flag_val));
}
