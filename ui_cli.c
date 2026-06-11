/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_cli.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:12:11 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 18:21:07 by lenivorb         ###   ########.fr       */
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

	count_numbers() :

		count the valid numbers in argv

*/

// --- proto ---

int	*get_int_list(const char **argv);
int get_flag_values(const char **argv);
int	get_flag_value(const char *flag);
int	count_numbers(const char **argv);

// --- define ---

int	*get_int_list(const char **argv)
{

	int		*int_list;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!argv)
		return (NULL);
	int_list = malloc(count_numbers(argv) * 4);
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

/*
get_flag_values() reads the first two strings - if they exist - 
returns a value between 0 and 17 if args have been valid
NOTE: Please call is_args_valid() before to check argv
*/

int get_flag_values(const char **argv)
{
	int	flag;

	flag = 0;
	if (!argv)
		return (-1);
	if ((argv[0]) && (is_valid_flag(argv[0])))
		flag += get_flag_value(argv[0]);
	if ((argv[1]) && (is_valid_flag(argv[1])))
		flag += get_flag_value(argv[1]);
	return (flag);
}

int	get_flag_value(const char *flag)
{
	int	flag;

	if (!flag)
		return (-1);
	return (
		1 * (!(ft_strncmp(s, FLAG_SIMPLE)) +  
		2 * (!(ft_strncmp(s, FLAG_MEDIUM))) +  
		4 * (!(ft_strncmp(s, FLAG_COMPLEX))) +  
		8 * (!(ft_strncmp(s, FLAG_ADAPTIVE))) + 
		16 * (!(ft_strncmp(s, FLAG_BENCH)))); 
}

int	count_numbers(const char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (argv[i++])
		count += (is_valid_nbr(argv[(i - 1)]));
	return (count);
}
