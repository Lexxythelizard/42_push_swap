/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

// --- define ---
/*
int	count_repitition_of_flags(const char **argv, int argc)
{
	int	count;

	count = 0;
	while ((count + 1) < argc) && (count < 2)
		count += is_valid_flag(argv[(count + 1)]);
}
*/
int	is_flag_combination_valid(const char **argv, int argc)
{
	int	display_flags;
	int	command_flags;

	display_flags = 0;
	command_flags = 0;
	if (argc < 2)
		return (0);
	if (argc < 3)
		return (is_valid_flag(argv[1]));
	display_flags = (is_display_flag(argv[1])) + (is_display_flag(argv[2]));
	command_flags = (is_command_flag(argv[1])) + (is_command_flag(argv[2]));
	if ((display_flags >= 2) || (command_flags >= 2))
		return (0);
	return (is_valid_flag(argv[1]));
}

int	is_valid_flag(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return (is_command_flag(s) || is_display_flag(s));
}

int	is_any_flag(const char *s)
{
	if ((s[0]) && (s[1]))
		return ((s[0] == 45) && (s[1] == 45));
	return (0);
}
