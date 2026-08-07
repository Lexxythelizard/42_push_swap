/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_arguments_flags_command_flags          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:16:53 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:16:55 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

// --- define ---

int	is_command_flag(const char *s)
{
	char	*temp;
	int		ctrl;

	if (!s)
		return (0);
	temp = ft_strtrim(s, SPACES_STR);
	ctrl = 0;
	if (!temp)
		return (0);
	ctrl = (
			(is_flag_simple((const char *)(temp)))
			|| (is_flag_medium((const char *)(temp)))
			|| (is_flag_complex((const char *)(temp)))
			|| (is_flag_adaptive((const char *)(temp)))
			);
	free(temp);
	return (ctrl);
}

int	is_flag_simple(const char *s)
{
	return (is_str_equal_to_str(s, FLAG_SIMPLE));
}

int	is_flag_medium(const char *s)
{
	return (is_str_equal_to_str(s, FLAG_MEDIUM));
}

int	is_flag_complex(const char *s)
{
	return (is_str_equal_to_str(s, FLAG_COMPLEX));
}

int	is_flag_adaptive(const char *s)
{
	return (is_str_equal_to_str(s, FLAG_ADAPTIVE));
}
