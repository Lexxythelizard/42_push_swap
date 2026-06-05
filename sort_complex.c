/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:27:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/05 15:52:13 by lenivorb         ###   ########.fr       */
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

void	func0(t_interface stacks, t_op_track *tracker);
void	merge_level(t_interface stacks, t_stack_track *st_tr);
void	merge(t_interface stacks, t_stack_track *st_tr);
void	merge_to_a(t_interface stacks, t_stack_track *st_tr);
void	merge_to_b(t_interface stacks, t_stack_track *st_tr);

// --- define ---

void	func0(t_interface stacks, t_stack_track *st_tr)
{
	// to create a merged stack of four elemnts:
	//	 first splt the stack
	//	 sort all pairs in each side see sort pairs
	//	 afterwards merge four pacs plus rest \
		 and destribute the merge results equalyy on both stacks
	//	 than merge eight pacs plus rest \
		 and destribute the merge results equalyy on both stacks
	//	 continue until it's merged back into one array

	// last theoretical problem:
	
	/*
		if sorted stack appears in b:
			and if it is descending just calling pa size times
		if sorted stack appears in b:
			either let it be merged asending or let it ...

		...screw this, why not just merge everything in ascending order
		and let the sorted stack appear in a by merging :)

		... Yeah, problem solved.
	*/
	
}

// --- merge functions ---

/*
merges one level like merge size 4, then double merge size...

consider merging this two functions
*/


void	merge_level(t_interface stacks, t_stack_track *st_tr)
{
	while (st_tr -> unmerged_a || (st_tr -> unmerged_b))
		merge(stacks, st_tr);
	st_tr -> merge_size *= 2;
}

/*coordinates the two merge functions like a pendulum*/

void	merge(t_interface stacks, t_stack_track *st_tr)
{
	if (st_tr -> side)
	{
		merge_to_b(stacks, st_tr);
		st_tr -> side++;
		return ;
	}	
	merge_to_a(stacks, st_tr);
	st_tr -> side--;
}

void	merge_to_a(t_interface stacks, t_stack_track *st_tr)
{
	int	pos;
	int	el_a;
	int	el_b;
	int	i;

	pos = 0;
	i = 0;
	el_a = min_of((st_tr -> unmerged_a), ((st_tr -> merge_size) / 2));
	el_b = min_of((st_tr -> unmerged_b), ((st_tr -> merge_size) / 2));
	while ((el_b--) && (stacks -> stacks[0] -> head))
	{
		while ((i++ <= el_a) && 
		((stack->stacks[1]->head->val) > (stacks->stacks[0]->head->val)))
		{
			exec(stacks, 5);		// exec ra 1 time
			pos++;
		}
		exec(stacks, 3);			// exec pa 1 time;
		(st_tr -> size_b)--;
		(st_tr -> size_a)++;
		(st_tr -> unmerged_b)--;
	}
	st_tr -> unmerged_a -= el_a;
	while (pos--)
		exec(stacks, 8);			// exec rra 1 time
}

void	merge_to_b(t_interface stacks, t_stack_track *st_tr)
{
	int	pos;
	int	el_a;
	int	el_b;
	int	i;

	pos = 0;
	i = 0;
	el_a = min_of((st_tr -> unmerged_a), ((st_tr -> merge_size) / 2));
	el_b = min_of((st_tr -> unmerged_b), ((st_tr -> merge_size) / 2));
	while ((el_a--) && (stacks -> stacks[0] -> head))
	{
		while ((i++ <= el_b) && 
		((stack->stack[0]->head->val) > (stacks->stacks[1]->head->val)))
		{
			exec(stacks, 6);				// exec rb 1 time
			pos++;
		}
		exec(stacks, 4);					// exec pb 1 time;
		(st_tr -> size_b)--;
		(st_tr -> size_a)++;
		(st_tr -> unmerged_b)--;
	}
	(st_tr->unmerged_a) -= el_a;
	while (pos--)
		exec(stacks, 9);			// exec rrb 1 time
}
