/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:32:11 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/28 19:00:12 by lenivorb         ###   ########.fr       */
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
		ft_putchar(((unsigned char)((size_t)(zu / divisor) + 48)), fd);
		zu %= divisor;
		divisor /= 10;
	}
	ft_putchar(((unsigned char)((size_t)(zu / divisor) + 48)), fd);
	zu %= divisor;
}

void	lxy_putfloat_fd(size_t zu, int fd)
{
	//code
}
