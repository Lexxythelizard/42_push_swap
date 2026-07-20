// --- include ---

#include "./ui.h"

// --- define ---

int	is_args_valid(const char **argv, int argc)
{
	int	i;
	int	flags;

	if (argc < 2)
		return (0);
	i = 1;
	flags = count_repitition_of_flags(argv, argc);
	i += flags;
	while (i < argc)
	{
		if (!(is_valid_nbr(argv[i])))
			return (0);
		i++;
	}
	if (flags == 2)
		return (is_unique_and_one_bench(argv, argc));
	return (1);
}
