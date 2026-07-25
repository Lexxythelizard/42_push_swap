// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
TODO: test and comment
*/

// --- prototype ---

static int	rotate_next_element_for_bucket_to_top(
				t_stack_machine *machine,
				int	bucket_i,
				int bucket_size);

// --- define ---

/*
comment
*/

void	push_last_bucket_to_b(
			t_stack_machine *machine)
{
	t_stack	*stack_a;

	len = machine -> stacks[0].len;
	machine_operation_execute_times_n(machine, PB, len);
}

/*
comment
*/

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

// --- utility ---

/*
comment
*/

static int	rotate_next_element_for_bucket_to_top(
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
