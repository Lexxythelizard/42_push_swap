/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/28 19:18:16 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"

// --- DOC ---

/*
TODO:

	- implement all the exec_s* functions					: DONE
	- implement all the exec_p* functions					: DONE
	- implement all the exec_r* functions					: DONE
	- implement all the exec_rr* functions					: DOM
*/

/*
	SCRATCHNOTES:

	!!! use size + 1 !!!
	get index maximum
	if index maximum > size / 2	ra size - index + 1 times
	else 						rra size - index    times
	anyway	add to op_tracker
	finally 					pb 			1 		times
	add to op_tracker						
*/

/*
idea:

	- count the elements in the stack
	- while there are elements in the stack
		- find the position of the smallest value
		- mov it to the top 
			(decide if ra or rra)	*1
		- push it to b
	- push the sorted stack b back to a --> a is ascending

	*1 because we can rotate in both directions:

	max rotations: (n / 2 + 1) * (n / 2 / 2) * 2 
			-->	   (n / 2 + 1) * (n / 2)			if n is even
	pa:				n
	pb:				n

	stack of 100 elements:	max 2550 rotations		<-- TOO MUCH
							max 200 pushes

	PS: F*ck I'm very sorry, yesterday in my head I calculated 255
	instead of 2550 rotations

	just used the pocket calculator while typing it, 
	after I implemented the sort_simple 

	Classic Lexxy ;)
*/

// --- define ---

int	sort_simple(t_op_track *tracker, t_interface *stacks)
{
	int	size;
	int	idx_min;

	if ((!(op_track)) || (!(stacks)) || (!(stacks ->a )) || (!(stacks -> b)))
		return (-1);
	size = get_stack_size(stacks -> a);
	idx_min = 0;
	if (!(size))
		return (0);
	while (size-- > 0)
	{
		idx_min = get_index_min_val(stacks -> a);
		if (idx_min > (int)(size / 2))
			call exec_ra_n(stacks, tracker, (size - idx_min));
		else 
			exec_rra_n(stacks, tracker, idx_min);
		exec_pb_n(stacks, tracker, 1);
	}
	size = get_stack_size(stacks -> b)
	exec_pa_n(stacks, tracker, size);
	return (1);
}
