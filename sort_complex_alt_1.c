/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_alt_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:27:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/04 17:50:21 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "stack.h"

// --- DOC ---

/*
	approach to pseudocode merge sort ...
*/

// --- prototype ---

void	func0(t_interface stacks, t_op_track *tracker);
void	merge(t_stack dest, t_stack sec, int ms);
void	sort_pairs(t_interface *stacks, t_op_track *tracker, int sz_a, int sz_b);
void	utility3(void);
void	utility4(void);

// --- define ---

void	func0(t_interface stacks, t_op_track *tracker)
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

// --- utilities ---

/*
	copied over, needs to get modified
	TODO: modify
	// --- struct ---

	typedef struct s_stack_track
	{
	    int     size_a;
	    int     size_b;
	    int     merge_size;
	    int     side;
	}           t_stack_track;

*/

void	merge(t_interface stacks, t_op_track *tracker, t_stack_track *st_tr)
{
	//coordinates the two merge functions
	if (st_tr -> side)
	{
		merge_to_b(stacks, tracker, st_tr);
		st_tr -> side++;
		return ;
	}	
	merge_to_a(stacks, tracker, st_tr);
	st_tr -> side--;
}

void	merge_to_a(t_interface_stacks, t_op_track *tracker, t_stack_track *st_tr)
{
	int	pos;
	int	el_a;
	int	el_b;
	int	i;

	pos = 0;
	i = 0;
	el_a = min_of((st_tr -> unmerged_a), ((st_tr -> merge_size) / 2));
	el_b = min_of((st_tr -> unmerged_b), ((st_tr -> merge_size) / 2));
	while ((el_b--) && (stacks -> a -> head))
	{
		while ((i++ <= el_a) && 
		((stack -> b -> head -> val) > (stacks -> a -> head -> val)))
		{
			exec(stacks, tracker, 5);		// exec ra 1 time
			pos++;
		}
		exec(stacks, tracker, 3);			// exec pa 1 time;
		(st_tr -> size_b)--;
		(st_tr -> size_a)++;
		(st_tr -> unmerged_b)--;
	}
	st_tr -> unmerged_a -= el_a;
	while (pos--)
		exec(stacks, tracker, a);			// exec rra 1 time
}

void	merge_to_b(t_interface_stacks, t_op_track *tracker, t_stack_track *st_tr)
{
	int	pos;
	int	el_a;
	int	el_b;
	int	i;

	pos = 0;
	i = 0;
	el_a = min_of((st_tr -> unmerged_a), ((st_tr -> merge_size) / 2));
	el_b = min_of((st_tr -> unmerged_b), ((st_tr -> merge_size) / 2));
	while ((el_a--) && (stacks -> a -> head))
	{
		while ((i++ <= el_b) && 
		((stack -> a -> head -> val) > (stacks -> b -> head -> val)))
		{
			exec(stacks, tracker, 6);		// exec rb 1 time
			pos++;
		}
		exec(stacks, tracker, 4);			// exec pb 1 time;
		(st_tr -> size_b)--;
		(st_tr -> size_a)++;
		(st_tr -> unmerged_b)--;
	}
	st_tr -> unmerged_a -= el_a;
	while (pos--)
		exec(stacks, tracker, 9);			// exec rrb 1 time
}

// Ruler for lenght max lenghts:)
/* ************************************************************************** */

/* pairs are sorted ascending */

void	sort_pairs(t_interface *stacks, t_op_track *tracker, t_stack_track *st_tr)
{
	t_stack_frame	a;
	t_stack_frame	b;

	if ((!(stacks)) || (!(stacks -> a)) || (!(stacks -> b)) || (!(tracker)))
		return ;
	a = stacks -> a -> head;
	b = stacks -> b -> head;
	while ((st_tr -> size_a)--)
	{
		if ((a -> val > a -> next -> val) && (b -> val > b -> next -> val))
			exec(stacks, tracker, 2);		// exec ss 1 time
		if (a -> val > a -> next -> val)
			exec(stacks, tracker, 0);		// exec sa 1 time
		if (b -> val > b -> next -> val)
			exec(stacks, tracker, 1);		// exec sb 1 time
		exec_n(stacks, tracker, 7, 2);		// exec rr 2 time
		(st_tr -> size_a)--;
		st_tr -> size_b -= 2
	}
	if ((sz_b >= 2) && ((b -> val) < (b -> next -> val)))
		exec(stacks, tracker, 1);					// exec sb 1 time
	exec_n(stacks, tracker, 6, (st_tr -> size_b))	// exec rb (st_tr -> size_b) times
}

/*	...you comment... */

void	split_stack(t_interface *stacks, t_op_track *tracker, int size)
{
	int	half;

	half = (int)(size / 2);
	if ((!(stacks)) || (!(stacks -> a)) || (!(stacks -> b)) || (!(tracker)))
		return ;
	while (half--)
	{
		exec(stacks, tracker, 4);			// exec pb 1 time
		exec_n(stacks, tracker, 5, 2);		// exec ra 2 times
	}
}

/*	...you comment... */

void	utility3(void)
{
	// code
}

/*	...you comment... */

void	utility4(void)
{
	// code
}
