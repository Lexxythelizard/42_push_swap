/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:37:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/29 19:53:11 by lenivorb         ###   ########.fr       */
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
	rtrn -> a = stack_init(nums, argc - 1);
	rtrn -> b = stack_init(NULL, 0);
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
