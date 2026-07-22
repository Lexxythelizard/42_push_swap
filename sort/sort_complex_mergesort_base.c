// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	reimplement from scratch
*/

// --- prototypes ---

static int	sort_one_time_two_pairs(
				t_stack_machine *machine,
				int key_uns);

static int	rotate_one_time_two_pairs(
				t_stack_machine *machine,
				int *unsorted_a,
				int *unsorted_b);

// --- define ---

int	split_stack(t_stack_machine *machine)
{
	int	half;

	half = (int)(machine -> stacks[0].len / 2);
	return (machine_operation_execute_times_n(machine, PB, half));
}

int	sort_pairs(t_stack_machine *machine)
{
	int	unsorted_a;
	int	unsorted_b;
	int	key_uns;

	unsorted_a = machine -> stacks[0].len;
	unsorted_b = machine -> stacks[1].len;
	key_uns = 0;
	
	while ((unsorted_a) || (unsorted_b))
	{

		key_uns = 2 * (unsorted_a >= 2) + (unsorted_b >= 2);

		sort_one_time_two_pairs(machine, key_uns);
		rotate_one_time_two_pairs(machine, &unsorted_a, &unsorted_b);

	/*
		unsorted_a -= int_min_of_two(unsorted_a, 2);
		unsorted_b -= int_min_of_two(unsorted_b, 2);
	*/

	}

	return (1);
}

static int	sort_one_time_two_pairs(t_stack_machine *machine, int key_uns)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		key_asc;

	stack_a = &(machine -> stacks[0]);
	stack_b = &(machine -> stacks[1]);

	key_asc = 0;
	key_asc += (2 * !(stack_is_first_and_sec_ascending(stack_a)));
	key_asc += (!(stack_is_first_and_sec_ascending(stack_b)));
	
	if ((key_asc / 2) && (key_asc % 2) && (key_uns / 2) && (key_uns % 2))
		return (machine_operation_execute(machine, SS));
	if ((key_asc / 2) && (key_uns / 2))
		return (machine_operation_execute(machine, SA));
	if ((key_asc % 2) && (key_uns % 2))
		return (machine_operation_execute(machine, SB));
	return (0);
}

static int	rotate_one_time_two_pairs(
				t_stack_machine *machine,
				int *unsorted_a,
				int *unsorted_b)
{
	int	ctrl;

	ctrl = 0;
	if ((*unsorted_a >= 2) && (*unsorted_b >= 2))
	{
		*unsorted_a -= 2;
		*unsorted_b -= 2;
		return (machine_operation_execute_times_n(machine, RR, 2));
	}
	if ((*unsorted_a) && (*unsorted_b))
	{
		ctrl = machine_operation_execute(machine, RR);
		(*unsorted_a)--;
		(*unsorted_b)--;
	}
	if (*unsorted_a)
		ctrl = machine_operation_execute(machine, RA);
	*unsorted_a -= (*unsorted_a > 0);
	if (*unsorted_b)
		ctrl = machine_operation_execute(machine, RB);
	*unsorted_b -= (*unsorted_b > 0);
	return (ctrl);
}
