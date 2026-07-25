// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
TODO: test
*/

// --- prototypes ---

static int	turn_to_unsorted_element_and_push_it_to_a(
				t_stack_machine *machine,
				int sorted);

static int	insert_in_place(
				t_stack_machine *machine,
				int position);

static int	turn_back_to_start_position(
				t_stack_machine *machine,
				int position);

static int	element_fits_in_between_descending(
				t_stack_machine *machine);

// --- define ---

/*
comment
*/

void	sort_n_elements_with_insertion_sort_descending(
			t_stack_machine *machine,
			int	sorting_range,
			int bucket_size)
{
	t_stack	*stack_b;
	int		unsorted;
	int		sorted;
	int		pos;

	stack_b = &(machine -> stack[1]);
	sorting_range = int_min_of_two(stack_b -> len, sorting_range);
	unsorted = int_min_of_two(stack_b -> len, sorting_range);
	sorted -= stack_count_descending_in_range_(stack_b, 0, unsorted);
	sorted = int_max_of_two(1, sorted);
	pos = 0;

	while (unsorted)
	{
		pos += turn_to_unsorted_element_and_push_it_to_a(machine, sorted);
		pos -= insert_in_place(machine, pos);
		pos -= turn_back_to_start_position(machine, pos);
		sorted = stack_count_descending_in_range_(stack_b, 0, unsorted);
		unsorted -= sorted;
	}
}

// --- utilities ---

/*
the function name explains everything :)
*/

static int	turn_to_unsorted_element_and_push_it_to_a(
			t_stack_machine *machine,
			int sorted)
{
	machine_operation_execute_times_n(machine, RB, sorted);
	machine_operation_execute(machine, PA);
	return (sorted);
}

/*
turn back until it fits in but max as far as position
*/

static int	insert_in_place(
			t_stack_machine *machine,
			int position)
{
	int		turn_backs;
	t_stack	*stack_b;

	turn_backs = 0;
	stack_b = &(machine -> stacks[0]);
	while (position)
	{
		if (element_fits_in_between_descending(machine))
			break ;
		turn_backs += machine_operation_execute(machine, RRB);
	}
	turn_backs += machine_operation_execute(machine, RB);
	return (turn_backs);
}

/*
the function name explains everything
*/

static int	turn_back_to_start_position(
			t_stack_machine *machine,
			int position)
{
	return (
		machine_operation_execute_times_n(
			machine, RRB, position));
}

/*
returns 0 / 1 if element woul fit in this place or not
*/

static int	element_fits_in_between_descending(
				t_stack_machine *machine)
{
	stack	*stack_b;
	int		bigger;
	int		smaller;
	int		in_between;

	bigger = machine -> stacks[1].last -> val;
	smaller = machine -> stacks[1].first -> val;
	in_between = machine -> stacks[0].first -> val;

	return ((bigger >= in_between) && (in_between >= bigger));
}
