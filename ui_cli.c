/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cli.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:12:11 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/29 19:51:04 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"
#include "ui_cli.h"

// --- DOC ---

/*
	NOTE:

	!!! Please run is_args_valid(argv) first !!!
	Order of the flags and numbers could be arbitary

	FUNC:

	get_int_list() :

		count the valid numbers in argv and allocates an int array
		order of flags and numbers could be arbitary
		use ft_atoi to convert;

	get_flag_list() :

		count the valid flags in argv and allocates a NULL terminated array
		flags n + 1 
		order of flags and numbers could be arbitary
		use ft_strdup;

	count_numbers() :

		count the valid numbers in argv

	count_flags() :

		count the valid flags in argv
*/

// --- proto ---

// --- define ---

int	*get_int_list(const char **argv)
{

	char 	*int_list;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	int_list = malloc(count_numbers(argv) * 4);
	if (!(flag_list))
		return (NULL);
	while (argv[i++])
	{
		if (is_valid_number(argv[(i - 1)]))
		{
			int_list[j] = ft_atoi(argv[(i - 1)]);
			j++
		}
	}
	return (int_list);
}

char **get_flag_list(const char **argv)
{
	char 	**flag_list;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	flag_list = calloc_char_arr(count_flags(argv) + 1);
	if (!(flag_list))
		return (NULL);
	while (argv[i++])
	{
		if (is_valid_flag(argv[(i - 1)]))
		{
			flag_list[j] = ft_strdup(argv[(i - 1)]);
			if (!(flag_list[j]))
			{
				free_str_array(flag_list);
				return (NULL);
			}
			j++;
		}
	}
	return (flag_list)
}


size_t	count_numbers(const char **argv)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (argv[i++])
		count += (is_valid_nbr(argv[(i - 1)]));
	return (count);
}

size_t count_flags(const char **argv)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (argv[i++])
		count += (is_valid_flag(argv[(i - 1)]));
	return (count);
}
