// --- includes ---

#include "./ui.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- define ---

/*
puts an Error message followd by a new line to the standart error
and returns 1
*/

int	put_error(void)
{
	ft_putendl_fd(ERR_STR, STDERR);
	return (1);
}
