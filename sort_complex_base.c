/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:27:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/05 17:44:29 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "stack.h"
#include "stack_track.h"

// --- DOC ---

/*
	approach to pseudocode merge sort ...
*/

// --- prototype ---

void	sort_pairs(t_interface *stacks, t_stack_track *st_tr);
void	split_stack(t_interface *stacks, t_op_track *tracker, int size);
void	utility3(void);
void	utility4(void);


// Ruler for lenght max lenghts:)
/* ************************************************************************** */

/* pairs are sorted ascending */

void	sort_pairs(t_interface *stacks, t_stack_track *st_tr)
{
	t_stack_frame	a;
	t_stack_frame	b;

	if ((!(stacks)) || (!(stacks -> stacks[0])) || (!(stacks -> stacks[1])))
		return ;
	a = stacks -> stacks[0] -> head;
	b = stacks -> stacks[1] -> head;
	while ((st_tr -> size_a)--)
	{
		if ((a -> val > a -> next -> val) && (b -> val > b -> next -> val))
			exec(stacks, 2);		// exec ss 1 time
		if (a -> val > a -> next -> val)
			exec(stacks, 0);		// exec sa 1 time
		if (b -> val > b -> next -> val)
			exec(stacks, 1);		// exec sb 1 time
		exec_n(stacks, 7, 2);		// exec rr 2 time
		(st_tr -> size_a)--;
		st_tr -> size_b -= 2;
	}
	if ((sz_b >= 2) && ((b -> val) < (b -> next -> val)))
		exec(stacks, 1);					// exec sb 1 time
	exec_n(stacks, 6, (st_tr -> size_b));	// exec rb (st_tr -> size_b) times
	st_tr -> unmerged_a = st_tr -> size_a;
	st_tr -> unmerged_b = st_tr -> size_b;
}

/*	...you comment... */

void	split_stack(t_interface *stacks, t_stack_track *st_tr, int size)
{
	int	half;

	half = (int)(size / 2);
	if ((!(stacks)) || (!(stacks -> stacks[0])) || (!(stacks -> stacks[0])) || 
		(!(stacks -> tracker)))
		return ;
	while (half--)
	{
		exec(stacks, 4);			// exec pb 1 time
		exec_n(stacks, 5, 2);		// exec ra 2 times
	}
	st_tr -> size_a = get_stack_size(stacks -> stacks[0]);
	st_tr -> size_a = get_stack_size(stacks -> stacks[0]);
}

/*	...you comment... */
/*
void	utility3(void)
{
	// code
}
*/
/*	...you comment... */
/*
void	utility4(void)
{
	// code
}
*/

