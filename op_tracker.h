/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tracker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:21:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/02 18:32:04 by rcollet          ###   ########.fr       */
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
	unsigned int	calls[11];
	unsigned int	total_ops;
	float			disorder;
	char			*strategy;
	void			(*print_bench)(s_op_tracker*);
}					t_op_track;

#endif
