/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"

// --- prototype ---

static int	count_repitition_of_flags(const char **argv, int argc);

// --- define ---

int	is_args_valid(const char **argv, int argc)
{
	int	i;
	int	flags;

	if (argc < 2)
		return (0);
	if (is_empty_str_in_arr(argv, argc))
		return (0);
	flags = count_repitition_of_flags(argv, argc);
	i = flags + 1;
	if (flags > 2)
		return (0);
	while (i < argc)
	{
		if (!(is_valid_nbr(argv[i])))
			return (0);
		i++;
	}
	if (flags == 2)
		return (is_flag_combination_valid(argv, argc));
	return (1);
}

static int	count_repitition_of_flags(const char **argv, int argc)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < argc)
	{
		count += is_valid_flag(argv[i]);
		i++;
	}
	return (count);
}
