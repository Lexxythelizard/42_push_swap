/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	test, norminette
*/

// --- proto ---

static int	swap_second_and_third_a(t_stack_machine *machine);
static int	swap_first_and_third_a(t_stack_machine *machine);

// --- define ---

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pa n times; n = length of stack a
*/

int	sort_two(t_stack_machine *machine)
{
	t_stack	*stack_a;

	stack_a = &(machine -> stacks[0]);
	if (stack_a -> len <= 1)
		return (-1);
	if (stack_is_first_and_sec_ascending(stack_a))
		return (0);
	return (
		machine_operation_execute(machine, SA));
}

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pb n times; n = length of stack b
*/

// rewrite still made for a ascendin made for a ascendingg

int	sort_three_descending_b(t_stack_machine *machine)
{
	t_stack	*stack_a;
	int		first;
	int		secon;
	int		third;

	stack_a = &(machine -> stacks[0]);
	if (stack_a -> len <= 2)
		return (-1);
	first = stack_a -> first -> val;
	secon = stack_a -> first -> next -> val;
	third = stack_a -> first -> next -> next -> val;
	if ((first <= secon) && (secon <= third))
		return (0);
	if ((first <= third) && (third <= secon))
		swap_second_and_third_a(machine);
	if ((secon <= first) && (first <= third))
		return (machine_operation_execute(machine, SA));
	if ((secon <= third) && (third <= first))
		return (machine_operation_execute(machine, RA));
	if ((third <= first) && (first <= secon))
		return (machine_operation_execute(machine, RRA));
	if ((third <= secon) && (secon <= first))
		swap_first_and_third_a(machine);
	return (0);
}

static int	swap_second_and_third_b(t_stack_machine *machine)
{
	if (!machine)
		return (-1);
	if (machine -> stacks[1].len < 3)
		return (0);
	machine_operation_execute(machine, RB);
	machine_operation_execute(machine, SB);
	machine_operation_execute(machine, RRB);
	return (1);
}

static int	swap_first_and_third_b(t_stack_machine *machine)
{
	if (!machine)
		return (-1);
	if (machine -> stacks[1].len < 3)
		return (0);
	machine_operation_execute(machine, RRB);
	machine_operation_execute(machine, SB);
	machine_operation_execute(machine, RB);
	return (1);
}
