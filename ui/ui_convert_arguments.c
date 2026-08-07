/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_convert_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:14:37 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:14:39 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

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

	count_numbers() :

		count the valid numbers in argv

*/

// --- define ---

int	*get_int_list(const char **argv, int argc)
{
	int	*int_list;
	int	valid_nbrs;
	int	i;
	int	j;

	valid_nbrs = 0;
	i = 1;
	j = 0;
	int_list = NULL;
	if (argc < 2)
		return (int_list);
	while (i++ < argc)
		valid_nbrs += is_valid_nbr(argv[(i - 1)]);
	int_list = malloc(valid_nbrs * 4);
	if (!int_list)
		return (NULL);
	i = argc - valid_nbrs;
	while (i < argc)
	{
		int_list[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
	return (int_list);
}

int	count_valid_numbers(const char **argv, int argc)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i++ < argc)
		count += is_valid_nbr(argv[(i - 1)]);
	return (count);
}

/*
get_flag_values() reads the first two strings - if they exist - 
returns a value between 0 and 17 if args have been valid
NOTE: Please call is_args_valid() before to check argv
*/

int	get_flag_values(const char **argv, int argc)
{
	if (argc < 2)
		return (-1);
	if (argc < 3)
		return (get_flag_value(argv[1]));
	return (get_flag_value(argv[1]) + get_flag_value(argv[2]));
}

int	get_flag_value(const char *flag)
{
	char	*temp;
	int		ctrl;

	if (!flag)
		return (0);
	temp = ft_strtrim(flag, SPACES_STR);
	ctrl = 0;
	if (!temp)
		return (0);
	ctrl = (0
			+ 1 * (is_flag_simple(temp))
			+ 2 * (is_flag_medium(temp))
			+ 4 * (is_flag_complex(temp))
			+ 8 * (is_flag_adaptive(temp))
			+ 16 * (is_flag_bench(temp)));
	return (
		free_and_return_int((void *)(temp), ctrl));
}
