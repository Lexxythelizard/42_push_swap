// --- icludes ---

#include "./sort.h"

// test

// --- DOC ---

/*
TODO: reimplement from srcatch
*/

// --- define ---

/*
Requieres n * sqrt(n) time / operation complexity

Idea:

	if stack was "splitted" in sqrt(n) chunks
	and every chunk was sorted by min extraction

	then: sqrt(n) * n* n -> O(n) for sqrt(n) sorted chunks
	
	if merging of sqrt(n) sorted chunks takes O(sqrt(n))

	this would be O(n * sqrt(n)) for chunk sort adaption
*/

void	chunck_sort_adaption(t_stack_machine *machine)
{
	int	sqrt;

	(void)(sqrt);
	(void)(machine);

	// get_pre_sorted_buckets_as_arrays()
	// while elements in stack a
		// push bucket (of matching arr elements)
			// find the shortest way to the next element to push to bucket
			// rotate
			// push to bucket
		// sort bucket in stack b descending
			// use modified insertion sort
	// push all the elements back to a

	return ;
}
