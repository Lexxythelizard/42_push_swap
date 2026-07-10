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

int	count_repitition_of_flags(const char **argv, int argc)
{
	int	count;

	count = 0;
	if (argc < 2)
		return (count);
	count += is_valid_flag(argv[1]);
	if (argc < 3)
		return (count);
	count += is_valid_flag(argv[2]);
	return (count);
}

int	is_unique_and_one_bench(const char **argv, int argc)
{
	if (argc < 2)
		return (0);
	if (argc < 3)
		return (is_valid_flag(argv[1]));
	if (ft_strncmp(argv[1], argv[2], 11)) 
		return (0);
	if (ft_strncmp(argv[1], FLAG_BENCH, 11))
		return (1);
	if (ft_strncmp(argv[2], FLAG_BENCH, 11))
		return (1);
	return (0);
}

int	is_valid_flag(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return ((!(ft_strncmp(s, FLAG_BENCH, 11))) || 
		(!(ft_strncmp(s, FLAG_SIMPLE, 11))) || 
		(!(ft_strncmp(s, FLAG_MEDIUM, 11))) || 
		(!(ft_strncmp(s, FLAG_COMPLEX, 11))) || 
		(!(ft_strncmp(s, FLAG_ADAPTIVE, 11))));
}

int	is_any_flag(const char *s)
{
	if ((s[0]) && (s[1]))
		return ((s[0] == 45) && (s[1] == 45));
	return (0);
}
