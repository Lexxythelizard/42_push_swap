/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:37:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/06/05 14:36:27 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialises the interface, containing a filled stack a from argv and an
   empty stack b */

t_interface	*init(int argc, char **argv)
{
	int			*nums;
	t_interface	*rtrn;
	
	rtrn = malloc(16);
	if (!rtrn)
		return (NULL);
	nums = get_int_list(argv);
	if (!nums)
		return (NULL);
	rtrn -> stacks[0] = stack_init(nums, argc - 1);
	rtrn -> stacks[1] = stack_init(NULL, 0);
	rtrn -> funcs[0] = &sa;
	rtrn -> funcs[1] = &sb;
	rtrn -> funcs[2] = &ss;
	rtrn -> funcs[3] = &pa;
	rtrn -> funcs[4] = &pb;
	rtrn -> funcs[5] = &ra;
	rtrn -> funcs[6] = &rb;
	rtrn -> funcs[7] = &rr;
	rtrn -> funcs[8] = &rra;
	rtrn -> funcs[9] = &rrb;
	rtrn -> funcs[10] = &rrr;
	rtrn -> stats = NULL;
	free(nums);
	return (rtrn);
}

//	--- ravy original ---

/*
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
*/
