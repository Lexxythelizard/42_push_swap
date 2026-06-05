/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:33 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/05 14:49:49 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "ft_printf.h"
#include "push_swap.h"

// --- DOC ---

// --- proto ---

// --- define ---

void	exec(t_interface *stacks, int idx)
{
	(stacks -> stats -> calls)[idx]++;
	((stacks -> func)[idx] -> f)(stacks)
	ft_putendl((stacks -> func)[idx] -> name, 1);
}

void	exec_n(t_interface *stacks, int idx, int n)
{
	while (n--)
		exec(stacks, tracker, idx);
}
