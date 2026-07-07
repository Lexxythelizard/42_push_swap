/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:27:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/07 15:30:31 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./stack.h"
#include "./push_swap.h"
#include "./stack_track.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- define ---

// --- DOC ---

/*
	approach to pseudocode merge sort ...
*/

// --- prototype ---

void	merge_sort(t_interface stacks);
void	merge_level(t_interface stacks, t_stack_track *st_tr);
void	merge(t_interface stacks, t_stack_track *st_tr);
void	merge_to_a(t_interface stacks, t_stack_track *st_tr);
void	merge_to_b(t_interface stacks, t_stack_track *st_tr);

// --- define ---

	// to create a merged stack of four elemnts:
	//	 first splt the stack
	//	 sort all pairs in each side see sort pairs
	//	 afterwards merge four pacs plus rest 
	//	 and destribute the merge results equalyy on both stacks
	//	 than merge eight pacs plus rest 
	//	  and destribute the merge results equalyy on both stacks
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

void	merge_sort(t_interface stacks)
{
	int				elements;
	t_stack_track	*st_tr;

	elements = get_stack_size(stacks[0]);
	st_tr = init_stack_track();
	if (elements < 2)
		return (free(st_tr));
	split_stack(stacks, st_tr, size);
	sort_pairs(stacks, st_tr);
	if (elements <= 4)
	{
		merge_to_a(stacks, st_tr);
		return (free(st_tr));
	}
	while ((st_tr -> merge_size < elements) && 
		(st_tr -> merge_size < INT_MAX / 2))
		merge_level(stacks, st_tr);
	if ((st_tr -> size a) && (st_tr -> size_b))
		merge_to_a(stacks, st_tr);
	free(st_tr);
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
	st_tr -> unmerged_a = st_tr -> size_a;
	st_tr -> unmerged_b = st_tr -> size_b;
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
	while ((el_b--) && (stacks -> stacks[0]->head))
	{
		while ((i++ <= el_a) && 
			((stack->stacks[1]->head->val) > (stacks->stacks[0]->head->val)))
		{
			exec(stacks, 5);
			pos++;
		}
		exec(stacks, 3);
		(st_tr -> size_b)--;
		(st_tr -> size_a)++;
		(st_tr -> unmerged_b)--;
	}
	st_tr -> unmerged_a -= el_a;
	while (pos--)
		exec(stacks, 8);
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
	while ((el_a--) && (stacks -> stacks[0]->head))
	{
		while ((i++ <= el_b) && 
			((stack->stack[0]->head->val) > (stacks->stacks[1]->head->val)))
		{
			exec(stacks, 6);
			pos++;
		}
		exec(stacks, 4);
		(st_tr -> size_b)--;
		(st_tr -> size_a)++;
		(st_tr -> unmerged_b)--;
	}
	(st_tr->unmerged_a) -= el_a;
	while (pos--)
		exec(stacks, 9);
}
