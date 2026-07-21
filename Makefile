# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 11:27:12 by lenivorb          #+#    #+#              #
#    Updated: 2026/07/09 16:16:23 by lenivorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

Include_SM		=	$(Include_Stack) \
					$(Include_Stats) \
					$(Include_Funcs) \
					$(Include_Machine)

Include_Test	=	-I $(Main_Dir)

Include_All		=	$(Include_SM) \
					$(Include_Ui) \
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
					$(Stack_Dir)/stack_pop_add.c \
					$(Stack_Dir)/stack_operation.c \
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
					$(Ui_Dir)/ui_validate_arguments_numbers.c \
					$(Ui_Dir)/ui_convert_arguments.c \
					$(Ui_Dir)/ui_entropy.c \
					$(Ui_Dir)/ui_output.c

Push_Swap_Files	=	$(This_Dir)/sort_adaptive.c \
					$(This_Dir)/sort_complex_mergesort_base.c \
					$(This_Dir)/sort_complex_mergesort.c \
					$(This_Dir)/sort_complex.c \
					$(This_Dir)/sort_medium.c \
					$(This_Dir)/sort_simple.c \
					$(This_Dir)/sort_run.c

All_Src_Files	=	$(Stack_Files) \
					$(Stats_Files) \
					$(Funcs_Files) \
					$(Machine_Files) \
					$(Ui_Files) \
					$(Push_Swap_Files)

Push_Swap_Main	=	$(This_Dir)/main.c

Test_Helper		=	$(Main_Dir)/test_helper_stack.c

Test_Stats		=	$(Main_Dir)/test_helper_stats.c

Test_Funcs		=	$(Main_Dir)/test_helper_funcs.c

Test_Machine	=	$(Main_Dir)/test_helper_machine.c

# -------> for testing

Args_Main		=	$(Main_Dir)/test_argparsing.c

Bench_Main		=	$(Main_Dir)/test_output.c

Entropy_Main	=	$(Main_Dir)/test_entropy.c

Stack_Main		=	$(Main_Dir)/test_stack_manipulation.c

Stack_Bas_Main	=	$(Main_Dir)/test_stack_operation_basics.c

Stack_Op_Main	=	$(Main_Dir)/test_stack_operation.c

Stats_Main		=	$(Main_Dir)/test_stats_manipulation.c

Funcs_Main		=	$(Main_Dir)/test_funcs_manipulation.c

Machine_M_Main	=	$(Main_Dir)/test_machine_manipulation.c

Machine_Main	=	$(Main_Dir)/test_machine_operation.c

Ui_Main			=	$(Main_Dir)/test_ui.c

Stack_Obj		=	$(Stack_Files:.c=.o)

Push_Swap_Obj	=	$(Push_Swap_Files:.c=.o)

# ------------------------- compile rules -------------------------

# None

# ------------------------- Commands -------------------------

# test

test_stackmanipulation: create_testdir
	$(Compile) $(Stack_Main) $(Test_Helper) $(Stack_Files) $(Debugg) \
	$(Include_Stack) $(Include_Test) \
	$(Out) $(Test_Dir)/stackmanipulation

test_stackbasicoperation: create_testdir
	$(Compile) $(Stack_Bas_Main) $(Test_Helper) $(Stack_Files) $(Debugg) \
	$(Include_Stack) $(Include_Test) \
	$(Out) $(Test_Dir)/stackbasicoperations

test_stackoperation: create_testdir
	$(Compile) $(Stack_Op_Main) $(Test_Helper) $(Stack_Files) $(Debugg) \
	$(Include_Stack) $(Include_Test) \
	$(Out) $(Test_Dir)/stackoperations

test_stats: create_testdir
	$(Compile) $(Stats_Main) $(Test_Stats) $(Stats_Files) $(Debugg) \
	$(Include_Stats) $(Include_Test) \
	$(Out) $(Test_Dir)/statsmanipulation

test_funcs: create_testdir
	$(Compile) $(Funcs_Main) $(Test_Funcs) $(Funcs_Files) $(Debugg) \
	$(Include_Funcs) $(Include_Test) \
	$(Out) $(Test_Dir)/funcsmanipulation

test_machinemanipulation: create_testdir
	$(Compile) $(Machine_M_Main) $(Test_Machine) $(Machine_Files) \
	$(Stack_Files) $(Stats_Files) $(Funcs_Files) $(Debugg) \
	$(Include_SM) $(Include_Test) \
	$(Out) $(Test_Dir)/machinemanipulation

test_machineoperation: create_testdir libft
	$(Compile) $(Machine_Main) $(Test_Machine) $(Machine_Files) \
	$(Stack_Files) $(Stats_Files) $(Funcs_Files) $(Debugg) \
	$(Include_Libft) $(Include_SM) $(Include_Test) \
	-L $(Library_Dir) -l ft \
	$(Out) $(Test_Dir)/machineoperation

test_ui: create_testdir libft ftprintf
	$(Compile) $(Ui_Main) \
	$(Ui_Files) $(Debugg) \
	$(Include_Libft) $(Include_Ui) $(Include_Test) \
	$(LIBRARIES) \
	$(Out) $(Test_Dir)/ui

# others

push_swap: create_testdir libft ftprintf
	$(Compile) $(CFlags) $(Push_Swap_Main) $(All_Src_Files) \
	$(Include_All) $(LIBRARIES) -g \
	$(Out) $(Test_Dir)/prototype

clean:
	rm -f $(Push_Swap_Obj) $@

create_testdir:
	if [ ! -e "$(Test_Dir)" ]; then \
		mkdir "$(Test_Dir)"; \
	fi

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


# ------------------------- Commands -------------------------

.PHONY: all re flcean clean \
		ftprintf ftprintf_re ftprintf_fclean ftprintf_clean \
		libft libft_re libft_fclean libft_clean \
		create_testdir compile_src 
