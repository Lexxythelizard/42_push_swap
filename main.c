// --- include ---

#include "./push_swap.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

int	ui_validate(const char **argv, int argc);
int	machine_set(t_stack_machine *machine, const char **argv, int argc);

// --- run ---

int	main(int argc, char **argv)
{
	t_stack_machine	machine;
	int				flag_val;

	if (argc < 2)
		return (0);	
	if (!(ui_validate((const char **)(argv), argc)))
		return (put_error());
	flag_val = machine_set(&machine, (const char **)(argv), argc);	
	run_sort(&machine, flag_val);
	machine_free(&machine);
	return (0);
}

// --- define ---

/* TODO: outsource */

int	ui_validate(const char **argv, int argc)
{
	int		*arr;
	int		len;

	if (!(is_args_valid(argv, argc)))
		return (0);

	len = count_valid_numbers(argv, argc);
	if (len == 0)
		return(0);

	arr = get_int_list(argv, argc);
	if (!arr)
		return (0);

	if (!(is_numbers_unique(arr, len)))
	{
		free(arr);
		return (0);
	}

	free(arr);
	return (1);
}

/* TODO: outsource */

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
