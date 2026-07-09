/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:10:38 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/09 16:02:09 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/stack_machine/stack_machine.h"

// --- define ---

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

/*ravy's implementation*/

void	sort_medium(t_stack_machine *machine)
{
	int	stack_size;
	int	bucket_size;
	int	bucket_max;
	int	i;

	stack_size = get_stack_size(&(machine -> stacks[0]));
	bucket_size = ft_sqrt(stack_size);
	while (stack_size >= bucket_size)
	{
		i = 0;
		stack_size -= bucket_size;
		bucket_max = get_nth_min(&(machine -> stacks[0]), bucket_size);
		while (i < bucket_size)
		{
			exec(machine, 5);
			if (machine -> stacks[0].first -> val <= bucket_max)
			{
				i++;
				exec(machine, 4);
			}
		}
		sort_bucket(machine, bucket_size, 1);
	}
	sort_bucket(machine, stack_size, 0);
	exec_n(machine, 3, get_stack_size(&(machine -> stacks[1])));
}

/*
TODO: 	implement either sort last bucket (ascending not descanding) 
		or add another param in sort bucket
		of course you could just push it to b and to the sorting, 
		but why should you do uneccesary operations? ^^
		consider to NULL poiner protect
*/

void	sort_bucket(t_stack_machine	*machine, int bs, int side)
{
	t_element	*start;
	t_element	*end;
	int			i;

	i = 0;
	start = (machine -> stacks)[side].first;
	end = start;
	while (i++ < bs)
		end = end -> next;
	while ((machine -> stacks)[side].first != end)
	{
		if ((stack_comp(&((machine -> stacks)[side])) + side) % 2)
		{
			exec(machine, side);
			exec(machine, 8 + side);
		}
		else
			exec(machine, 5 + side);
	}
	while (i--)
		exec(machine, 8 + side);
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
		if (power > (unsigned int)(nb))
			sqrt -= step;
		else
			sqrt += step;
		step /= 2;
	}
	if (power > (unsigned int)nb)
		sqrt--;
	return (sqrt);
}
