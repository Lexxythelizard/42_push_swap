/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_funcs.c                                    :+:      :+:    :+:   */
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

void	func_assign(t_stack_machine *machine)
t_func	func_init(void (*f)(t_stack_machine *), char *name)

// --- define ---

void	func_assign(t_stack_machine *machine)
{
	machine -> funcs[0] = func_wrap(&sa, "sa");
	machine -> funcs[1] = func_wrap(&sb, "sb");
	machine -> funcs[2] = func_wrap(&ss, "ss");
	machine -> funcs[3] = func_wrap(&pa, "pa");
	machine -> funcs[4] = func_wrap(&pb, "pb");
	machine -> funcs[5] = func_wrap(&ra, "ra");
	machine -> funcs[6] = func_wrap(&rb, "rb");
	machine -> funcs[7] = func_wrap(&rr, "rr");
	machine -> funcs[8] = func_wrap(&rra, "rra");
	machine -> funcs[9] = func_wrap(&rrb, "rrb");
	machine -> funcs[10] = func_wrap(&rrr, "rrr");
}

/* Creates an instance of t_func from a function pointer and a function name */
t_func	func_init(void (*f)(t_stack_machine *machine), char *name)
{
	t_func	func_obj;

	func_obj.func = f;
	func_obj.name = name;
	return (func_obj);
}
