/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_utils_put_nbr_to_base.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:58:43 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/03 16:48:21 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../core/ft_printf_core.h"
#include "../ft_printf.h"

/* del */
#include <stdio.h>

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

static unsigned int	lxy_len_if_valid(const char *base);

// --- define ---

int	lxy_put_unsigned_int_base(
		unsigned int u,
		const char *base)
{
	unsigned int	base_n;
	ssize_t			wrt;
	ssize_t			len;
	unsigned int	divisor;

	divisor = 1;
	len = 0;
	base_n = lxy_len_if_valid(base);
	if (base_n < 2)
		return (-1);
	while ((divisor <= (u / base_n)))
		divisor *= base_n;
	while (divisor >= base_n)
	{
		wrt = write(STDOUT, &(base[((unsigned int)(u / divisor))]), 1);
		u %= divisor;
		divisor /= base_n;
		if (wrt < 0)
			return (-1);
		len += wrt;
	}
	wrt = write(STDOUT, &(base[u]), 1);
	if (wrt < 0)
		return (-1);
	return ((int)(len + wrt));
}

/*	...you comment... */

int	lxy_put_unsigned_long_base(
		unsigned long lu,
		const char *base)
{
	unsigned long	base_n;
	ssize_t			wrt;
	ssize_t			len;
	unsigned long	divisor;

	divisor = 1;
	len = 0;
	base_n = (unsigned long)(lxy_len_if_valid(base));
	if (base_n < 2)
		return (-1);
	while ((divisor <= (lu / base_n)))
		divisor *= base_n;
	while (divisor >= base_n)
	{
		wrt = write(STDOUT, &(base[((unsigned long)(lu / divisor))]), 1);
		lu %= divisor;
		divisor /= base_n;
		if (wrt < 0)
			return (-1);
		len += wrt;
	}
	wrt = write(STDOUT, &(base[lu]), 1);
	if (wrt < 0)
		return (-1);
	return ((int)(len + wrt));
}

/*	...you comment... */

int	lxy_put_size_t_base(
		size_t zu,
		const char *base)
{
	size_t	base_n;
	ssize_t	wrt;
	ssize_t	len;
	size_t	divisor;

	divisor = 1;
	len = 0;
	base_n = (size_t)(lxy_len_if_valid(base));
	if (base_n < 2)
		return (-1);
	while ((divisor <= (zu / base_n)))
		divisor *= base_n;
	while (divisor >= base_n)
	{
		wrt = write(STDOUT, &(base[((size_t)(zu / divisor))]), 1);
		zu %= divisor;
		divisor /= base_n;
		if (wrt < 0)
			return (-1);
		len += wrt;
	}
	wrt = write(STDOUT, &(base[zu]), 1);
	if (wrt < 0)
		return (-1);
	return ((int)(len + wrt));
}

static unsigned int	lxy_len_if_valid(const char *base)
{
	int				len;
	unsigned char	ascii[128];

	len = 0;
	if (!base)
		return (0);
	while (len++ < 128)
		ascii[(len - 1)] = 0;
	len = 0;
	while (base[len])
	{
		if (ascii[((int)(base[len]))])
			return (0);
		ascii[((int)(base[len]))]++;
		len++;
	}
	return (len);
}
