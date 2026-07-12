// --- icludes ---

#include "push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/stack_machine/stack_machine.h"

// --- DOC ---

/*
	TODO:	test calculate_entropy
*/

// --- prototype ---

// --- define ---

float	calculate_entropy(int *arr, int len)
{
	int	non_asc;
	int	checked_pairs;
	int	i;
	int	j;

	if ((!arr) || (len == 0))
		return (-1.00);
	if (len == 1)
		return (0.00);
	non_asc = 0;
	checked_pairs = 0;
	i = 0;
	while ((i + 1) < len)
	{
		j = i + 1;
		while (j < len)
		{
			non_asc += (arr[i] > arr[j]);
			j++;
			checked_pairs++;
		}
		i++;
	}
	return ((float)(non_asc) / (float)(checked_pairs));
}
