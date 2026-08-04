/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:45:21 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/04 17:49:42 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// --- include ---

#include "../libraries/libft/libft.h"
#include "../libraries/ft_printf/ft_printf.h"
#include "../stackmachine/machine.h"

// --- DOC ---

// --- Makros ---

// --- struct ---

// --- prototype ---

int	checker_setup_machine(
		t_stack_machine *machine,
		const char **argv,
		int argc);

int	checker_validate_userinput(
		const char **argv,
		int argc);

int	checker_run(
		t_stack_machine *machine);

// --- end ---

#endif

