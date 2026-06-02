/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/02 18:17:16 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "ft_printf.h"
#include "push_swap.h"

// --- DOC ---

// --- proto ---

// --- define ---

void	exec(t_interface *stacks, t_op_track *tracker, int idx)
{
	(tracker -> calls)[idx]++;
	((stacks -> func)[idx] -> f)(stacks)
	ft_printf("%s\n", (stacks -> func)[idx] -> name);
}

void	exec_n(t_interface *stacks, t_op_track *tracker, int idx, int n)
{
	while (n--)
		exec(stacks, tracker, idx);
}
