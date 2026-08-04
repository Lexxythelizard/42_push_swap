/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:26:47 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/04 17:59:42 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../libraries/libft/libft.h"
#include "../libraries/ft_printf/ft_printf.h"
#include "../stackmachine/machine.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	main(int argc, char **argv)
{
	// read input
	// call a validation function
	// set up stack
	// read STDIO

	t_stack_machine	machine;
	int				ctrl;

	machine_init_new_empty(&machine);
	if (!(checker_validate_user_input((const char **)(argv), argc)))
		return (put_error());
	ctrl = checker_setup_machine(&machine, (const char **)(argv), argc);
	if (ctrl == (-1))
		return (put_error());
	checker_run(&machine);
	machine_free(&machine);
	return (0);
}
