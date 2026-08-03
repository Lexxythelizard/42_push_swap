# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#              #
#    Updated: 20xx/xx/xx xx:xx:xx by intranam         ###   ########.fr        #
#                                                                              #
#  *************************************************************************** #

# ------------------------- Program -------------------------

NAME			=	push_swap

# ------------------------- Variables -------------------------

#  basics 

Compile			=	cc

CFlags			=	-Wall -Wextra -Werror

DEBUGG_MODE		=	1

Out				=	-o

Include			=	-I

Dont_link		=	-c

Debugg			=	-g

# ------------------------- Directories -------------------------

This_Dir		=	.

Library_Dir		=	$(This_Dir)/libraries

Printf_Dir		=	$(Library_Dir)/ft_printf

Libft_Dir		=	$(Library_Dir)/libft

Machine_Dir		=	$(This_Dir)/stackmachine

Stack_Dir		=	$(Machine_Dir)/stack

Stats_Dir		=	$(Machine_Dir)/stats

Funcs_Dir		=	$(Machine_Dir)/funcs

Ui_Dir			=	$(This_Dir)/ui

Sort_Dir		=	$(This_Dir)/sort

Test_Dir		=	$(This_Dir)/test_programs

Main_Dir		=	$(This_Dir)/test_files

Include_This	=	-I $(This_Dir)

Include_Printf	=	-I $(Printf_Dir)

Include_Libft	=	-I $(Libft_Dir)

Include_Stack	=	-I $(Stack_Dir)

Include_Stats	=	-I $(Stats_Dir)

Include_Funcs	=	-I $(Funcs_Dir)

Include_Machine	=	-I $(Machine_Dir)

Include_Ui		=	-I $(Ui_Dir)

Include_Sort	=	-I $(Sort_Dir)

Include_SM		=	$(Include_Stack) \
					$(Include_Stats) \
					$(Include_Funcs) \
					$(Include_Machine)

Include_Test	=	-I $(Main_Dir)

Include_All		=	$(Include_SM) \
					$(Include_Ui) \
					$(Include_Sort) \
					$(Include_Libft) \
					$(Include_Printf) \
					$(Include_This)

# ------------------------- library files -------------------------

PRINTF			=	libftprintf.a

LIBFT			=	libft.a

# ------------------------- library inclusion -------------------------

LIBRARIES		=	-L $(Library_Dir) -l ftprintf -l ft

# ------------------------- Files -------------------------

Stack_Files		=	$(Stack_Dir)/stack_elements.c \
					$(Stack_Dir)/stack_operation.c \
					$(Stack_Dir)/stack_operation_pop_add.c \
					$(Stack_Dir)/stack_scan.c \
					$(Stack_Dir)/stack_scan_max.c \
					$(Stack_Dir)/stack_scan_min.c \
					$(Stack_Dir)/stack_stack.c

Stats_Files		=	$(Stats_Dir)/machine_stats.c \
					$(Stats_Dir)/machine_stats_strategy_entro.c \
					$(Stats_Dir)/machine_stats_strategy_flag.c

Funcs_Files		=	$(Funcs_Dir)/machine_funcs.c

Machine_Files	=	$(Machine_Dir)/machine_machine.c \
					$(Machine_Dir)/machine_assign.c \
					$(Machine_Dir)/machine_operation_swap.c \
					$(Machine_Dir)/machine_operation_push.c \
					$(Machine_Dir)/machine_operation_rotate.c \
					$(Machine_Dir)/machine_operation_reverse_rotate.c \
					$(Machine_Dir)/machine_operation.c

Ui_Files		=	$(Ui_Dir)/ui_validate_arguments.c \
					$(Ui_Dir)/ui_validate_arguments_flags.c \
					$(Ui_Dir)/ui_validate_arguments_flags_command_flags.c \
					$(Ui_Dir)/ui_validate_arguments_flags_display_flags.c \
					$(Ui_Dir)/ui_validate_arguments_numbers.c \
					$(Ui_Dir)/ui_convert_arguments.c \
					$(Ui_Dir)/ui_entropy.c \
					$(Ui_Dir)/ui_output.c

Sort_Files	=		$(Sort_Dir)/sort_adaptive.c \
					$(Sort_Dir)/sort_anysort_sort_small_stacks.c \
					$(Sort_Dir)/sort_anysort_utilities_execute_swap_elements_a.c \
					$(Sort_Dir)/sort_anysort_utilities_execute_swap_elements_b.c \
					$(Sort_Dir)/sort_complex_mergesort_base.c \
					$(Sort_Dir)/sort_complex_mergesort_merge_to_side_x.c \
					$(Sort_Dir)/sort_complex_mergesort_efficiency.c \
					$(Sort_Dir)/sort_complex_mergesort.c \
					$(Sort_Dir)/sort_complex.c \
					$(Sort_Dir)/sort_medium.c \
					$(Sort_Dir)/sort_medium_bucketsort.c \
					$(Sort_Dir)/sort_medium_bucketsort_fill_bucket.c \
					$(Sort_Dir)/sort_medium_bucketsort_sort_bucket.c \
					$(Sort_Dir)/sort_medium_bucketsort_sort_bucket_efficiency.c \
					$(Sort_Dir)/sort_medium_bucketsort_utility.c \
					$(Sort_Dir)/sort_medium_bucketsort_utility_arr.c \
					$(Sort_Dir)/sort_medium_bucketsort_utility_arr_arr.c \
					$(Sort_Dir)/sort_simple.c \
					$(Sort_Dir)/sort_simple_min_extraction.c \
					$(Sort_Dir)/sort_benchmarks.c \
					$(Sort_Dir)/sort_utillities_execute_a.c \
					$(Sort_Dir)/sort_utillities_execute_b.c \
					$(Sort_Dir)/sort_utillities_scan.c

Push_Swap_Files	=	$(This_Dir)/interface_sort.c \
					$(This_Dir)/interface_stackmachine.c \
					$(This_Dir)/interface_ui.c

All_Src_Files	=	$(Stack_Files) \
					$(Stats_Files) \
					$(Funcs_Files) \
					$(Machine_Files) \
					$(Sort_Files) \
					$(Ui_Files) \
					$(Push_Swap_Files)

Push_Swap_Main	=	$(This_Dir)/main.c

# ------------------------- compile rules -------------------------

# None

# ------------------------- Commands -------------------------

all: $(NAME)

re: fclean all

$(NAME): create_testdir libft ftprintf
	$(Compile) $(CFlags) $(Push_Swap_Main) $(All_Src_Files) \
	$(Include_All) $(LIBRARIES) \
	$(Out) $(This_Dir)/$(NAME)

fclean: ftprintf_fclean libft_fclean clean
	rm -f $(NAME)

clean: ftprintf_clean libft_clean
	rm -f $(Push_Swap_Obj) $@

ftprintf:
	cd $(Printf_Dir) && $(MAKE)
	mv $(Printf_Dir)/$(PRINTF) $(Library_Dir)/$(PRINTF)

ftprintf_re:
	rm -f $(Library_Dir)/$(PRINTF)
	cd $(Printf_Dir) && $(MAKE) re
	mv $(Printf_Dir)/$(PRINTF) $(Library_Dir)/$(PRINTF)

ftprintf_fclean:
	rm -f $(Library_Dir)/$(PRINTF)
	cd $(Printf_Dir) && $(MAKE) fclean

ftprintf_clean:
	cd $(Printf_Dir) && $(MAKE) clean

libft:
	cd $(Libft_Dir) && $(MAKE)
	mv $(Libft_Dir)/$(LIBFT) $(Library_Dir)/$(LIBFT)

libft_re:
	rm -f $(Library_Dir)/$(LIBFT)
	cd $(Libft_Dir) && $(MAKE) re
	mv $(Libft_Dir)/$(LIBFT) $(Library_Dir)/$(LIBFT)

libft_fclean:
	rm -f $(Library_Dir)/$(LIBFT)
	cd $(Libft_Dir) && $(MAKE) fclean

libft_clean:
	cd $(Libft_Dir) && $(MAKE) clean

# for tests

push_swap_test: create_testdir libft ftprintf
	$(Compile) $(CFlags) $(Push_Swap_Main) $(All_Src_Files) \
	$(Include_All) $(LIBRARIES) -g \
	$(Out) $(Test_Dir)/prototype

create_testdir:
	if [ ! -e "$(Test_Dir)" ]; then \
		mkdir "$(Test_Dir)"; \
	fi

# ------------------------- PHONY -------------------------

.PHONY: \
	all \
	re \
	fclean \
	clean \
	ftprintf \
	ftprintf_re \
	ftprintf_fclean \
	ftprintf_clean \
	libft \
	libft_re \
	libft_clean \
	push_swap_test \
	create_testdir \
	compile_src
