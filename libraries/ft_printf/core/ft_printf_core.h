/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:44:49 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/03 16:16:38 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CORE_H
# define FT_PRINTF_CORE_H

// --- include ---

# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

// --- DOC ---

/*
	...you comment here...
*/

// --- Makros ---

# define STDOUT 1
# define HEXDEC_LO "0123456789abcdef"
# define HEXDEC_UP "0123456789ABCDEF"
# define DECDEC "0123456789"
# define NIL "(nil)"
# define NSTR "(null)"
# define HASH "0x"
# define HASH_UP "0X"

# define SSZ_MIN LONG_MIN
# define SSZ_MAX LONG_MAX

// --- struct ---

typedef struct s_flags
{
	int		hash;
	int		wsp;
	int		plus;
}			t_flags;

// --- prototype ---

// utils
int		lxy_put_unsigned_int_base(unsigned int u, const char *base);
int		lxy_put_unsigned_long_base(unsigned long lu, const char *base);
int		lxy_put_size_t_base(size_t zu, const char *base);
int		lxy_strlen(const char *s);

// specifiers
int		is_specifier(const char *s);
int		is_specifier_single(unsigned char c);
int		is_specifier_prefix(unsigned char c);
int		get_specifier_lenght(const char *s);

// scan
int		is_flag(unsigned char c);
int		is_percent(unsigned char c);
int		is_equal(const char *s1, const char *s2, int size);

// flags
t_flags	*init_flags(void);
void	clean_flags(t_flags *flags);

// process
int		process_specifier(
			t_flags *flags,
			va_list *args,
			const char *line,
			int *idx);
int		process_flagg(
			t_flags *flags,
			const char *line);

// call put function
int		call_put_func(const char *spec, va_list *args, t_flags *flags);

// get functions
int		(*get_char_func(const char *spec))(const char c);
int		(*get_string_func(const char *spec))(const char *s);
int		(*get_long_func(const char *spec))(long l, t_flags *flags);
int		(*get_ssize_t_func(const char *spec))(ssize_t z, t_flags *flags);
int		(*get_int_func(const char *spec))(int i, t_flags *flags);
int		(*get_ud_func(const char *spec))(unsigned int u, t_flags *flags);
int		(*get_lu_func(const char *spec))(unsigned long lu, t_flags *flags);
int		(*get_size_t_func(const char *spec))(size_t zu, t_flags *flags);

// put functions
int		lxy_put_char(const char c);
int		lxy_put_str(const char *s);

int		lxy_put_percent_sign(void);
int		lxy_put_trigger_hashflag(void);
int		lxy_put_trigger_hashflag_upper(void);
int		lxy_put_white_space(int n);

int		lxy_put_decimal(int dec, t_flags *flags);
int		lxy_put_undecimal(unsigned int udec, t_flags *flags);

int		lxy_put_signed_int(int i, t_flags *flags);
int		lxy_put_signed_long(long l, t_flags *flags);
int		lxy_put_ssize_t(ssize_t sz, t_flags *flags);
int		lxy_put_unsigned_int(unsigned int u, t_flags *flags);
int		lxy_put_unsigned_long(unsigned long lu, t_flags *flags);
int		lxy_put_size_t(size_t zu, t_flags *flags);

int		lxy_put_hexa_lowercase(unsigned int u, t_flags *flags);
int		lxy_put_hexa_uppercase(unsigned int u, t_flags *flags);
int		lxy_put_long_hexa_lowercase(unsigned long lu, t_flags *flags);
int		lxy_put_long_hexa_uppercase(unsigned long lu, t_flags *flags);
int		lxy_put_long_long_hexa_lowercase(size_t zu, t_flags *flags);
int		lxy_put_long_long_hexa_uppercase(size_t zu, t_flags *flags);

int		lxy_put_pointer(void *ptr, t_flags *flags);

// not sure if I will implement them
int		lxy_put_float(float f);
int		lxy_put_double(double fl);

// --- end ---

#endif
