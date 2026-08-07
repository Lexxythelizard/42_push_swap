/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_arguments_compare.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:15:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:15:59 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

// --- define ---

int	is_str_equal_to_str(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	ctrl_len;

	if ((!s1) && (!s2))
		return (1);
	if ((!s1) || (!s2))
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len != s2_len)
		return (0);
	ctrl_len = s1_len * (s1_len >= s2_len) + s2_len * (s2_len > s1_len);
	return (!(ft_strncmp(s1, s2, ctrl_len)));
}

int	is_begin_with_double_dash(const char *s)
{
	if ((s[0]) && (s[1]))
		return ((s[0] == 45) && (s[1] == 45));
	return (0);
}
