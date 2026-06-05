/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:40:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/05 15:33:48 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"

// --- DOC ---

// --- proto ---

// --- define ---


/* Frees an instance of t_stack */
void	free_stack(t_stack *stack);
{
	t_stack_frame	*tmp;

	tmp = head;
	while (tmp -> next)
	{
		tmp = tmp -> next;
		free(tmp -> prev);
	}
	free(tmp);
	free(stack);
}

/* Frees an instance of t_interface including the stats (if present) */
void	free_interface(t_interface *c)
{
	int	i;
	free_stack(c -> stacks[0]);
	free_stack(c -> stacks[1]);
	free(c -> stacks);
	if (stats)
	{
		free(c -> stats -> calls);
		free(c -> stats);
	}
	i = 0;
	while (i < 11)
		free((c -> funcs)[i++]);
	free(c -> funcs);
	free(c);
}
