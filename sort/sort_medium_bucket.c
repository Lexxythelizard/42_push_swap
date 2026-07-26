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

// --- prototype ---

static int	push_everything_back_to_a(t_stack_machine *machine);

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

void	bucket_sort_adaption(t_stack_machine *machine)
{
	int	**bucket_map;
	int	bucket_idx;
	int	bucket_size;
	int	rest;
	int	buckets;

	buckets = (int)(get_sqrt(machine -> stacks[0].len));
	bucket_size = buckets;
	rest = bucket_size * buckets;
	buckets += (rest > 0);
	bucket_map = get_pre_sorted_buckets_as_arrays(
		machine,
		buckets,
		rest);
	bucket_idx = 0;

	while (bucket_idx < buckets)
		bucket_idx = push_and_sort_bucket(
			machine,
			bucket_map,
			bucket_idx,
			bucket_size);
	push_and_sort_rest(
			machine,
			rest);
	push_everything_back_to_a(machine);
}

/*
comment
*/

int	push_and_sort_bucket(
		t_stack_machine *machine,
		int **bucket_map,
		int bucket_idx,
		int bucket_size)
{
	push_bucket_to_b(
		machine,
		bucket_map,
		bucket_idx,
		bucket_size);
	sort_n_elements_with_insertion_sort_descending(
		machine,
		bucket_size);
	return (1);
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

// --- utillity ---

static int	push_everything_back_to_a(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			RA,
			machine -> stacks[1].len));
}
