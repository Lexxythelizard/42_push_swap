/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/28 14:11:41 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"
#include "push_swap.h"

// --- DOC ---

// --- proto ---

// --- define ---

void	exec_pa_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pa(stacks);
		(tracker -> pa)++;
		i++;
	}
}

void	exec_pb_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pb(stacks);
		(tracker -> pb)++;
		i++;
	}
}
