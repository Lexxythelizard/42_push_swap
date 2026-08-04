/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:27:35 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/04 17:59:30 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./checker.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	checker_setup_machine(
		t_stack_machine *machine,
		const char **argv,
		int argc)
{
	int	*int_arr;
	int	*int_arr_len;

	int_arr_len = count_valid_numbers(argv, argc);
	int_arr = get_int_list(argv, argc);
	if (!int_arr)
		return (-1);
	machine_stack_init(machine, int_arr, int_arr_len);
	free(int_arr);
	return (int_arr_len);
}

char	**checker_setup_comands(void)
{
	char	**commands;
	char	*temp;

	return (NULL):
}
