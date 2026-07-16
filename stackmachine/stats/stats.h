#ifndef STATS_H
# define STATS_H

// --- makros ---

# define SIMPLE "(O(n²))"
# define MEDIUM "(O(n√n\u0305)"
# define COMPLEX "(O(n*log(n)))"

# define BENCH_STR "test bench"
# define ADAPTIVE_STR "test adaptive"
# define COMPLEX_STR "test complex"
# define MEDIUM_STR "test medium"
# define SIMPLE_STR "test simple"

# define BENCH_VAL 16
# define ADAPTIVE_VAL 8
# define COMPLEX_VAL 4
# define MEDIUM_VAL 2
# define SIMPLE_VAL 1

# define COMPLEX_ENTRO 0.5
# define MEDIUM_ENTRO 0.3
# define SIMPLE_ENTRO 0.2
# define NULL_ENTRO 0.00

// --- structs ---

typedef struct s_stats
{
	unsigned int	calls[11];
	unsigned int	total_ops;
	float			disorder;
	char			*strategy;
}					t_stats;

// --- prototypes ---

// machine_stats.c 

int	stats_init_empty(t_stats *stats);

// machine_stats_strategy_flag.c

int	stats_assign_strategy_by_flag(t_stats *stats, int flag_val);

// machine_stats_strategy_entro.c

int stats_assign_strategy_by_entropy(t_stats *stats);

// --- end ---

#endif
