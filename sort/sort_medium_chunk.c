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

	// get sqrt
	// while elements in stack a
		// push sqrt or rest elements to stack b
		// sort them by max extraction adaption
	// merge elements chunks
	return ;
}
