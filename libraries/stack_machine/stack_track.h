/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_track.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:17:20 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/06 19:26:30 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TRACK_H
# define STACK_TRACK_H

// --- include ---

// --- DOC ---

/*
	...you comment here...
*/

// --- Makros ---

# define YOUR_DEFVAL 161

// --- struct ---

typedef struct s_stack_track
{
	int		size_a;
	int		size_b;
	int		merge_size;
	int		unmerged_a;
	int		unmerged_b;
	int		side;
}			t_stack_track;

// --- end ---

#endif
