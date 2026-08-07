/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_arguments_numbers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:17:14 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:17:15 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

// --- define ---

//static int	is_within_integer_range(const char *s);

// --- define ---

int	is_numbers_unique(int *list, int len)
{
	int	i;
	int	j;

	i = 0;
	while ((i + 1) < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (list[i] == list[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_nbr(const char *s)
{
	size_t	i;
	char	*temp;
	int		ctrl;

	if (!s)
		return (0);
	temp = ft_strtrim(s, SPACES_STR);
	if (!temp)
		return (0);
	i = ((temp[0] == 43) || (temp[0] == 45));
	ctrl = is_digits_str(&(temp[i]));
	if (!(ctrl))
		return (free_and_return_int((void *)(temp), ctrl));
	i = (temp[0] == 43);
	ctrl = is_number_within_int_range(&(temp[i]));
	return (free_and_return_int((void *)(temp), ctrl));
}

int	is_number_within_int_range(const char *s)
{
	char	*control_str;
	char	*compare_str;
	int		compare_int;
	int		ctrl;

	control_str = ft_strtrim(s, SPACES_STR);
	if (!control_str)
		return (-1);
	compare_int = ft_atoi(control_str);
	compare_str = ft_itoa(compare_int);
	if (!compare_str)
		free(control_str);
	if (!compare_str)
		return (-1);
	ctrl = is_str_equal_to_str(control_str, compare_str);
	free(control_str);
	free(compare_str);
	return (ctrl);
}
