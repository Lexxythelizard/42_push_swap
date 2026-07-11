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
		- test:			is_flag					: DOME
		- test:			is_valid_flag			: DONE
		- test:			is_valid_nbr			: DONE
		- test:			is_args_valid			: DONE
		- test:			2a not valid number		: DONE
*/

// --- prototype ---

void	check_valid_flag(const char *s);
void	check_valid_nbr(const char *s);
void	check_is_flag(const char *s);
void	check_get_flag_values(const char **argv, int argc);
void	check_count_valid_numbers(const char **argv, int argc);
void	check_int_array(int *arr, int len);
void	check_is_numbers_unique(int *arr, int len);
void	test_converted_flag_value(int flag_val);

// --- run ---

int	main(int argc, char **argv)
{
	int	i;
	int	*arr;

	i = 1;
	if (argc < 3)
		return (-1);
	ft_printf("\n++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	ft_printf("test: cases and validation functions\n");

	ft_printf("test: %s\n", TEST0);
	check_is_flag(TEST0);
	check_valid_flag(TEST0);
	check_valid_nbr(TEST0);

	ft_printf("test: %s\n", TEST1);
	check_is_flag(TEST1);
	check_valid_flag(TEST1);
	check_valid_nbr(TEST1);

	ft_printf("test: %s\n", TEST2);
	check_is_flag(TEST2);
	check_valid_flag(TEST2);
	check_valid_nbr(TEST2);

	ft_printf("test: %s\n", TEST3);
	check_is_flag(TEST3);
	check_valid_flag(TEST3);
	check_valid_nbr(TEST3);

	ft_printf("test: %s\n", TEST4);
	check_is_flag(TEST4);
	check_valid_flag(TEST4);
	check_valid_nbr(TEST4);

	ft_printf("test: %s\n", TEST5);
	check_is_flag(TEST5);
	check_valid_flag(TEST5);
	check_valid_nbr(TEST5);

	ft_printf("test: %s\n", TEST6);
	check_is_flag(TEST6);
	check_valid_flag(TEST6);
	check_valid_nbr(TEST6);

	ft_printf("test: %s\n", TEST7);
	check_is_flag(TEST7);
	check_valid_flag(TEST7);
	check_valid_nbr(TEST7);

	ft_printf("test: %s\n", TEST8);
	check_is_flag(TEST8);
	check_valid_flag(TEST8);
	check_valid_nbr(TEST8);

	ft_printf("test: %s\n", TEST9);
	check_is_flag(TEST9);
	check_valid_flag(TEST9);
	check_valid_nbr(TEST9);

	ft_printf("test: %s\n", TEST10);
	check_is_flag(TEST10);
	check_valid_flag(TEST10);
	check_valid_nbr(TEST10);

	ft_printf("----------------------------------------------\n");
	ft_printf("test: passed arguments:\n");
	while (i++ < argc)
		ft_printf("\"%s\" ", argv[(i - 1)]);
	ft_printf("\n\n");
	i = 0;
	ft_printf("is args valid: %d\n", is_args_valid((const char **)(argv), argc));
	check_get_flag_values((const char **)(argv), argc);
	check_count_valid_numbers((const char **)(argv), argc);
	ft_printf("\n");

	arr = get_int_list((const char **)(argv), argc);
	ft_printf("create int array   ");
	check_int_array(
		arr,
		count_valid_numbers((const char **)(argv), argc));
	test_converted_flag_value(get_flag_values((const char **)(argv), argc));
	ft_printf("\n");
	check_is_numbers_unique(
		arr,
		count_valid_numbers((const char **)(argv), argc));
	if (arr)
		free(arr);
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
	ft_printf("is any flag: %d\n", is_any_flag(s));
}

void	check_get_flag_values(const char **argv, int argc)
{
	ft_printf("flag values are: %d\n", get_flag_values(argv, argc));
}

void	check_count_valid_numbers(const char **argv, int argc)
{
	ft_printf("valid numbers are: %d\n", count_valid_numbers(argv, argc));
}

void	check_int_array(int *arr, int len)
{
	int	i;

	i = 0;
	ft_printf("display int array\n");
	if ((!arr) || (len <= 0))
	{
		ft_printf("%p\n", arr);
		return ;
	}
	while (i++ < len)
		ft_printf("idx: %d\tval: %d\n", (i - 1), arr[(i - 1)]);
	ft_printf("end\n\n");
}

void	check_is_numbers_unique(int *arr, int len)
{
	ft_printf("is_numbers unique: %d\n", is_numbers_unique(arr, len));
}

void	test_converted_flag_value(int flag_val)
{
	ft_printf("value %d means:\n", flag_val);
	if (flag_val / 16)
		ft_printf("%s was given\n", FLAG_BENCH);
	else
		ft_printf("%s NOT given\n", FLAG_BENCH);
	flag_val %= 16;	

	if (flag_val / 8)
		ft_printf("%s was given\n", FLAG_ADAPTIVE);
	else
		ft_printf("%s NOT given\n", FLAG_ADAPTIVE);
	flag_val %= 8;	

	if (flag_val / 4)
		ft_printf("%s was given\n", FLAG_COMPLEX);
	else
		ft_printf("%s NOT given\n", FLAG_COMPLEX);
	
	flag_val %= 4;	
	if (flag_val / 2)
		ft_printf("%s was given\n", FLAG_MEDIUM);
	else
		ft_printf("%s NOT given\n", FLAG_MEDIUM);

	flag_val %= 2;	
	if (flag_val / 1)
		ft_printf("%s was given\n", FLAG_SIMPLE);
	else
		ft_printf("%s NOT given\n", FLAG_SIMPLE);
	flag_val %= 1;
}
