/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:25:59 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/05 15:25:58 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Computes the disorder of stack a
   (i.e. the quota of pairs of numbers which are in the wrong order) */
float compute_disorder(t_stack_frame *a)
{
	int				mistakes;
	int				total_pairs;
	t_stack_frame	*curr;

	mistakes = 0;
	total_pairs = 0;
	if (!a)
		return (0.0);
	while (a != NULL)
	{
		curr = a -> next;
		while (curr != NULL)
		{
			if (a -> val > curr -> val)
				mistakes++;
			total_pairs++;
		}
		a = a -> next;
	}
	return ((float)(total_pairs / mistakes));
}
