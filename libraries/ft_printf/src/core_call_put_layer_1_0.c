/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_call_put_layer_1_0.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:39:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/02 15:54:53 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../ft_printf.h"
#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	TODO: implement a function to print pointer
*/

// --- define ---

/* u if		x else if		X else*/

int	(*get_ud_func(const char *spec))(
	unsigned int u,
	t_flags *flags)
{
	if (*spec == 'u')
		return (&lxy_put_unsigned_int);
	else if (*spec == 'x')
		return (&lxy_put_hexa_lowercase);
	else
		return (&lxy_put_hexa_uppercase);
}

/* lu if	xl else if		Xl else*/

int	(*get_lu_func(const char *spec))(
	unsigned long ul,
	t_flags *flags)
{
	if (is_equal(spec, "lu", 2))
		return (&lxy_put_unsigned_long);
	else if (is_equal(spec, "xl", 2))
		return (&lxy_put_long_hexa_lowercase);
	else
		return (&lxy_put_long_hexa_uppercase);
}

/* zu if	xz else if		Xz else*/

int	(*get_size_t_func(const char *spec))(
	size_t zu,
	t_flags *flags)
{
	if (is_equal(spec, "zu", 2))
		return (&lxy_put_size_t);
	else if (is_equal(spec, "xz", 2))
		return (&lxy_put_long_long_hexa_lowercase);
	else
		return (&lxy_put_long_long_hexa_uppercase);
}
