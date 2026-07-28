/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
	this file contains functions to get a pre sorted 1D array
*/

// --- prototype ---

static int	*get_array_from_stack_a(t_stack_machine *machine);
static void	standart_lexxy_sort(int *arr, int len);
static void	swap_int(int *a, int *b);

// --- define ---

/*
extracts all the values of stack a and returns a pre sorted array
*/

int	*arr_int_get_presorted(
		t_stack_machine *machine)
{
	int			*arr_int;
	int			len;

	len = machine -> stacks[0].len;
	arr_int = get_array_from_stack_a(machine);
	if (!arr_int)
		return (NULL);
	standart_lexxy_sort(arr_int, len);
	return (arr_int);
}

/*
just gets the array fro stack a
*/

static int	*get_array_from_stack_a(
		t_stack_machine *machine)
{
	int			*arr;
	int			len;
	int			i;
	t_element	*element;

	i = 0;
	len = machine -> stacks[0].len;
	arr = malloc(len * sizeof(int));
	element = machine -> stacks[0].first;
	if (!arr)
		return (NULL);
	while ((element) && (i < len))
	{
		arr[i] = element -> val;
		element = element -> next;
		i++;
	}
	return (arr);
}

/*
lexxy's standart sort :)
*/

static void	standart_lexxy_sort(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while ((i + 1) < len)
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

/*
self explaining
*/

static void	swap_int(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}
