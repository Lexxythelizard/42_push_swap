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



// ------ module: sort bucket ---------------

void	sort_bucket(
			t_stack_machine *machine,
			int	bucket_i,
			int bucket_size)
{
	t_stack	*stack_b;
	int		i;

	t_stack_b
	i = 0;
	// call a sorting func
}

void	sort_n_elements_with_insertion_sort(
			t_stack_machine *machine,
			int	sorting_range,
			int bucket_size)
{
	t_stack	*stack_b;
	int		i;
	int		local_max;
	int		current_max;

	stack_b = &(machine -> stack[1]);
	sorting_range = int_min_of_two(sorting_range, stack_b -> len);
	local_max = stack_get_max_val_in_range(stack_b, 0, (sorting_range - 1)); 
	while ((i + 1) < sorting_range)
	{

	}


	so


}

void	sort_call_insertion_sort_descending(
			t_stack_machine *machine)
{
	t_stack	*stack_b;
	int		i;

	stack_b = &(machine -> stack[1]);
	
	// while loop

		// get_local_max
}



// ---- module push bucket --------------

void	push_last_bucket_to_b(
			t_stack_machine *machine)
{
	t_stack	*stack_a;

	len = machine -> stacks[0].len;
	machine_operation_execute_times_n(machine, PB, len);
}

void	push_bucket_to_b(
			t_stack_machine *machine,
			int	bucket_i,
			int bucket_size)
{
	int	bucket_x_i;

	bucket_x_i = 0;
	while (bucket_x_i < bucket_size)
	{
		rotate_next_element_for_bucket_to_top(machine, bucket_i, bucket_size);
		machine_operation_execute(machine, PB);
		bucket_x_i++;
	}
}

int	rotate_next_element_for_bucket_to_top(
			t_stack_machine *machine,
			int	bucket_i,
			int bucket_size)
{
	t_stack	*stack_a
	int		steps_ra;
	int		steps_rra;
	int		idx;
	int		element_i;

	i = 0;
	stack_a = &(machine -> stack[0]);
	steps_ra = int_max_of_two((stacks_a -> len), 0);
	steps_rra = int_max_of_two((stacks_a -> len), 0);
	while (element_i < bucket_size)
	{
		idx = stack_get_idx_of_val(stack_a, sniggle[bucket_i][element_i]);
		steps_ra = int_max_of_two(steps_ra, idx);
		steps_rra = int_max_of_two(steps_rra, ((stack_a -> len) - idx));
		element_i;
	}
	if (steps_ra < steps_rra)
		return (machine_operation_execute_times_n(machine, RRA, steps_rra));
	return (machine_operation_execute_times_n(machine, RA, steps_ra));
}
