/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/28 19:22:42 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"
#include "push_swap.h"
#include "output.h"

// --- DOC ---

// --- proto ---

// --- define ---

void	exec_rra_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rra(stacks);
		(tracker -> rra)++;
		i++;
	}
	ft_putendl_fd(STR_RRA, STDOUT);
}

void	exec_rrb_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rrb(stacks);
		(tracker -> rrb)++;
		i++;
	}
	ft_putendl_fd(STR_RRB, STDOUT);
}

void	exec_rrr_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rrr(stacks);
		(tracker -> rrr)++;
		i++;
	}
	ft_putendl_fd(STR_RRR, STDOUT);
}
