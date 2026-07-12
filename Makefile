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

Stack_Dir		=	$(Library_Dir)/stack_machine

Stack_Core_Dir	=	$(Stack_Dir)/core

Test_Dir		=	$(This_Dir)/tests

Include_This	=	-I $(This_Dir)

Include_Printf	=	-I $(Printf_Dir)

Include_Libft	=	-I $(Libft_Dir)

Include_Stack	=	-I $(Stack_Dir)

# ------------------------- library files -------------------------

PRINTF			=	libftprintf.a

LIBFT			=	libft.a

STACK			=	libstackmachine.a

# ------------------------- library inclusion -------------------------

LIBRARIES		=	-L $(Library_Dir) -l ftprintf -l ft -l stackmachine

# ------------------------- Files -------------------------

Stack_Files		=	$(Stack_Dir)/disorder_metric.c \
					$(Stack_Dir)/machine_exec.c \
					$(Stack_Dir)/machine_free.c \
					$(Stack_Dir)/machine_init.c \
					$(Stack_Dir)/machine_operation_push.c \
					$(Stack_Dir)/machine_operation_reverse_rotate.c \
					$(Stack_Dir)/machine_operation_rotate.c \
					$(Stack_Dir)/machine_operation_swap.c \
					$(Stack_Dir)/stack_manipulation.c \
					$(Stack_Dir)/stack_operation.c \
					$(Stack_Dir)/stack_scan.c

Push_Swap_Files	=	$(This_Dir)/sort_adaptive.c \
					$(This_Dir)/sort_complex_mergesort_base.c \
					$(This_Dir)/sort_complex_mergesort.c \
					$(This_Dir)/sort_complex.c \
					$(This_Dir)/sort_medium.c \
					$(This_Dir)/sort_simple.c \
					$(This_Dir)/sort_run.c \
					$(This_Dir)/ui_convert_arguments.c \
					$(This_Dir)/ui_validate_arguments.c \
					$(This_Dir)/ui_validate_arguments_flags.c \
					$(This_Dir)/ui_validate_arguments_numbers.c \
					$(This_Dir)/ui_output.c \
					$(This_Dir)/utillities.c

# -------> for testing

Args_Main		=	./test_argparsing.c

Bench_Main		=	./test_output.c

Stack_Obj		=	$(Stack_Files:.c=.o)

Push_Swap_Obj	=	$(Push_Swap_Files:.c=.o)

# ------------------------- compile rules -------------------------

$(Stack_Obj): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(CFlags) $(Debugg) \
		$(Include_Stack_Core) $(Include_Stack) $(Dont_link) $< $(Out) $@; \
	else \
		$(Compile) $(CFlags) \
		$(Include_Stack_Core) $(Include_Stack) $(Dont_link) $< $(Out) $@; \
	fi

$(Push_Swap_Obj): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(CFlags) $(Debugg) \
		$(Include_This) $(Include_Printf) $(Include_Libft) $(Dont_link) $< $(Out) $@; \
	else \
		$(Compile) $(CFlags) \
		$(Include_This) $(Include_Printf) $(Include_Libft) $(Dont_link) $< $(Out) $@; \
	fi

# ------------------------- Commands -------------------------

test0: $(Push_Swap_Obj)

test_args: create_testdir libft ftprintf stackmachine
	$(Compile) $(Args_Main) $(Push_Swap_Files) $(Debugg) $(LIBRARIES) \
	$(Out) $(Test_Dir)/argpasstest

test_bench: create_testdir libft ftprintf stackmachine
	$(Compile) $(Bench_Main) $(Push_Swap_Files) $(Debugg) $(LIBRARIES) \
	$(Out) $(Test_Dir)/benchtest

clean:
	rm -f $(Push_Swap_Obj) $@

create_testdir:
	if [ ! -e "$(Test_Dir)" ]; then \
		mkdir "$(Test_Dir)"; \
	fi

stackmachine: $(Stack_Obj)
	ar rcs $(STACK) $(Stack_Obj)
	mv $(STACK) $(Library_Dir)/$(STACK)

stackmachine_re: stackmachine_fclean stackmachine

stackmachine_fclean: stackmachine_clean
	rm $(Library_Dir)/$(STACK)

stackmachine_clean:
	rm $(Stack_Obj)

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
