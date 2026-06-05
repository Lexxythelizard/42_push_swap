/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:10:38 by rcollet           #+#    #+#             */
/*   Updated: 2026/06/05 14:49:08 by rcollet          ###   ########.fr       */
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

void	sort_medium(t_interface *stacks)
{
	int	stack_size;
	int	bucket_size;
	int	bucket_max;
	int	i;
	
	stack_size = get_stack_size(stacks -> a);
	bucket_size = ft_sqrt(stack_size);
	while (stack_size >= bucket_size)
	{
		i = 0;
		stack_size -= bucket_size;
		bucket_max = get_nth_min(stacks -> a, bucket_size);
		while (i < bucket_size)
		{
			exec(stacks, 5);
			if (stacks -> a -> head -> val <= bucket_max)
			{
				i++;
				exec(stacks, 4);
			}
		}
		sort_bucket(stacks, bucket_size, 1);
	}
	sort_bucket(stacks, stack_size, 0);
	exec_n(stacks, 3, get_stack_size(stacks -> b));
}

/*
TODO: 	implement either sort last bucket (ascending not descanding) 
		or add another param in sort bucket
		of course you could just push it to b and to the sorting, 
		but why should you do uneccesary operations? ^^
		consider to NULL poiner protect
*/

void	sort_bucket(t_interface	*c, int bs, int side)
{
	t_stack_frame	*start;
	t_stack_frame	*end;
	int				i;

	i = 0;
	start = (c -> stacks)[side] -> head;
	end = start;
	while (i++ < bs)
		end = end -> next;
	while ((c -> stacks)[side] -> head != end)
	{
		if ((stack_comp((c -> stacks)[side]) + side) % 2)
		{
			exec(c, side);
			exec(c, 8 + side);
		}
		else
			exec(c, 5 + side);
	}
	while (i--)
		exec(c, 8 + side);
}

// --- utility ---

/*
TODO: refactor to get the closest srqt <= sqrt(nb)
*/

int	ft_sqrt(int nb)
{
	int				sqrt;
	int				step;
	unsigned int	power;

	step = 16384;
	sqrt = step * 2;
	if (nb <= 0)
		return (0);
	while (step && power != (unsigned int)nb)
	{
		power = sqrt * sqrt;
		else if (power > (unsigned int)(nb))
			sqrt -= step;
		else
			sqrt += step;
		step /= 2;
	}
	if (power > (unsigned int)nb)
		sqrt--;
	return (sqrt);
}
