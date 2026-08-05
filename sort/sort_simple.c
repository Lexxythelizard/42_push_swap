/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 2026/08/05 18:53:32 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	rewrite comments
*/

// static void print_stacks(t_stack_machine *machine);

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
	// for testing
	int	len;

	len = machine -> stacks[0].len;
	if (len == 4)
		return ((void)(anysort_sort_four(machine)));
	if (len == 5)
		return ((void)(anysort_sort_five(machine)));
	// test end
	min_extraction_adaption_sort(machine);
	return ;
}

// --- for testing ---
/*
static void print_stacks(t_stack_machine *machine)
{
	int	len_a;
	int	len_b;
	int	i;
	t_element	*element_a;
	t_element	*element_b;

	i = 0;

	len_a = machine -> stacks[0].len;
	len_b = machine -> stacks[1].len;

	element_a = machine -> stacks[0].first;
	element_b = machine -> stacks[1].first;

	printf("stacks: len a: %d\tlen b: %d\n", len_a, len_b);
	while ((len_a - i) > len_b)
	{
		printf("%d\t\t\n", element_a -> val);
		element_a = element_a -> next;
		i++;
	}
	while ((len_b - i) > len_a)
	{
		printf("\t\t%d\n", element_b -> val);
		element_b = element_b -> next;
		i++;
	}
	while ((element_a) && (element_b))
	{
		printf("%d\t\t%d\n", element_a -> val, element_b -> val);
		element_a = element_a -> next;
		element_b = element_b -> next;
	}
	printf("-----------------------------\n");
	printf("a\t\tb\n");
}
*/
