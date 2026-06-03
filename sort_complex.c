/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:27:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/03 18:05:09 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "stack.h"

// --- DOC ---

/*
	tried to pseudocode merge sort 
	... reached a dead end.
	... max rotations when merging would be worst case n^2
*/

// --- prototype ---

void	func0(void);
void	merge(t_stack dest, t_stack sec, int ms);
void	utility2(void);
void	utility3(void);
void	utility4(void);

// --- define ---

void	func0(void)
{
	// to create a merged stack of four elemnts:
	//	 pb first two elements
	//	 sort first two elemnts of b
	//	 sort first two elements of a
	//	 merge first two elements of a and first two elements of b in a
	//	 probably source out the merging to a function
	// continue to sort and merge the next <= 4 elements stack
	// than continue to sort and merge the next <= 8 elements stack
	// ...
	// recursion ??? ...
}

// --- utilities ---

/*ms: merge size: max size of the resulting stack: allways even */

/*
	 merge deeps in dest (stack b) [ms / 2]
	 merge deeps in sec  (stack a) <= [ms / 2]
	 keep track of the rotatios and ([new]: not) rotate back everytime

	 new estimation:
		 worst case !simplified!:	rotations 2 * (ms / 2) + ms
									pushes ms / 2

		--> O(n)	for merge yeah I was an Idiot^^
*/

void	merge(t_stack *dest, t_stack *sec, int ms)
{

	int	pos;
	int	i;
	int	left;

	pos = 0;
	i = 0;
	left = (ms / 2)
	while ((left--) && (sec -> head))
	{
		while (i++ <= (ms / 2) && (sec -> head -> val < dest -> head -> val))
		{
			// exec rb 1 time
			pos++;
		}
		// exec pb 1 time;
	}
	while (pos--)
		//exec rrb 1 time
}

/*	...you comment... */

void	utility2(void)
{
	// code
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

