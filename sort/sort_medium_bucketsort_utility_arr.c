// --- icludes ---

#include "./sort.h"

// test

// --- DOC ---

/*
TODO: test
*/

// --- prototype ---

static int	*get_array_from_stack_a(t_stack_machine *machine);
static void	standart_lexxy_sort(int *arr, int len);
static void	swap_int(int *a, int *b);

// --- define ---

/*
comment
*/

int	*arr_int_get_presorted(
		t_stack_machine *machine)
{
	int			*arr;
	int			len;
	t_element	*element;

	len = machine -> stacks[0].len;
	element = machine -> stacks[0].first;
	arr = get_array_from_stack_a(machine);
	if (!arr)
		return (NULL);
	standart_lexxy_sort(arr, len);
	return (pre_sorted_buckets);
}

static int	*get_array_from_stack_a(
		t_stack_machine *machine)
{
	int			*arr;
	int			len;
	t_element	*element;

	len = machine -> stacks[0].len;
	arr = malloc(len * sizeof(int));
	element = machine -> stacks[0].first;
	if (!arr)
		return (NULL);
	while (element < len)
	{
		arr[i] = elment -> val;
		element = element -> next;
		i++;
	}
	return (arr);
}

static void	standart_lexxy_sort(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;

	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
				swap_int(&(arr[i]), &(arr[j]));
			j++;
		}
		i++;
	}
}

static void	swap_int(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}
