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

int	is_numbers_unique(int *list, int len)
{
	if (1)
		return (is_numbers_unique_simple(list, len));
	return (is_numbers_unique_simple(list, len));
}

/*
refactored: now:								24 lines :)
	- works with flag counter
	- if iteration neither flag nor nbr 		--> 0
	- flags are just allowed as first two args	--> 0
	- if 2 flags and both are not --bench 		-->	0
	- if both flags are identicall				--> 0
	- if there are mor then two flags			--> 0
*/

int	is_args_valid(const char **argv)
{
	int	i;
	int	flags;

	i = (-1);
	flags = 0;
	if (!(argv))
		return (0);
	while (argv[i++] != NULL)
	{
		if ((!(is_valid_nbr(argv[i]))) && (!(is_valid_flag(argv[i]))))
			return (0);
		if (is_valid_flag(argv[i]))
			flags++;
	}
	if ((flags == 1) && (!(is_valid_flag(argv[0]))))
		return (0);
	if ((flags == 2) && 
		(!((is_valid_flag(argv[0])) && (is_valid_flag(argv[1])))))
		return (0);
	if ((flags == 2) && (ft_strncmp(argv[0], FLAG_BENCH, 11)) && 
		(ft_strncmp(argv[1], FLAG_BENCH, 11)))
		return (0);
	if ((flags == 2) && (!(ft_strncmp(argv[0], argv[1], 11))))
		return (0);
	return (flags <= 2);
}

/*
is_valid_nbr
	- Nullpointer guard
	- skipping whitespaces
	- skipping single sign
	- return is_numeric

	--> return 0 / 1
*/

int	is_valid_nbr(const char *s)
{
	size_t	i;

	i = 0;
	if (!(s))
		return (0);
	while ((s[i]) && (((s[i] >= 9) && (s[i] <= 13)) || (s[i] == 32)))
		i++;
	i += ((s[i] == 43) || (s[i] == 45));
	return (ft_isdigit(s[i]));
}

/*
all the flags should work, regafrdess lenghts
the orfer doesn't matter
flags should be overwritten by 'contra' flags (--simple , arg, ... --complex)
	--> --complex
*/

int	is_valid_flag(const char *s)
{
	if (!(is_flag(s)))
		return (0);
	return ((!(ft_strncmp(s, FLAG_BENCH, 11))) || 
		(!(ft_strncmp(s, FLAG_SIMPLE, 11))) || 
		(!(ft_strncmp(s, FLAG_MEDIUM, 11))) || 
		(!(ft_strncmp(s, FLAG_COMPLEX, 11))) || 
		(!(ft_strncmp(s, FLAG_ADAPTIVE, 11))));
}

int	is_flag(const char *s)
{
	if ((s[0]) && (s[1]))
		return ((s[0] == 43) && (s[1] == 43));
	return (0);
}
