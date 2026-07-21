// --- include ---

#include "./push_swap.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

/* TODO: write comment, norminette check */

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
