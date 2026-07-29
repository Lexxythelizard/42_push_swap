/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/08 19:00:52 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

void	ft_putchar_fd(char c, int fd);

// --- DOC ---

/*

*/

// --- scrats notes (delete later) ---

/*
	... notes...
*/

// --- define ---

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// --- utilities ---
/*
(static)	lxy_...
{
	//ft...
}
*/
