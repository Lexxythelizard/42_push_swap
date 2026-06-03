/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:27:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/03 16:20:28 by lenivorb         ###   ########.fr       */
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

/*	...you comment... */

void	merge(t_stack dest, t_stack sec, int ms)
{
	// merge deeps in dest (stack b) [ms / 2]
	// merge deeps in sec  (stack a) <= [ms / 2]
	// keep track of the rotatios and rotate back everytime
	// worst case !simplified! : (ms / 2 + ms) * (ms / 4) * 2

	//	 --> ms^2 rotations --> O(n) for merge....

	// too much .... can't do ....
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

