/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:29:29 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/22 19:27:40 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Prints a character
   The following conversion rules can apply:
   min_width - fills up with whitespace until at least min-width characters are
               printed
   '-'       - fills up on the right instead of the left if min-width is 
               specified
   Returns the number of characters printed */
int	rvn_printchar(char c, t_conv conv)
{
	int	count;

	count = 1;
	if (conv.conv_type != 'c')
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	if (!conv.flags[2])
		count += rvn_fill(conv.min_width - 1, ' ');
	ft_putchar_fd(c, 1);
	if (conv.flags[2])
		count += rvn_fill(conv.min_width - 1, ' ');
	return (count);
}

/* Prints a string or '(null)' if called with NULL
   The following conversion rules can apply:
   min_width       - fills up with whitespace until at least min_width
                     characters are printed
   precision ('.') - Prints at most prec characters of the string
   '-'             - fills up on the right instead of the left if min-width is
                     specified
   Returns the number of characters printed */
int	rvn_printstr(const char *s, t_conv conv)
{
	int	count;
	int	i;
	int	slen;

	if (!s)
		return (rvn_printstr("(null)", conv));
	if (conv.conv_type != 's')
	{
		count = ft_strlen(s);
		ft_putstr_fd((char *)s, 1);
		return (count);
	}
	count = conv.prec;
	slen = ft_strlen(s);
	if (count < 0 || slen < count)
		count = slen;
	i = count;
	if (!conv.flags[2])
		count += rvn_fill(conv.min_width - count, ' ');
	while (i--)
		ft_putchar_fd(*(s++), 1);
	if (conv.flags[2])
		count += rvn_fill(conv.min_width - count, ' ');
	return (count);
}

/* Prints a signed or unsigned integer in a certain base
   The following conversion rules can apply:
   min_width       - fills up with whitespace until at least min_width 
                     characters are printed
   precision ('.') - Prints at least prec digits, fills up with '0' if
                     necessary, overrides a '0' flag
   '0'             - Fills up with '0' instead of whitespace
   '-'             - fills up on the right instead of the left if min-width is 
                     specified, overrides a '0' flag
   ' '             - inserts a whitespace (' ') before a positive signed integer
   '+'             - inserts a plus sign ('+') before a positive signed integer,
                      overrides a ' ' flag
   Returns the number of characters printed */
int	rvn_printnbr(unsigned long n, t_conv conv, char *base, bool issigned)
{
	int	count;
	int	num_digit;

	num_digit = rvn_getlog(n, ft_strlen(base), issigned) + (!n && conv.prec);
	count = num_digit + (issigned && ((long)n < 0 || conv.flags[3] || \
			conv.flags[4]));
	if (conv.flags[1] && conv.min_width > conv.prec)
	{
		conv.prec = conv.min_width;
		num_digit = count;
	}
	count += (conv.prec > num_digit) * (conv.prec - num_digit);
	if (!conv.flags[1] && !conv.flags[2])
		count += rvn_fill(conv.min_width - count, ' ');
	if (issigned && (long)n < 0)
		ft_putchar_fd('-', 1);
	else if (issigned && (conv.flags[3] || conv.flags[4]))
		ft_putchar_fd(' ' + conv.flags[4] * ('+' - ' '), 1);
	rvn_fill(conv.prec - num_digit, '0');
	if (n || conv.prec)
		rvn_putbase(n * (1 - 2 * ((long)n < 0 && issigned)), base);
	if (conv.flags[2])
		count += rvn_fill(conv.min_width - count, ' ');
	return (count);
}

/* Prints an unsigned number in hexadecimal using either 0-9 and either 
   a-f or A-F to represent it
   The following conversion rules can apply additionaly to those in 
   rvn_printnbr:
   '#' - Inserts a 0x or 0X in front of the hexadecimal number depending
         on if the number is lowercase or uppercase
   A call with 'p' is similar to '#x' but returns '(nil)' if called with
   NULL/0
   Returns the number of characters printed */
int	rvn_printhex(unsigned long hex, t_conv conv, bool isupper)
{
	int	count;

	if (conv.conv_type == 'p' && !hex)
		return (rvn_printstr("(nil)", conv));
	count = 0;
	if (conv.flags[0] && hex)
	{
		if (isupper)
			count += rvn_printstr("0X", conv);
		else
			count += rvn_printstr("0x", conv);
		conv.min_width -= 2;
	}
	if (!isupper)
		return (count + rvn_printnbr(hex, conv, "0123456789abcdef", false));
	else
		return (count + rvn_printnbr(hex, conv, "0123456789ABCDEF", false));
}
