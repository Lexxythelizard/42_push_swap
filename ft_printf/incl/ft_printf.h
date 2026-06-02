/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:17:58 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/15 16:44:48 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		rvn_printuntil(const char **s);
int		rvn_printchar(char c);
int		rvn_printstr(const char *s);
int		rvn_printnbr(unsigned long n, char *base, bool issigned);
int		rvn_getlog(unsigned long n, int base, bool issigned);
void	rvn_putbase(unsigned long n, char *base);
int		rvn_printhex(unsigned long hex, bool isupper);

#endif
