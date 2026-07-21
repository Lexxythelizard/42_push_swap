// --- include ---

#include "./sort.h"

// for test
#include <stdio.h>

// --- DOC ---

/*
TODO:	test edge cases, remove printf debugging
*/

// --- define ---

/*

// bubble_sort adption: lexxy_standard_sort

void	lexxy_standard_sort(int *arr, int len)
{
	int i;
	int j;

	i = 0;
	while ((i + 1) < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
				swap(&(arr[i]), &(arr[j]));
			j++;
		}
		i++;
	}
}

void	selection_sort(int *arr, int len)
{
	int	idx_min;
	int	cur_min;
	int	i;
	int	j;

	i = 0;
	while((i + 1) < len)
	{
		cur_min = arr[i];
		j = i + 1;
		while(j < len)
		{
			if (arr[j] < cur_min)
				idx_min = arr[j];
			cur_min = arr[idx_min];
			j++;
		}
		swap(&(arr[j]), &(arr[idx_min]));
		i++;
	}
}

void	min_extraction_sort(int *arr, int len)
{
	int	*temp;

	if ((!arr) || (len == 0))
		return ;
	temp = malloc(len * size_of(int));
	if (!temp)
		return ;

	i = 0;
	
	while (i < len)
		if (arr[])
}

void	swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

*/

void	sort_simple(t_stack_machine *machine)
{
	t_element	*cursor;

	printf("test simple\n");
	printf("elements sorted:\t%d\n",
		min_extraction_adaption_sort(machine));
	printf("stack a:\n");
	cursor = machine -> stacks[0].first;
	while (cursor)
	{
		printf("%d\n", cursor -> val);
		cursor = cursor -> next;
	}
	return ;
}
