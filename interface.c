/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:37:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/27 16:19:44 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialises the interface, containing a filled stack a from argv and an
   empty stack b */
t_interface	*init(int argc, char **argv)
{
	int			*nums;
	size_t		i;
	t_interface	*rtrn;
	
	rtrn = malloc(16);
	if (!rtrn)
		return (NULL);
	i = 0;
	nums = malloc(4 * argc);
	if (!nums)
		return (NULL);
	while (++i < argc)
		nums[i - 1] = ft_atoi(argv[i]);
	rtrn -> a = stack_init(nums, argc - 1);
	rtrn -> b = stack_init(NULL, 0);
	free(nums);
	return (rtrn);
}

/* TODO: 
	- Check for duplicate values (in argv!)						: DONE (4 function bc unclear)
																  moved in file: 
	- check for invalid (non-numeric + '-') inputs 				: DONE
    - implement utility functions for the interface operations 	: on it
	  (see exercise), there are already s, p, r and rr 
	  functions that work on stacks in stack.c 

*/

// === check for invalid (non-numeric + '-') inputs ===

/*
lxy_is_nbr_input_valid
	- Nullpointer guard
	- skipping whitespaces
	- skipping single sign
	- return is_numeric

	--> return 0 / 1
*/

int lxy_is_nbr_input_valid(const char *s)
{
	size_t	i;

	i = 0;
	if (!(s))
		return (0);
	while((s[i]) && (((s[i] >= 9) && (s[i] <= 13)) || (s[i] == 32)))
		i++;
	i += ((s[i] == 43) || (s[i] == 45));
	return (ft_isnumeric(s[i]));
}
