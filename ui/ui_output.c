// --- includes ---

#include "./ui.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- define ---

/*
Prints out the bench statistics
*/

void	print_bench(t_stats *stats)
{
	int	pre_comma;
	int	post_comma;

	ft_printf("This will print the stats if --bench was passed.\n\n");
	pre_comma = (int)(stats -> disorder);
	post_comma = (int)(stats -> disorder * 100.00) % 100;
	ft_printf("[bench] disorder:  %d.%d%%\n", pre_comma, post_comma);
	ft_printf("[bench] strategy:  %s\n", stats -> strategy);
	ft_printf("[bench] total_ops:  %u\n", stats -> total_ops);
	ft_printf("[bench] sa:  %u  sb:  %u  ss:  %u,  pa:  %u,  pb:  %u\n",
		(stats -> calls)[0], (stats -> calls)[1], (stats -> calls)[2],
		(stats -> calls)[3], (stats -> calls)[4]);
	ft_printf("[bench] ra:  %u  rb:  %u  rr:  %u",
		(stats -> calls)[5], (stats -> calls)[6], (stats -> calls)[7]);
	ft_printf(",  rra:  %u,  rrb:  %u,  rrr:  %u\n",
		(stats -> calls)[8], (stats -> calls)[9], (stats -> calls)[10]);
}

/*
puts an Error message followd by a new line to the standart error
and returns 1
*/

int	put_error(void)
{
	ft_putendl_fd(ERR_STR, STD_ERR);
	return (1);
}
