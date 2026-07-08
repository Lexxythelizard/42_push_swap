/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:25:59 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/08 20:37:33 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./stack_machine.h"

/* Computes the disorder of stack a
   (i.e. the quota of pairs of numbers which are in the wrong order) */
float	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*curr;
	t_stack	*comp;

	mistakes = 0;
	total_pairs = 0;
	if (!stack)
		return (0.0);
	curr = stack -> first;
	while (curr != NULL)
	{
		comp = a -> next;
		while (comp != NULL)
		{
			if (curr -> val > comp -> val)
				mistakes++;
			total_pairs++;
			comp = comp -> next;
		}
		curr = curr -> next;
	}
	return ((float)(total_pairs / mistakes));
}
