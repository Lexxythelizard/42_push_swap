# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 11:27:12 by lenivorb          #+#    #+#              #
#    Updated: 2026/07/07 15:44:52 by lenivorb         ###   ########.fr        #
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

Test_Dir		=	$(This_Dir)/tests

Include_This	=	-I $(This_Dir)

Include_Printf	=	-I $(Printf_Dir)

Include_Libft	=	-I $(Libft_Dir)

# ------------------------- library files -------------------------

PRINTF			=	libftprintf.a

LIBFT			=	libft.a

# ------------------------- library inclusion -------------------------

LIBRARIES		=	-L $(Library_Dir) -l ftprintf -l ft

# ------------------------- Files -------------------------

All_Files		=	./cleanup.c				./disorder_metric.c \
					./exec.c				./interface.c \
					./interface_push.c		./interface_rotate.c \
					./interface_rrotate.c	./interface_swap.c \
					./output.c				./scan_stack_1.c \
					./sort_complex_base.c	./sort_complex.c \
					./sort_medium.c 		./sort_run.c \
					./sort_simple_0.c		./stack.c \
					./ui_cli.c				./utillities.c \
					./validation.c

# -------> for testing

Arg_Parsing		= 	./validation.c			./utillities.c \
					./ui_cli.c				./cleanup.c

Args_Main		=	./test_argparsing.c

All_Obj			=	$(All_Files:.c=.o)

# ------------------------- compile rules -------------------------

$(All_Obj): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(CFlags) $(Debugg) \
		$(Include_This) $(Include_Printf) $(Include_Libft) $(Dont_link) $< $(Out) $@; \
	else \
		$(Compile) $(CFlags) \
		$(Include_This) $(Include_Printf) $(Include_Libft) $(Dont_link) $< $(Out) $@; \
	fi

# ------------------------- Commands -------------------------

test0: $(All_Obj)

clean:
	rm -f $(All_Obj) $@

create_test_args: create_testdir $(Args_Main) $(Arg_Parsing)
	$(Compile) $(CFlags) $(debug) $(Include_This) $(Include_Libft) \
	$(LIBFT) $(Out) $(Test_Dir)/argparse

create_testdir:
	if [ -ne "$(Test_Dir)" ]; then \
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
