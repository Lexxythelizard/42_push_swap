/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 2026/08/05 16:46:43 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include <stddef.h>

// --- Makros ---

# define FLAG_NULL     "--"
# define FLAG_BENCH     "--bench"
# define FLAG_SIMPLE    "--simple"
# define FLAG_MEDIUM    "--medium"
# define FLAG_COMPLEX   "--complex"
# define FLAG_ADAPTIVE  "--adaptive"

# define SPACES_STR  "\t\n\v\f\r "

# define ERR_STR "Error"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

// --- prototypes ---

struct	s_stats;

// ui_calculate_entropy.c

float	calculate_entropy(int *arr, int len);

// ui_free_and_return.c

int		free_and_return_int(void *ptr, int i);
void	*free_and_return_any_ptr(void *ptr, void *address);

// ui_convert_arguments.c

int		*get_int_list(const char **argv, int argc);
int		count_valid_numbers(const char **argv, int argc);
int		get_flag_values(const char **argv, int argc);
int		get_flag_value(const char *flag);

// ui_validate_arguments.c

int		is_args_valid(const char **argv, int argc);

// ui_validate_arguments_compare.c

int		is_str_equal_to_str(const char *s1, const char *s2);
int		is_begin_with_double_dash(const char *s);

// ui_validate_arguments_digits.c

int		is_digits_str(const char *s);

// ui_validate_arguments_empty.c

int		is_empty_str(const char *s);
int		is_empty_str_in_arr(const char **argv, int argc);

// ui_validate_arguments_spaces.c

int		is_space(int c);
int		is_space_str(const char *s);
int		is_space_str_in_arr(const char **argv, int argc);

// ui_validate_arguments_numbers.c

int		is_numbers_unique(int *list, int len);
int		is_valid_nbr(const char *s);
int		is_number_within_int_range(const char *s);

// ui_validate_arguments_flags.c

int		is_valid_flag(const char *s);
int		is_flag_combination_valid(const char **argv, int argc);
int		is_any_flag(const char *s);

// ui_validate_arguments_flags_command_flags.c

int		is_command_flag(const char *s);
int		is_flag_simple(const char *s);
int		is_flag_medium(const char *s);
int		is_flag_complex(const char *s);
int		is_flag_adaptive(const char *s);

// ui_validate_arguments_flagsdisplay_flags.c

int		is_display_flag(const char *s);
int		is_flag_bench(const char *s);

// ui_output.c

int		put_error(void);

// --- end ---

#endif
