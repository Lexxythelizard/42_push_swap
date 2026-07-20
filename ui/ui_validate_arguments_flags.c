// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

// --- define ---

int	count_repitition_of_flags(const char **argv, int argc)
{
	int	count;

	count = 0;
	if (argc < 2)
		return (count);
	count += is_valid_flag(argv[1]);
	if (argc < 3)
		return (count);
	count += is_valid_flag(argv[2]);
	return (count);
}

int	is_unique_and_one_bench(const char **argv, int argc)
{
	if (argc < 2)
		return (0);
	if (argc < 3)
		return (is_valid_flag(argv[1]));
	if (ft_strncmp(argv[1], argv[2], 11) == 0)
		return (0);
	if (ft_strncmp(argv[1], FLAG_BENCH, 11) == 0)
		return (1);
	if (ft_strncmp(argv[2], FLAG_BENCH, 11) == 0)
		return (1);
	return (0);
}

int	is_valid_flag(const char *s)
{
	if (!(is_any_flag(s)))
		return (0);
	return ((!(ft_strncmp(s, FLAG_BENCH, 11)))
		|| (!(ft_strncmp(s, FLAG_SIMPLE, 11)))
		|| (!(ft_strncmp(s, FLAG_MEDIUM, 11)))
		|| (!(ft_strncmp(s, FLAG_COMPLEX, 11)))
		|| (!(ft_strncmp(s, FLAG_ADAPTIVE, 11))));
}

int	is_any_flag(const char *s)
{
	if ((s[0]) && (s[1]))
		return ((s[0] == 45) && (s[1] == 45));
	return (0);
}
