// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
TODO: test and comment
*/

/*
Requieres n * sqrt(n) time / operation complexity

Idea:

	if stack was "splitted" in sqrt(n) chunks
	and every chunk was sorted by min extraction

	then: sqrt(n) * n* n -> O(n) for sqrt(n) sorted chunks
	
	if merging of sqrt(n) sorted chunks takes O(sqrt(n))

	this would be O(n * sqrt(n)) for chunk sort adaption
*/

// --- define ---

/*
	get_pre_sorted_buckets_as_arrays()
	while elements in stack a
		push bucket (of matching arr elements)
			find the shortest way to the next element to push to bucket
			rotate
			push to bucket
		sort bucket in stack b descending
			use modified insertion sort
	push all the elements back to a

*/

int	bucket_sort_adaption(t_stack_machine *machine)
{
	int	**bucket_map;
	int	bucket_size;
	int	rest;
	int	buckets;

	if (machine -> stacks[0].len <= 1)
		return (machine -> stacks[0].len);
	if (machine -> stacks[0].len == 2)
		return (sort_two(machine));
	if (machine -> stacks[0].len == 3)
		return (sort_three(machine));
	buckets = (int)(get_sqrt(machine -> stacks[0].len));
	bucket_size = buckets;
	rest = machine -> stacks[0].len - bucket_size * buckets;
	buckets += (rest > 0);
	bucket_map = get_pre_sorted_buckets_as_arrays(
		machine,
		buckets,
		rest);
	push_and_sort_buckets(
		machine,
		bucket_map,
		bucket_size);
	push_and_sort_rest(
		machine,
		rest);
	push_all_elements_to_stack_a(machine);
	arr_arr_int_free(bucket_map);
	return (machine -> stacks[0].len);
}

/*
comment
*/

int	push_and_sort_buckets(
		t_stack_machine *machine,
		int **bucket_map,
		int bucket_size)
{
	int	bucket_idx;

	bucket_idx = 0;
	while (bucket_idx < bucket_size)
	{
		push_bucket_to_b(
			machine,
			bucket_map,
			bucket_idx,
			bucket_size);
		sort_n_elements_with_insertion_sort_descending(
			machine,
			bucket_size);
		bucket_idx++;
	}
	return (bucket_idx);
}

/*
comment
*/

int	push_and_sort_rest(
		t_stack_machine *machine,
		int rest)
{
	push_last_bucket_to_b(
		machine);
	sort_n_elements_with_insertion_sort_descending(
		machine,
		rest);
	return (1);
}
