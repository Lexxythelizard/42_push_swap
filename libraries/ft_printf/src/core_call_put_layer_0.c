/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_call_put_layer_0.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:39:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/02 15:56:18 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../ft_printf.h"
#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	call_put_func(const char *spec, va_list *args, t_flags *flags)
{
	if ((is_equal(spec, "lu", 2)) || (is_equal(spec, "lx", 2))
		|| (is_equal(spec, "lX", 2)))
		return ((*get_lu_func(spec))(va_arg(*args, unsigned long), flags));
	else if ((is_equal(spec, "zu", 2)) || (is_equal(spec, "zx", 2))
		|| (is_equal(spec, "zX", 2)))
		return ((*get_size_t_func(spec))(va_arg(*args, size_t), flags));
	else if (*spec == 'c')
		return ((*get_char_func(spec))((char)(va_arg(*args, int))));
	else if (*spec == 's')
		return ((*get_string_func(spec))(va_arg(*args, const char *)));
	else if (*spec == '%')
		return (lxy_put_percent_sign());
	else if ((*spec == 'i') || (*spec == 'd'))
		return ((*get_int_func(spec))(va_arg(*args, int), flags));
	else if ((*spec == 'u') || (*spec == 'x') || (*spec == 'X'))
		return ((*get_ud_func(spec))(va_arg(*args, unsigned int), flags));
	else if (is_equal(spec, "ld", 2))
		return ((*get_long_func(spec))(va_arg(*args, long), flags));
	else if (is_equal(spec, "zd", 2))
		return ((*get_ssize_t_func(spec))(va_arg(*args, ssize_t), flags));
	else if (*spec == 'p')
		return (lxy_put_pointer(va_arg(*args, void *), flags));
	else
		return (0);
}
