/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:40:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/08 20:38:34 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

// --- DOC --

/*
TODO:	reimplement from scratch
*/

// --- proto --- for tests

void	free_machine(t_stack_machine *machine);

// --- define ---

void	free_machine(t_stack_machine *machine)
{
	int	i;

	free_stack(&(machine -> stacks[0]));
	free_stack(&(machine -> stacks[1]));
	free(machine -> stacks);
	if (machine -> stats)
	{
		free(machine -> stats -> calls);
		free(machine -> stats);
	}
	i = 0;
	while (i < 11)
		free(&((machine -> funcs)[i++]));
}
