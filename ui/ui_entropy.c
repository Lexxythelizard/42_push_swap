// --- icludes ---

#include "./ui.h"

// --- DOC ---

/*
	TODO:	test calculate_entropy
*/

// --- define ---

float	calculate_entropy(int *arr, int len)
{
	int	non_asc;
	int	checked_pairs;
	int	i;
	int	j;

	if ((!arr) || (len == 0))
		return (-1);
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
	if ((len == 1) || (non_asc == 0))
		return (0);
	return ((float)(non_asc) / checked_pairs);
}
