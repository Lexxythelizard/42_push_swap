/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:25:04 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 21:07:34 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include <[statlib].h>

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

int	raise_error(void);

// --- run ---

int	main(int argc, char **argv)
{
	t_interface	*stacks;

	int	*numbers;
	if (!argc) || !(is_args_valid(argv))
		return (raise_error);
	stacks = init(argv);
	if (!stacks)
		return (raise_error);
	run_sort(stacks);
	free_interface(stacks);
}

// --- define ---

int	raise_error(void)
{
	ft_putendl_fd("Error", STDERR);
	return (STDERR);
}

