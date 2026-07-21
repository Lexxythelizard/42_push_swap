// --- include ---

#include "./machine.h"

// --- DOC --

/*
	executes one of the machine -> stack methods and which puts down its name, 
	changes the stats if needed. The methods are indexed as follows:

		MAKRO:		idx			function:		string:

		SA :		0:			sa				"sa"
		SB :		1:			sb				"sb"
		SS :		2:			ss				"ss"
		PA :		3:			pa				"pa"
		PB :		4:			pb				"pb"
		RA :		5:			ra				"ra"
		RB :		6:			rb				"rb"
		RR :		7:			rr				"rr"
		RRA :		8:			rra				"rra"
		RRB :		9:			rrb				"rrb"
		RRR :		10:			rrr				"rrr"

	return:
		>= 0	if succes
		0		if not possible
		-1		if error
*/

// --- define ---

/*
takes pointer to instance of t_stack_machine and idx to execute operation
prints operation if success 
For intuitive use: use one of the Makros above

return:
	1	if success
	0	if not possible
	-1	if error
*/

int	machine_operation_execute(t_stack_machine *machine, int idx)
{
	int	ctrl;

	if ((!machine) || (idx < 0) || (idx > OPS_N))
		return (-1);
	ctrl = ((machine -> funcs)[idx].func)(machine);
	if (ctrl == 1)
		machine -> stats.calls[idx]++;
	machine -> stats.total_ops += (ctrl == 1);
	return (ctrl);
}

/*
takes pointer to instance of t_stack_machine and idx 
to execute operation n times if possiple
prints operation if success 

return:
	n	number of sucessful executions
	-1	if any error occured in any iteration
*/

int	machine_operation_execute_times_n(t_stack_machine *machine, int idx, int n)
{
	int	count;
	int	ctrl;

	count = 0;
	ctrl = 0;
	while (n--)
	{
		ctrl = machine_operation_execute(machine, idx);
		if (ctrl == (-1))
			return (-1);
		count += ctrl;
	}
	return (count);
}
