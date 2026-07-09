/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/09 13:46:16 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/stack_machine/stack_machine.h"

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

	n/2 + 2 * (n/2 -1) + 2 * (n/2 - 2) + ... + 1
	= (n + (n-1) + (n-2) + ... + 1) / 2 - n / 4
	= n^2/4 if even, or (n^2 - 1)/4 if n is odd
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

int	sort_simple(t_interface *stacks)
{
	int	size;
	int	idx_min;

	if ((!(stacks)) || (!(stacks -> stacks[0])) || 
		(!(stacks -> stacks[1])) || (!(stacks -> stats)))
		return (-1);
	size = get_stack_size(stacks -> stacks[0]);
	idx_min = 0;
	if (!(size))
		return (0);
	while (size-- > 0)
	{
		idx_min = get_nth_min_idx(stacks -> stacks[0], 1);
		if (idx_min > (int)(size / 2))
			exec_n(stacks, 5, (size - idx_min));
		else 
			exec_n(stacks, 8, idx_min);
		exec(stacks, 4);
	}
	size = get_stack_size(stacks -> b);
	exec_n(stacks, 3, size);
	return (1);
}
