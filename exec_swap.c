/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/28 14:10:37 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"
#include "push_swap.h"

// --- DOC ---

// --- proto ---

// --- define ---

void	exec_sa_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		sa(stacks);
		(tracker -> sa)++;
		i++;
	}
}

void	exec_sb_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		sb(stacks);
		(tracker -> sb)++;
		i++;
	}
}

void	exec_ss_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ss(stacks);
		(tracker -> ss)++;
		i++;
	}
}
