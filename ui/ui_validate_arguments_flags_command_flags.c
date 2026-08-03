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
	return (!(ft_strncmp(s, FLAG_SIMPLE, 11)));
}

int	is_flag_medium(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return (!(ft_strncmp(s, FLAG_MEDIUM, 11)));
}

int	is_flag_complex(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return (!(ft_strncmp(s, FLAG_COMPLEX, 11)));
}

int	is_flag_adaptive(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return (!(ft_strncmp(s, FLAG_ADAPTIVE, 11)));
}
