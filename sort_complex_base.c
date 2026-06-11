/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:27:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 20:13:33 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "stack.h"
#include "push_swap.h"
#include "stack_track.h"

// --- DOC ---

/*
	approach to pseudocode merge sort ...
*/

// --- prototype ---

void			
	sort_pairs(
		t_interface *stacks,
		t_stack_track *st_tr);
void			
	split_stack(
		t_interface *stacks,
		t_stack_track *st_tr, int size);
t_stack_track	
	*init_stack_track(void);

// --- define ---

/* pairs are sorted ascending */
/*
	while (still pair nee to get sorted)
	{
		if both sides need to get swapped
			exec ss 1 time
		if just side a needs to get swapped
			exec sa 1 time
		if just side b needs to get swapped
			exec sb 1 time
		exec rr 2 time
		}
	if unsorted elements in stack b == 2 and if need for swap
		exec sb 1 time
	exec rb (st_tr -> size_b) times
	resetting unmerged for merging
*/

void	sort_pairs(
			t_interface *stacks,
			t_stack_track *st_tr)
{
	t_stack_frame	a;
	t_stack_frame	b;

	if ((!(stacks)) || (!(stacks -> stacks[0])) || (!(stacks -> stacks[1])))
		return ;
	a = stacks -> stacks[0]->head;
	b = stacks -> stacks[1]->head;
	while ((st_tr -> unmerged_a)--)
	{
		if ((a -> val > a -> next -> val) && (b -> val > b -> next -> val))
			exec(stacks, 2);
		if (a -> val > a -> next -> val)
			exec(stacks, 0);
		if (b -> val > b -> next -> val)
			exec(stacks, 1);
		exec_n(stacks, 7, 2);
		(st_tr -> unmerged_a)--;
		st_tr -> unmerged_b -= 2;
	}
	if ((st_tr -> unmerged_b >= 2) && ((b -> val) < (b -> next -> val)))
		exec(stacks, 1);
	exec_n(stacks, 6, (st_tr -> unmerged_b));
	st_tr -> unmerged_a = st_tr -> size_a;
	st_tr -> unmerged_b = st_tr -> size_b;
}

/*	...you comment... */

/*
	while (there is still the half)
	{
		exec pb 1 time
		exec ra 2 times
	}
	setting size_[a/b]		to stack_len [a/b]
	setting unmerged_[a/b]	to stack_len [a/b]
*/

void	split_stack(
			t_interface *stacks,
			t_stack_track *st_tr,
			int size)
{
	int	half;

	half = (int)(size / 2);
	if ((!(stacks)) || (!(stacks -> stacks[0])) || (!(stacks -> stacks[0])) || 
		(!(stacks -> tracker)))
		return ;
	while (half--)
	{
		exec(stacks, 4);
		exec_n(stacks, 5, 2);
	}
	st_tr -> size_a = get_stack_size(stacks -> stacks[0]);
	st_tr -> size_a = get_stack_size(stacks -> stacks[0]);
	st_tr -> unmerged_a = st_tr -> size_a;
	st_tr -> unmerged_b = st_tr -> size_b;
}

/*	...you comment... */

t_stack_track	*init_stack_track(void)
{
	t_stack_track	*stack_track;

	stack_track = malloc(24);
	if (!stack_track)
		return (NULL);
	stack_track -> size_a = 0;
	stack_track -> size_b = 0;
	stack_track -> merge_size = 0;
	stack_track -> unmerged_a = 0;
	stack_track -> unmerged_b = 0;
	stack_track -> side = 0;
	return (stack_track);
}
