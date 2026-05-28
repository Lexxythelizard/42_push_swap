/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_layer_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:40:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/28 12:26:45 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"
#include "op_tracker.h"

// --- DOC ---

/*
TODO:
	- implement utility lxy/rvn_putfloat_fd			: 
	- implement utility lxy/rvn_putsize_t_fd		: (considering)...
*/

// --- define ---

static void	put_line_0(t_op_track *track, int fd)
{
	ft_putstr(STR_BENCH, fd);
	ft_putchar_fd(32, fd);
	ft_putstr(STR_DISORDER, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	lxy_putfloat((track -> disorder), fd);		// <-- implement 
}

static void	put_line_1(t_op_track *track, int fd)
{
	ft_putstr_fd(STR_BENCH, fd);
	ft_putchar_fd(32, fd);
	ft_putstr_fd(STR_STRATEGY, fd);
	ft_putstr_fd(STR_TWO_SPACE, fd);
	ft_putstr_fd((track -> strategy), fd);
}

static void	put_line_2(t_op_track *track, int fd)
{
	ft_putstr_fd(STR_BENCH, fd);
	ft_putchar_fd(32, fd);
	ft_putstr_fd(STR_TOTAL_OPS, fd);
	ft_putstr_fd(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> total_ops), fd);
}


static void	putt_line_3(t_op_track *track, int fd)
{
	ft_putstr(STR_BENCH, fd);
	ft_putchar_fd(32, fd);
	ft_putstr(STR_SA, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> sa), fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putstr(STR_SB, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> sb), fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putstr(STR_SS, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> ss), fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putstr(STR_PA, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> pa), fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putstr(STR_PB, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> pb), fd);
}

static void	put_line_4(t_op_track *track, int fd)
{
	ft_putstr(STR_BENCH, fd);
	ft_putchar_fd(32, fd);
	ft_putstr(STR_RA, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> ra), fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putstr(STR_RB, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> rb), fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putstr(STR_RR, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> rr), fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putstr(STR_RRA, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> rra), fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putstr(STR_RRB, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> rrb), fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putstr(STR_RRR, fd);
	ft_putstr(STR_TWO_SPACE, fd);
	ft_putnbr_fd((track -> rrr), fd);
}
