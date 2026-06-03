/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:27:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/03 21:50:28 by lenivorb         ###   ########.fr       */
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
void	push_sort(t_interface stacks, t_op_track *tracker, int n);
void	push_back(t_interface stacks, t_op_track *tracker, int n);
int		*get_sequence(t_interface stacks);

// --- define ---

void	func0(t_interface stacks, t_op_track *tracker)
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

	// IDEA: 
	/*
		istead of doing it recursively by 'splitting' the size every time

		start to push and sort 2 elements, next to elements merge to four ...
		and so on
		right side sorted side (stack b) will grow constantly
		my inspireation was: https://www.youtube.com/watch?v=ZRPoEKHXTJg 
		
		to do that I thought of creating a numerical sequence 
		related to function calls
		
		2 2 2 4 2 2 2 4 4 8 2 2 2 4 2 2 2 4 4 8 8 16 2 2 2 4 ...
		p p b m p p b m b m p p b m p p b m b m b m  p p b m ...

		p : 'push' - push n elements to b and swap sort (n = 2)
		b : 'back' - push n elements back to a
		m : 'merge' - sides to <= n elements --> dest stack b

		rythm:	if n two : p, p, b
				else	 : m, b, m, b, ...

		in that case merge() needs to get modified 
		pushing back changes order ascending <--> descending ...

		--> alternatively we just modify b: back() 					<== I decided to do this
		this would mean plus rotations <-- 
	*/
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

void	merge(t_interface stacks, t_op_track *tracker, int ms)
{

	int	pos;
	int	i;
	int	left;

	pos = 0;
	i = 0;
	left = (ms / 2)
	while ((left--) && (stacks -> a -> head))
	{
		while (i++ <= (ms / 2) && 
		((stack -> a -> head -> val) < (stacks -> b -> head -> val)))
		{
			exec(stacks, tracker, 6);		// exec rb 1 time
			pos++;
		}
		exec(stacks, tracker, 4);			// exec pb 1 time;
	}
	while (pos--)
		exec(stacks, tracker, 9);			// exec rrb 1 time
}

/*	0 <= n <= 2 */

void	push_sort(t_interface stacks, t_op_track *tracker, int n)
{
	int	two;

	two = (n == 2);
	if ((!(stacks -> a -> head)) || (!(n)) || (n > 3))
		return ;
	while (n--)
	{
		if (!(stacks -> a -> head))
			return ;
		exec(stacks, tracker, 4);			// exec pb 1 time
	}
	if ((two) && ((stacks -> b -> head) < (stacks -> b -> tail -> val)))
		exec(stacks, tracker, 1);			// exec sb 1 time
}

/*	pushes back this way to keep the descending order and make merge easier */

void	push_back(t_interface stacks, t_op_track *tracker, int n)
{
	if (n <= 0)
		return ;
	exec_n(stacks, tracker, 6, (n - 1));           // exec rb n times
	while (n--)
	{
		exec(stacks, tracker, 6);           // exec pa 1 time
		exec(stacks, tracker, 9);           // exec rrb 1 time
	}
}

/*	...you comment... */

int	*get_sequence(t_interface stacks)
{
	// int var
	// int var

	
	if ((!(stacks)) || (!(stacks -> a -> head)))
		return (NULL);
	// some algorythm ;)

	// return (sequence);
}

