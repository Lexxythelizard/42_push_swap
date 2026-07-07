/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:40:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/07 15:25:44 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- define ---

/* Frees an instance of t_stack */
void	free_stack(t_stack *stack)
{
	t_stack_frame	*tmp;

	tmp = stack -> head;
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

	free_stack(&(c -> stacks[0]));
	free_stack(&(c -> stacks[1]));
	free(c -> stacks);
	if (c -> stats)
	{
		free(c -> stats -> calls);
		free(c -> stats);
	}
	i = 0;
	while (i < 11)
		free(&((c -> funcs)[i++]));
	free(c -> funcs);
	free(c);
}
