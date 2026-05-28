/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tracker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:21:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/28 12:28:32 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	OP_TRACKER_H
# define OP_TRACKER_H

// notes
/*
Contains string MAKROS and a struct: s op_tracker 

	see VI.5.1 Usage examples
*/

// --- MAKROS ---

# define STR_BENCH "[bench]"
# define STR_TWO_SPACE "  "
# define STR_DISORDER " disorder : "
# define STR_STRATEGY " strategy : "
# define STR_TOTAL_OPS " total_ops : "
# define STR_SA "sa:"
# define STR_SB "sb:"
# define STR_SS "ss:"
# define STR_PA "pa:"
# define STR_PB "pb:"
# define STR_RA "ra:"
# define STR_RB "rb:"
# define STR_RR "rr:"
# define STR_RRA "rra:"
# define STR_RRB "rrb:"
# define STR_RRR "rrr:"

// in case ft_printf is working and valid... or we bring up our own...

# define TXT_LINE_0 "[bench] disorder : %f"
# define TXT_LINE_1 "[bench] strategy : %s"
# define TXT_LINE_2 "[bench] total_ops : %zu"
# define TXT_LINE_3 "[bench] sa:  %zu  sb:  %zu  ss:  %zu  pa:  %zu  pb:  %zu "
# define TXT_LINE_4 "[bench] ra:  %zu  rb:  %zu  rr:  %zu  rra:  %zu  rrb:  %zu  rrr:  %zu"

// TODO:	consider split TXT_LINE_4 to 4A and 4B

// --- structs ---

typedef struct s_op_tracker
{
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
	size_t	total_ops;
	double	disorder;
	char	*strategy;
	void	(*print_bench)(s_op_tracker*);
}			t_op_track
