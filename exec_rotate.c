/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/28 19:20:56 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"
#include "push_swap.h"
#include "output.h"

// --- DOC ---

// --- proto ---

// --- define ---

void	exec_ra_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ra(stacks);
		(tracker -> ra)++;
		i++;
	}
	ft_putendl_fd(STR_RA, STDOUT);
}

void	exec_rb_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rb(stacks);
		(tracker -> rb)++;
		i++;
	}
	ft_putendl_fd(STR_RB, STDOUT);
}

void	exec_rr_n(t_interface *stacks, t_op_track *tracker, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rr(stacks);
		(tracker -> rr)++;
		i++;
	}
	ft_putendl_fd(STR_RR, STDOUT);
}
