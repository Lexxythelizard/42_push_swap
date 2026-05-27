/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:25:59 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/27 13:59:13 by lenivorb         ###   ########.fr       */
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

float compute_disorder(t_stack *stack_a)
{
	t_stack_frame	ptr_a;
	t_stack_frame	ptr_b;
	int				checked;
	int				non_asc;

	if ((!(stack_a)) || (!(stack_a -> head)))
		return (-1.0);
	ptr_a = stack_a -> head;
	while (ptr_a -> next != NULL)
	{
		ptr_b = ptr_a -> next;
		while (ptr_b -> next != NULL)
		{
			ptr_b = ptr_b -> next;
			non_asc += (ptr_a -> val > ptr_b -> val);
			checked++;
		}
		ptr_a = ptr_a -> next;
	}
	return ((float)(non_asc / checked));
}
