/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:37:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/26 13:03:08 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialises the interface, containing a filled stack a from argv and an
   empty stack b */
t_interface	*init(int argc, char **argv)
{
	int		*nums;
	size_t	i;
	
	argc--;
	i = 0;
	nums = malloc(4 * argc);
	if (!nums)
		return (NULL);
	while (i < argc)
	{
	}
	free(nums);
}

/* TODO: Check for duplicate values, check for invalid (non-numeric + '-') inputs,
   implement utility functions for the interface operations (see exercise), 
   there are already s, p, r and rr functions that work on stacks in stack.c */
