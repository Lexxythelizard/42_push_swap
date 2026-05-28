/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_layer_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:40:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/28 12:27:45 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"
#include "op_tracker.h"

// --- DOC ---

/*
TODO: see output_layer_1.c
*/

// --- proto types ---

static void	put_line_0(t_op_track *track, int fd);
static void	put_line_1(t_op_track *track, int fd);
static void	put_line_2(t_op_track *track, int fd);
static void	put_line_3(t_op_track *track, int fd);
static void	put_line_4(t_op_track *track, int fd);

// --- define ---

void print_bench(t_op_track *track, int fd)
{
	put_line_0(track, fd);
	ft_putchar_fd(10, fd);
	put_line_1(track, fd);
	ft_putchar_fd(10, fd);
	put_line_2(track, fd);
	ft_putchar_fd(10, fd);
	put_line_3(track, fd);
	ft_putchar_fd(10, fd);
	put_line_4(track, fd);
	ft_putchar_fd(10, fd);
}
