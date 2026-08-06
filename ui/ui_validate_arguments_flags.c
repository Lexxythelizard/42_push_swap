/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_arguments_flags.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 2026/08/06 15:42:11 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

// --- define ---

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
	char	*temp;
	int		ctrl;

	if (!s)
		return (0);
	temp = ft_strtrim(s, SPACES_STR);
	if (!temp)
		return (0);
	ctrl = is_begin_with_double_dash(temp);
	if (!(ctrl))
		return (free_and_return_int((void *)(temp), ctrl));
	ctrl = (is_command_flag(temp) || is_display_flag(temp));
	return (free_and_return_int((void *)(temp), ctrl));
}
