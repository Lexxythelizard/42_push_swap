/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_argparsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:28:12 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/05 20:11:45 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/stack_machine/stack_machine.h"

#define TEST0 "-"
#define TEST1 "--"
#define TEST2 "--hello"
#define TEST3 "--simple"
#define TEST4 "--bench"
#define TEST5 "-0"
#define TEST6 "0"
#define TEST7 "+0"
#define TEST8 "a"
#define TEST9 "2a"
#define TEST10 "    -3"

// --- DOC ---

/*
	TODO:
		- test:			is_flag					:
		- test:			is_valid_flag			:
		- test:			is_valid_nbr			:
		- test:			is_args_valid			:
*/

// --- prototype ---

void	check_valid_flag(const char *s)
void	check_valid_nbr(const char *s)
void	check_is_flag(const char *s)

// --- run ---

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (-1);
	ft_printf("\n++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	ft_printf("test: cases and validation functions\n");

	ft_printf("test: %s\n", TEST0);
	check_is_flag(TEST0);
	check_valid_flag(TEST0);
	check_valid_number(TEST0);

	ft_printf("test: %s\n", TEST1);
	check_is_flag(TEST1);
	check_valid_flag(TEST1);
	check_valid_number(TEST1);

	ft_printf("test: %s\n", TEST2);
	check_is_flag(TEST2);
	check_valid_flag(TEST2);
	check_valid_number(TEST2);

	ft_printf("test: %s\n", TEST3);
	check_is_flag(TEST3);
	check_valid_flag(TEST3);
	check_valid_number(TEST3);

	ft_printf("test: %s\n", TEST4);
	check_is_flag(TEST4);
	check_valid_flag(TEST4);
	check_valid_number(TEST4);

	ft_printf("test: %s\n", TEST5);
	check_is_flag(TEST5);
	check_valid_flag(TEST5);
	check_valid_number(TEST5);

	ft_printf("test: %s\n", TEST6);
	check_is_flag(TEST6);
	check_valid_flag(TEST6);
	check_valid_number(TEST6);

	ft_printf("test: %s\n", TEST7);
	check_is_flag(TEST7);
	check_valid_flag(TEST7);
	check_valid_number(TEST7);

	ft_printf("test: %s\n", TEST8);
	check_is_flag(TEST8);
	check_valid_flag(TEST8);
	check_valid_number(TEST8);

	ft_printf("test: %s\n", TEST9);
	check_is_flag(TEST9);
	check_valid_flag(TEST9);
	check_valid_number(TEST9);

	ft_printf("test: %s\n", TEST10);
	check_is_flag(TEST10);
	check_valid_flag(TEST10);
	check_valid_number(TEST10);

	ft_printf("----------------------------------------------\n");
	ft_printf("test: passed arguments:\n");
	while (i++ < argc)
		ft_printf("\"%s\" ", argv[(i - 1)]);
	ft_printf("\n\n");
	/*
	ft_printf("test every argument seperately\n\n");
	*/
	ft_printf("is args valid: %d\n", is_args_valid(argv + 1));
	ft_printf("\n++++++++++++++++++++++++++++++++++++++++++++++\n");
	return (0);
}

// --- define ---

void	check_valid_flag(const char *s)
{
	ft_printf("is valid flag: %d\n", is_valid_flag(s));
}

void	check_valid_nbr(const char *s)
{
	ft_printf("is valid nbr: %d\n", is_valid_nbr(s));
}

void	check_is_flag(const char *s)
{
	ft_printf("is flag: %d\n", is_valid_flag(s));
}

/*
void	check_valid_flag(const char *s)
{
	ft_printf("is args valid: %d", is_valid_flag(s));
}
*/
