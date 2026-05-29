/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:32:11 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/29 21:26:23 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"

// --- DOC ---

// --- define ---

void	lxy_putzu_fd(size_t zu, int fd)
{
	size_t	divisor;

	divisor = 1;
	while (((size_t)(zu / divisor)) >= 10)
		divisor *= 10;
	while (divisor >= 10)
	{
		ft_putchar_fd(((unsigned char)((size_t)(zu / divisor) + 48)), fd);
		zu %= divisor;
		divisor /= 10;
	}
	ft_putchar_fd(((unsigned char)((size_t)(zu / divisor) + 48)), fd);
	zu %= divisor;
}

void	lxy_putfloat_fd(float fl, int fd)
{
	size_t	zu;

	zu = (size_t)(fl);
	lxy_putzu_fd(zu);
	fl -= (float)(zu);
	fl *= 10;
	zu = (size_t)(fl);
	ft_putchar_fd(((unsigned char)(zu + 48)), fd);
	fl -= (float)(zu);
	while (fl != 0.0)
	{
		fl *= 10;
		zu = (size_t)(fl);
		ft_putchar_fd(((unsigned char)(zu + 48)), fd);
		fl -= (float)(zu);
	}
}
