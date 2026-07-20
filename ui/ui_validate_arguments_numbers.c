// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

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

	i = 0;
	if (!(s))
		return (0);
	while ((s[i]) && (((s[i] >= 9) && (s[i] <= 13)) || (s[i] == 32)))
		i++;
	i += ((s[i] == 43) || (s[i] == 45));
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}
