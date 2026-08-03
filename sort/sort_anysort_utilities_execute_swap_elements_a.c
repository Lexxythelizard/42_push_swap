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

// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
	little efficientcy work arround four smaller stacks
*/

// --- define ---

/*
swaps second and third element in three opeartions - no rotation
*/

void	anysort_sub_swap_second_and_third_a(
			t_stack_machine *machine)
{
	machine_operation_execute(machine, PB);
	machine_operation_execute(machine, SA);
	machine_operation_execute(machine, PA);
	return ;
}

/*
inserts the third element as the first 
while the first becomes the new second and 
the second becomes the new third
in four operations	- no rotation
*/

void	anysort_sub_swap_second_and_third_then_second_and_first_a(
			t_stack_machine *machine)
{
	machine_operation_execute(machine, PB);
	machine_operation_execute(machine, SA);
	machine_operation_execute(machine, PA);
	machine_operation_execute(machine, SA);
	return ;
}

/*
inserts the first element as the third 
while the second becomes the new first and 
the third becomes the new second
in four operations	- no rotation
*/

void	anysort_sub_swap_second_and_first_then_second_and_third_a(
			t_stack_machine *machine)
{
	machine_operation_execute(machine, SA);
	machine_operation_execute(machine, PB);
	machine_operation_execute(machine, SA);
	machine_operation_execute(machine, PA);
	return ;
}

/*
swaps first and second element with one operations
sadly norminette doesn't allow more then five functions per file :/
*/

void	anysort_sub_swap_first_and_second_a(
			t_stack_machine *machine)
{
	machine_operation_execute(machine, SA);
	return ;
}

/*
swaps first and third element with five operations - no rotation
*/

void	anysort_sub_swap_first_and_third_a(
			t_stack_machine *machine)
{
	machine_operation_execute(machine, SA);
	machine_operation_execute(machine, PB);
	machine_operation_execute(machine, SA);
	machine_operation_execute(machine, PA);
	machine_operation_execute(machine, SA);
	return ;
}
