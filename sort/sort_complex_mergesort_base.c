// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
	this file contains the very base and the very first steps of the 
	merge sort adaption:

	it has two functions which are available in the sort.h header file:

		- split_stack()
		- sort_pairs()
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

/*
this function simply splits the stack bei pushing half of its elements 
to stack b
if number of elements are uneven
*/

int	split_stack(t_stack_machine *machine)
{
	int	half;

	half = (int)(machine -> stacks[0].len / 2);
	return (machine_operation_execute_times_n(machine, PB, half));
}

/*
this function is meant to sort the elements pair wise in both stacks
simulatniously, by calling either 'ss', 'sa' or 'sb'
and rotating the stacks forward.

Considered both stacks as unsorted and uses those n umbers for iteration 
and to adapt behavior.

Can handle uneven stacks and odd numbers of elements.

returns 1 if succes
*/

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
	}
	return (1);
}

// --- utilities ---

/*
this utiliy function takes a pointer to the instance of stack machine and 
a key of unsortetd (0 - 3)
kalculating the key of ascending (0 - 3) to decide 
weather it calls 'ss', 'sa' or 'sb'

					unsort a >= 2	unsort b >= 2	Range
					descen a (0/1)	descen (0/1)	Range

	key unsorted	0 / 1			0 / 1			{0, 1, 2, 3}

	key ascending	0 / 1			0 / 1			{0, 1, 2, 3}

*/

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

/*
this utility function takes a pointer to the instance of stack machine 
and two pointers to unsorted_a and unsorted_b
by its values it decided weather it call 'rr' times two, 'rr' times one, 
'ra' or 'rb'

decrements values of unsorted_a and unsorted_b if matching function 
was called

returns number of operations
*/

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
