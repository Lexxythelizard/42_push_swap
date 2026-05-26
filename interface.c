/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:37:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/26 17:35:59 by lenivorb         ###   ########.fr       */
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

/* TODO: 
	- Check for duplicate values								: unclear 
	- check for invalid (non-numeric + '-') inputs 				: DONE
    - implement utility functions for the interface operations 	: on it
	  (see exercise), there are already s, p, r and rr 
	  functions that work on stacks in stack.c 

*/

// === Check for duplicate values: unclear what you want me todo.... ===

// 	chould check if there are double values
int	lxy_has_duplicate_values(/*stack*/)
{
	//	--> O(n^2) or O(log(n)*n) with two pointers if my math is right
	// return 1 / 0
}

// 	chould it check if there are at least one double values in the list
int	lxy_is_doupled_values(t_stack_frame *node)
{
	//	--> O(n)
	// return 1 / 0
}

// 	chould check if there are double values
t_stack_frame	*lxy_get_duplicate_value(t_stack_frame *node)
{
	//	--> O(n)
	// returns a pointer to the node that has the same value or the node itself 
}

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
