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
