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

int	is_command_flag(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return (is_flag_simple(s)
		|| is_flag_medium(s)
		|| is_flag_complex(s)
		|| is_flag_adaptive(s));
}

int	is_flag_simple(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return (is_str_equal_to_str(s, FLAG_SIMPLE));
}

int	is_flag_medium(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return (is_str_equal_to_str(s, FLAG_MEDIUM));
}

int	is_flag_complex(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return (is_str_equal_to_str(s, FLAG_COMPLEX));
}

int	is_flag_adaptive(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return (is_str_equal_to_str(s, FLAG_ADAPTIVE));
}
