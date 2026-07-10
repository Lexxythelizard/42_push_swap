/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:07:03 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/09 13:56:41 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/stack_machine/stack_machine.h"

// --- define ---

int	is_args_valid(const char **argv, int argc)
{
	int	i;
	int	flags;

	if (argc < 2)
		return (0);
	i = 1;
	flags = count_repitition_of_flags(argv, argc);
	i += flags;
	while (i < argc)
	{
		if (!(is_valid_nbr(argv[i])))
			return (0);
		i++;
	}
	if ((flags == 2)) 
		return (is_unique_and_one_bench(argv, argc));
	return (1);
}
