// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
TODO: test
*/

// --- prototypes ---

static int	insert_element(
				t_stack_machine *machine,
				int sorted);

static int	element_fits_in_between_in_descending_order(
				t_stack_machine *machine);

// --- define ---

/*
comment
*/

void	sort_n_elements_with_insertion_sort_descending(
			t_stack_machine *machine,
			int	sorting_range)
{
	t_stack	*stack_b;
	int		sorted;
	int		artefact;

	stack_b = &(machine -> stacks[1]);
	artefact = 0;
	sorted = 1;
	// if ((sorting_range >= 0) && (sorting_range <= 1))
		// return (sorting_range);
	// if (sorting_range == 2)
		// return (sort_two(stack_b));
	// if (sorting_range == 3)
		// return (sort_three(stack_b));
	while (sorted < sorting_range)
	{
		artefact = (stack_is_first_and_sec_ascending(stack_b));
		machine_operation_execute(machine, RB);
		sorted += insert_element(machine, (sorted * artefact));
		artefact = 0;
	}
}

// --- utilities ---

/*
the function name explains everything :)
*/

static int	insert_element(
			t_stack_machine *machine,
			int sorted)
{
	int	i;
	int	inserted;
	int pos;

	i = 0;
	inserted = 0;
	pos = sorted;
	if (sorted)
		machine_operation_execute(machine, PA);
	while ((i < sorted) && (!(inserted)))
	{
		if (element_fits_in_between_in_descending_order(machine))
			inserted = machine_operation_execute(machine, PB);
		else
			pos -= machine_operation_execute(machine, RRB);
		i++;
	}
	if (!(inserted))
		machine_operation_execute(machine, PB);
	machine_operation_execute_times_n(machine, RB, (sorted - pos));
	return (1);
}

/*
returns 0 / 1 if element woul fit in this place or not
*/

static int	element_fits_in_between_in_descending_order(
				t_stack_machine *machine)
{
	int		bigger;
	int		smaller;
	int		in_between;

	bigger = machine -> stacks[1].last -> val;
	smaller = machine -> stacks[1].first -> val;
	in_between = machine -> stacks[0].first -> val;

	return ((bigger >= in_between) && (in_between >= smaller));
}
