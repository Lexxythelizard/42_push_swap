#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "./stackmachine/machine.h"
# include "./sort/sort.h"
# include "./ui/ui.h"

// --- Makros ---

// --- prototypes ---

// interface_sort.c

void	run_sort(t_stack_machine *machine, int flag);

// interface_stackmachine.c

int		machine_set(t_stack_machine *machine, const char **argv, int argc);

// interface_ui.c

int		ui_validate(const char **argv, int argc);

// --- end ---

#endif
