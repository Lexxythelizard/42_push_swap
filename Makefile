# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 11:27:12 by lenivorb          #+#    #+#              #
#    Updated: 2026/06/12 12:11:09 by lenivorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------- Variables -------------------------

This_Dir		=	.

Lib_Dir			=	./libft

Test_Dir		=	./tests

Compile			=	cc

Include			=	-I

CFlags			=	-Wall -Wextra -Werror

Lib				=	-L

link			=	-l

Out				=	-o

LIBFT			=	$(Lib_Dir)/libft.h

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

create_test_args: create_testdir $(Args_Main) $(Arg_Parsing) $(LIBFT)
	$(Compile) $(CFlags) $(debug) $(Include) $(This_Dir) \
	$(Lib) $(Lib_dir) $(link) ft $(Out) $(Test_Dir)/argparse

create_testdir:
	if [ -ne "$(Test_Dir)" ]; then
		mkdir "$(Test_Dir)"

create_libft:
	cd $(Lib_Dir) $(MAKE)

# ------------------------- Commands -------------------------

.PHONY: create_test_args create_testdir create_libft
