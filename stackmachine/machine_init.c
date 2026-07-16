/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:37:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 20:38:52 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stackmachine.h"

// --- DOC --

/*
TODO:   - reimplement from scratch
		- source out func_ functions
		- source out stats_ functions
*/

// --- proto --- for tests

t_stack_machine	*machine_init_new_empty(void);

// --- define ---

t_stack_machine	*machine_init_new_empty(void)
{
	t_stack_machine	machine;

	stack_init_empty(&(machine.stack[0]));
	stack_init_empty(&(machine.stack[1]));
	stats_init_empty(&(machine.stats));
	func_assign(&machine);
	return (&machine);
}
