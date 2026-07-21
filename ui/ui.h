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

# define ERR_STR "Error"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

// --- prototypes ---

struct s_stats;

// ui_calculate_entropy.c

float			calculate_entropy(int *arr, int len);

// ui_convert_arguments.c

int				*get_int_list(const char **argv, int argc);
int				count_valid_numbers(const char **argv, int argc);
int				get_flag_values(const char **argv, int argc);
int				get_flag_value(const char *flag);

// ui_validate_arguments.c

int				is_args_valid(const char **argv, int argc);

// ui_validate_arguments_numbers.c

int				is_numbers_unique(int *list, int len);
int				is_valid_nbr(const char *s);

// ui_validate_arguments_flags.c

int				is_valid_flag(const char *s);
int				count_repitition_of_flags(const char **argv, int argc);
int				is_unique_and_one_bench(const char **argv, int argc);
int				is_any_flag(const char *s);

// ui_output.c

int				put_error(void);
// --- end ---

#endif
