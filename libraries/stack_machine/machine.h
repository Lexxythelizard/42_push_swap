/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:55:43 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 19:39:43 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H

// --- include ---

# include "./stack.h"
# include "./stack_track.h"

// --- makros ---

# define SIMPLE "(O(n²))"
# define MEDIUM "(O(n√n\u0305)"
# define COMPLEX "(O(n*log(n)))"

// --- prototypes ---

struct	s_stack_machine;
struct	s_func;
struct	s_stats;

// --- structs ---

typedef struct s_stats
{
	unsigned int	calls[11];
	unsigned int	total_ops;
	float			disorder;
	char			*strategy;
}					t_stats;

typedef struct s_func
{
	void	(*f)(struct s_stack_machine *machine);
	char	*name;
}			t_func;

typedef struct s_stack_machine
{
	t_stack	stacks[2];
	t_stats	*stats;
	t_func	funcs[11];	
}			t_stack_machine;

#endif
