// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
	meta file for utility array handling functions 
	for bucket sort adaption
*/

// --- define ---

/*
this function returns a NULL terminated array of pointers
to interger arrays which contain the sorted vaules of each bucket

counld be used like an two dimensiional array
*/

int	**get_pre_sorted_buckets_as_arrays(
		t_stack_machine *machine,
		int buckets,
		int rest)
{
	int	*arr_int;
	int	**arr_arr_int;

	arr_int = arr_int_get_presorted(machine);
	if (!arr_int)
		return (NULL);
	arr_arr_int = arr_arr_int_fill_buckets(
			arr_int,
			buckets,
			rest);
	free(arr_int);
	if (!arr_arr_int)
		return (NULL);
	return (arr_arr_int);
}

/*
frees an NULL terminated array of pointers to integer arrays
*/

int	**arr_arr_int_free(int **arr_arr_int)
{
	int	i;

	i = 0;
	while (arr_arr_int[i])
	{
		free(arr_arr_int[i]);
		i++;
	}
	free(arr_arr_int);
	return (NULL);
}

/*
credits to mira :)
*/

float	get_sqrt(int x)
{
	double	guess;
	int		i;

	if (x < 0)
		return (-1);
	if (x == 0)
		return (0);
	guess = x;
	i = 0;
	while (i < 30)
	{
		guess = (guess + x / guess) / 2.0;
		i++;
	}
	return (guess);
}
