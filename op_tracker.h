/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tracker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:21:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/02 16:04:13 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	OP_TRACKER_H
# define OP_TRACKER_H

// notes
/*
Contains struct: s op_tracker 

	see VI.5.1 Usage examples
*/

// --- MAKROS ---

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
	float	disorder;
	char	*strategy;
	void	(*print_bench)(s_op_tracker*);
}			t_op_track

#endif
