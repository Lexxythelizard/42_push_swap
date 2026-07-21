// --- icludes ---

#include "./push_swap.h"
#include "./libraries/ft_printf/ft_printf.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

void	run_sort(t_stack_machine *machine, int flag_val)
{
	int	bench;

	bench = (int)(flag_val / BENCH_VAL);
	flag_val %= BENCH_VAL;
	if ((int)(flag_val / ADAPTIVE_VAL))
		sort_adaptive(machine);
	else if ((int)(flag_val / COMPLEX_VAL))
		sort_complex(machine);
	else if ((int)(flag_val / MEDIUM_VAL))
		sort_medium(machine);
	else if (flag_val == SIMPLE_VAL)
		sort_simple(machine);
	if (bench)
	{
		ft_printf("test bench\n");
		print_bench(machine);
	}
}
