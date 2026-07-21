// --- include ---

#include "./push_swap.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- DOC ---

/*
	... your comment here ...
*/

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
