/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:25:59 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/27 16:00:40 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
function compute_disorder(stack a):
	mistakes = 0
	total_pairs = 0
	for i from 0 to size(a)-1:
		for j from i+1 to size(a)-1:
			total_pairs += 1
			if a[i] > a[j]:
				mistakes += 1
	return mistakes / total_pairs

--> see : VI.3.2 Disorder metric (mandatory)
*/

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
