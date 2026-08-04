/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   filename.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: intranam <intranam@student.42berlin.d	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam		  #+#	#+#			 */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

// --- include ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	test, norminette
*/

// --- define ---

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pa n times; n = length of stack a
*/

int	anysort_push_all_elements_to_stack_a(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			PA,
			machine -> stacks[1].len));
}

/*
calls machine_operation_execute_times_n -> machine_operation_execute
-> calls pb n times; n = length of stack b
*/

int	anysort_push_all_elements_to_stack_b(t_stack_machine *machine)
{
	return (
		machine_operation_execute_times_n(
			machine,
			PB,
			machine -> stacks[0].len));
}
