/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:07:03 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/29 17:14:15 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"
#include "ui_cli.h"

// --- DOC ---


// --- define ---

int	is_args_valid(const char **argv)
{
	size_t	i;

	i = 0;
	if (!(argv))
		return (0);
	while (argv[i] != NULL)
	{
		if ((!(is_valid_nbr(argv[i]))) || (!(is_valid_flag(argv[i]))))
			return (0);
		i++;
	}
	return (1);
}


/*
is_valid_nbr
	- Nullpointer guard
	- skipping whitespaces
	- skipping single sign
	- return is_numeric

	--> return 0 / 1
*/

int is_valid_nbr(const char *s)
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


/*
all the flags should work, regafrdess lenghts
the orfer doesn't matter
flags should be overwritten by 'contra' flags (--simple , arg, ... --complex)
	--> --complex
*/

int	is_valid_flag(const char *s)
{
	if (!(is_flag))
		return (0);
	return ((!(ft_strncmp(s, FLAG_BENCH))) || 
		(!(ft_strncmp(s, FLAG_SIMPLE))) || 
		(!(ft_strncmp(s, FLAG_MEDIUM))) || 
		(!(ft_strncmp(s, FLAG_COMPLEX))) || 
		(!(ft_strncmp(s, FLAG_ADAPTIVE))));
}

int	is_flag(const char *s)
{
	if ((s[0]) && (s[1]))
		return ((s[0] == 43) && (s[1] == 43));
	return (0);
}
