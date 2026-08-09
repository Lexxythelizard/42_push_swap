/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:02:50 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:02:53 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATS_H
# define STATS_H

// --- makros ---

# define ADAPTIVE_COMPLEX_STR "Adaptive / O(n*log(n))"
# define ADAPTIVE_MEDIUM_STR "Adaptive / O(n√n\u0305)"
# define ADAPTIVE_SIMPLE_STR "Adaptive / O(n²)"
# define ADAPTIVE_NULL_STR "Adaptive / O(0)"

# define BENCH_STR "[bench] "
# define DISORDER_STR "disorder:  "
# define STRATEGY_STR "strategy:  "
# define TOTAL_OPS_STR "total_ops:  "

# define ADAPTIVE_STR "Adaptive"
# define COMPLEX_STR "Complex / O(n*log(n))"
# define MEDIUM_STR "Medium / O(n√n\u0305)"
# define SIMPLE_STR "Simple / O(n²)"

# define BENCH_VAL 16
# define ADAPTIVE_VAL 8
# define COMPLEX_VAL 4
# define MEDIUM_VAL 2
# define SIMPLE_VAL 1

# define COMPLEX_ENTRO 0.5f
# define MEDIUM_ENTRO 0.2f
# define SIMPLE_ENTRO 0.01f
# define NULL_ENTRO 0

# ifndef OPS_N
#  define OPS_N 11
# endif

// --- structs ---

typedef struct s_stats
{
	unsigned int	calls[OPS_N];
	unsigned int	total_ops;
	float			entropy;
	char			*strategy;
}					t_stats;

// --- prototypes ---

// machine_stats.c 

int	stats_init_empty(t_stats *stats);

// machine_stats_strategy_flag.c

int	stats_assign_strategy_by_flag(t_stats *stats, int flag_val);

// machine_stats_strategy_entro.c

int	stats_assign_strategy_by_entropy(t_stats *stats);

// --- end ---

#endif
