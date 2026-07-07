/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:39:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/03 14:59:11 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../ft_printf_bonus.h"
#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	ft_printf(const char *passed_line, ...)
{
	va_list	args;
	int		wrt0;
	int		wrt1;
	int		idx;
	t_flags	*flags;

	flags = init_flags();
	va_start(args, passed_line);
	idx = 0;
	wrt1 = 0;
	while (passed_line[idx])
	{
		if (is_percent(passed_line[idx]))
			wrt0 = process_specifier(flags, &args,
					&(passed_line[idx]), &idx);
		else
			wrt0 = lxy_put_char(passed_line[idx]);
		if (wrt0 < 0)
			return (-1);
		wrt1 += wrt0;
		idx++;
	}
	free(flags);
	va_end(args);
	return (wrt1);
}
