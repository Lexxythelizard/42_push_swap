/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_arguments_flags_display_flags          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:17:02 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:17:04 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

// --- define ---

int	is_display_flag(const char *s)
{
	char	*temp;
	int		ctrl;

	if (!s)
		return (0);
	temp = ft_strtrim(s, SPACES_STR);
	if (!temp)
		return (0);
	ctrl = is_flag_bench((const char *)(temp));
	free(temp);
	return (ctrl);
}

int	is_flag_bench(const char *s)
{
	return (is_str_equal_to_str(s, FLAG_BENCH));
}
