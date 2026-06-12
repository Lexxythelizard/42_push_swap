# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 11:27:12 by lenivorb          #+#    #+#              #
#    Updated: 2026/06/12 15:36:45 by lenivorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------- Variables -------------------------

This_Dir		=	.

Printf_Dir		=	$(This_Dir)/ft_printf

Libft_Dir		=	$(Printf_Dir)/libft

Test_Dir		=	$(This_Dir)/tests

Compile			=	cc

Include_This	=	-I $(This_Dir)

Include_Printf	=	-I $(Printf_Dir)

Include_Libft	=	-I $(Libft_Dir)

CFlags			=	-Wall -Wextra -Werror

Out				=	-o

THIS_H			=	$(This_Dir)/push_swap.h

LIBFT_H			=	$(Libft_Dir)/libft.h

LIBFT_H			=	$(Printf_Dir)/ft_printf.h

PRINTF			=	-L $(Printf_Dir) -l ftprintf

LIBFT			=	-L $(Libft_Dir) -l ft

# -------> for testing

debug			=	-g

# ------------------------- Files -------------------------

All_Files		=	./cleanup.c				./disorder_metric.c \
					./exec.c				./interface.c \
					./interface_push.c		./interface_rotate.c \
					./interface_rrotate.c	./interface_swap.c \
					./output.c				./scan_stack_1.c \
					./skeleton_def.c		./sort_complex_base.c \
					./sort_complex.c		./sort_medium.c \
					./sort_run.c			./sort_simple_0.c \
					./stack.c				./test.c \
					./ui_cli.c				./utillities.c \
					./validation.c			./main.c

# -------> for testing

Arg_Parsing		= 	./validation.c			./utillities.c \
					./ui_cli.c				./cleanup.c

Args_Main		=	./test_argparsing.c

# ------------------------- Commands -------------------------

create_test_args: create_testdir $(Args_Main) $(Arg_Parsing)
	$(Compile) $(CFlags) $(debug) $(Include_This) $(Include_Libft) \
	$(LIBFT) $(Out) $(Test_Dir)/argparse

create_testdir:
	if [ -ne "$(Test_Dir)" ]; then
		mkdir "$(Test_Dir)"

create_printf:
	cd $(Printf_Dir) && $(MAKE)

# ------------------------- Commands -------------------------

.PHONY: create_test_args create_testdir create_libft
