/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:10:38 by rcollet           #+#    #+#             */
/*   Updated: 2026/06/03 15:12:54 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "stack.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

void	func0(void);
void	sort_bucket(t_stack_frame stack, int bs);
int		ft_sqrt(int nb);

// --- define ---

/*lexxy's first scratchnotes*/

void	func0(void)
{
	// int	stack size;
	// int	buckets;
	// int	last_bucket init with 0;

	// get bucket size
	//	 if sqrt(stack_size) --> sqrt
	//	 else get the next closest sqrt and have one extra bucket
	//		--> buckets + 1 (calculating bucket size leftover)
	// loop
	//	 use min extraktion to extract first [bucketsize] elements
	//	 sort stack by insertion sort : descending
	// if leftover bucket:
	//	 use insertion sort on stack a : ascending
	// calling pa [size stack b] times
}

/*
TODO: 	implement either sort last bucket (ascending not descanding) 
		or add another param in sort bucket
		of course you could just push it to b and to the sorting, 
		but why should you do uneccesary operations? ^^
		consider to NULL poiner protect
*/

void	sort_bucket(t_stack_frame stack, int bs)
{
	//int	i;

	// i = 0
	// do nothing if bs is 1
	// consider first element as sorted
	while (i++ < bs)
	{
		// rotate to bucket index i
		// pa
		// rotate stack b until element fitting in (keep track)
		// pb
		// rotate back
	}
}


// --- utility ---

/*
TODO: refactor to get the closest srqt <= sqrt(nb)
*/

int	ft_sqrt(int nb)
{
	int				sqrt;
	int				start;
	unsigned int	power;

	start = 65536 / 2;
	sqrt = start;
	if (nb <= 0)
		return (0);
	while (start >= 1)
	{
		power = sqrt * sqrt;
		if (power == (unsigned int)(nb))
			return (sqrt);
		else if (power > (unsigned int)(nb))
			sqrt -= start / 2;
		else
			sqrt += start / 2;
		start /= 2;
	}
	return (0);
}
