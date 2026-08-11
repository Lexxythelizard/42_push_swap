/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:07:15 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:07:17 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "./stackmachine/machine.h"
# include "./sort/sort.h"
# include "./ui/ui.h"
# include "./benchmarks/benchmarks.h"

// --- prototypes ---

// interface_sort.c

void	run_sort(t_stack_machine *machine, int flag);

// interface_stackmachine.c

int		machine_set(t_stack_machine *machine, const char **argv, int argc);

// interface_ui.c

int		ui_validate(const char **argv, int argc);

// --- end ---

#endif
