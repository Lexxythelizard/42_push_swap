/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_benchmarks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:09:47 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:09:48 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "./sort.h"
#include "../stackmachine/machine.h"
#include "../libraries/ft_printf/ft_printf.h"
#include "../libraries/libft/libft.h"

// --- prototype ---
/*
static void	print_first_line(t_stack_machine *machine);
static void	print_second_and_third_line(t_stack_machine *machine);
static void	print_fourth_line(t_stack_machine *machine);
static void	print_fifth_line(t_stack_machine *machine);
*/
// --- define ---

/*
Prints out the bench statistics
*/

void	print_bench(t_stack_machine *machine)
{
	t_stats	*stats;
	int		pre_comma;
	int		post_comma;

	stats = &(machine -> stats);
	pre_comma = (int)(stats -> entropy * 100);
	post_comma = (int)(stats -> entropy * 10000) % 100;
	ft_printf("[bench] disorder:  %d.%d%%\n", pre_comma, post_comma);
	ft_printf("[bench] strategy:  %s\n", stats -> strategy);
	ft_printf("[bench] total_ops:  %u\n", stats -> total_ops);
	ft_printf("[bench] sa:  %u  sb:  %u  ss:  %u,  pa:  %u,  pb:  %u\n",
		(stats -> calls)[SA], (stats -> calls)[SB], (stats -> calls)[SS],
		(stats -> calls)[PA], (stats -> calls)[PB]);
	ft_printf("[bench] ra:  %u  rb:  %u  rr:  %u",
		(stats -> calls)[RA], (stats -> calls)[RB], (stats -> calls)[RR]);
	ft_printf(",  rra:  %u,  rrb:  %u,  rrr:  %u\n",
		(stats -> calls)[RRA], (stats -> calls)[RRB], (stats -> calls)[RRR]);
}

/*
void	print_bench_new(t_stack_machine *machine)
{
	print_first_line(machine);
	print_second_and_third_line(machine);
	print_fourth_line(machine);
	print_fifth_line(machine);
}

static void	print_first_line(t_stack_machine *machine)
{
	t_stats	*stats;
	int		pre_comma;
	int		post_comma;

	stats = &(machine -> stats);
	pre_comma = (int)(stats -> entropy * 100);
	post_comma = (int)(stats -> entropy * 10000) % 100;
	ft_putstr_fd(BENCH_STR, STDERR);
	ft_putstr_fd(DISORDER_STR, STDERR);
	ft_putnbr_fd(pre_comma, STDERR);
	ft_putchar_fd('.', STDERR);
	ft_putnbr_fd(post_comma, STDERR);
	ft_putchar_fd('%', STDERR);
	ft_putchar_fd('\n', STDERR);
}

static void	print_second_and_third_line(t_stack_machine *machine)
{
	t_stats	*stats;

	stats = &(machine -> stats);
	ft_putstr_fd(BENCH_STR, STDERR);
	ft_putstr_fd(STRATEGY_STR, STDERR);
	ft_putendl_fd(stats -> strategy, STDERR);
	ft_putstr_fd(BENCH_STR, STDERR);
	ft_putstr_fd(TOTAL_OPS_STR, STDERR);
	ft_putnbr_fd(stats -> total_ops, STDERR);
	ft_putchar_fd('\n', STDERR);
}

static void	print_fourth_line(t_stack_machine *machine)
{
	t_stats	*stats;

	stats = &(machine -> stats);
	ft_putstr_fd(BENCH_STR, STDERR);

	ft_putstr_fd(SA_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[SA], STDERR);

	ft_putstr_fd(SB_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[SB], STDERR);

	ft_putstr_fd(SS_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[SS], STDERR);

	ft_putstr_fd(PA_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[PA], STDERR);

	ft_putstr_fd(PB_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[PB], STDERR);

	ft_putchar_fd('\n', STDERR);
}

static void	print_fifth_line(t_stack_machine *machine)
{
	t_stats	*stats;

	stats = &(machine -> stats);
	ft_putstr_fd(BENCH_STR, STDERR);

	ft_putstr_fd(RA_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[RA], STDERR);

	ft_putstr_fd(RB_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[RB], STDERR);

	ft_putstr_fd(RR_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[RR], STDERR);

	ft_putstr_fd(RRA_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[RRA], STDERR);

	ft_putstr_fd(RRB_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[RRB], STDERR);

	ft_putstr_fd(RRR_STR, STDERR);
	ft_putstr_fd(COL_SPACE_STR, STDERR);
	ft_putnbr_fd(stats -> calls[RRR], STDERR);

	ft_putchar_fd('\n', STDERR);
}
*/
