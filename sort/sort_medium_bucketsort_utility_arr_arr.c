// --- icludes ---

#include "./sort.h"

// test

// --- DOC ---

/*
TODO: test
*/

// --- prototype ---

static int	**arr_arr_int_fill_full_buckets(
				int **arr_arr_int,
				int	*pre_sorted_arr,
				int	full_buckets);

static int	**arr_arr_int_fill_rest_bucket(
				int **arr_arr_int,
				int	*pre_sorted_arr,
				int	len,
				int	rest);

static int	**arr_arr_int_init_new(
				int buckets);

static int	*copy_sequence(
				int *src_arr,
				int start,
				int size);

// --- define ---

/*
comment
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
		buckets,
		rest);
	if (!arr_arr_int)
		return (NULL);
	return (arr_arr_int);
}

static int	**arr_arr_int_fill_full_buckets(
				int **arr_arr_int,
				int	*pre_sorted_arr,
				int	full_buckets)
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

static int	**arr_arr_int_fill_rest_bucket(
				int **arr_arr_int,
				int	*pre_sorted_arr,
				int	len,
				int	rest)
{
	int	*temp;
	int start;

	if (rest == 0)
		return (arr_arr_int);
	start = len - rest;
	temp = copy_sequence(pre_sorted_arr, start, rest);
	if (!temp)
		return (arr_arr_int_free(arr_arr_int));
	return (arr_arr_int);
}

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
