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
	this file contains the writing and allocating of the "2D Array" 
	which is meant to be a map of sorted buckets.
*/

// --- prototype ---

static int	**arr_arr_int_fill_full_buckets(
				int **arr_arr_int,
				int *pre_sorted_arr,
				int full_buckets);

static int	**arr_arr_int_fill_rest_bucket(
				int **arr_arr_int,
				int *pre_sorted_arr,
				int full_buckets,
				int rest);

static int	**arr_arr_int_init_new(
				int buckets);

static int	*copy_sequence(
				int *src_arr,
				int start,
				int size);

// --- define ---

/*
needs a pre sorted array 1D, the number of buckets 
(included the last, not full bucket) and its filling: rest

returns a "2D Array" actually not a real one, but you can handle it like one
*/

int	**arr_arr_int_fill_buckets(
		int *pre_sorted_arr,
		int buckets,
		int rest)
{
	int	**arr_arr_int;
	int	full_buckets;

	full_buckets = buckets - (rest > 0);
	arr_arr_int = arr_arr_int_init_new(
			buckets);
	if (!arr_arr_int)
		return (NULL);
	arr_arr_int = arr_arr_int_fill_full_buckets(
			arr_arr_int,
			pre_sorted_arr,
			full_buckets);
	if (!arr_arr_int)
		return (NULL);
	arr_arr_int = arr_arr_int_fill_rest_bucket(
			arr_arr_int,
			pre_sorted_arr,
			full_buckets,
			rest);
	if (!arr_arr_int)
		return (NULL);
	return (arr_arr_int);
}

/*
takes the empty "2D Array", the pre sorted array 
and the number of full buckets (wihout the rest)

fills buckets one by one and returns a 
pointer to the first element of "2D Array"

frees and returns NULL if an error occures
*/

static int	**arr_arr_int_fill_full_buckets(
				int **arr_arr_int,
				int *pre_sorted_arr,
				int full_buckets)
{
	int	*temp;
	int	i;
	int	start;
	int	bucket_size;

	i = 0;
	bucket_size = full_buckets;
	while (i < full_buckets)
	{
		start = bucket_size * i;
		temp = copy_sequence(pre_sorted_arr, start, bucket_size);
		arr_arr_int[i] = temp;
		if (!temp)
			return (arr_arr_int_free(arr_arr_int));
		i++;
	}
	return (arr_arr_int);
}

/*
takes the empty "2D Array", the pre sorted array 
and the number of full buckets (wihout the rest)
and the rest

fills the last (rest) bucket and returns a 
pointer to the first element of "2D Array"

frees and returns NULL if an error occures
*/

static int	**arr_arr_int_fill_rest_bucket(
			int **arr_arr_int,
			int *pre_sorted_arr,
			int full_buckets,
			int rest)
{
	int	*temp;
	int	start;

	if (rest == 0)
		return (arr_arr_int);
	start = full_buckets * full_buckets;
	temp = copy_sequence(pre_sorted_arr, start, rest);
	if (!temp)
		return (arr_arr_int_free(arr_arr_int));
	arr_arr_int[full_buckets] = temp;
	return (arr_arr_int);
}

/*
takes the number of all buckets (incl rest bucket) 
to allocate, first dimension of the "2D Array"
and NULL terminates it.
returns a pointer to the new allocated "2D Array"

frees and returns NULL if an error occures
*/

static int	**arr_arr_int_init_new(
				int buckets)
{
	int	**arr_arr_int;
	int	i;

	i = 0;
	arr_arr_int = malloc((buckets + 1) * sizeof(int *));
	if (!arr_arr_int)
		return (NULL);
	while (i <= buckets)
	{
		arr_arr_int[i] = NULL;
		i++;
	}
	return (arr_arr_int);
}

/*
works like ft_substring, but with an integer array.
returns a pointer to the first element of the new alloated in array
returns NULL if an error occures
*/

static int	*copy_sequence(
				int *src_arr,
				int start,
				int size)
{
	int	*arr;
	int	i;

	i = 0;
	if ((!src_arr) || (size == 0))
		return (NULL);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = src_arr[(start + i)];
		i++;
	}
	return (arr);
}
