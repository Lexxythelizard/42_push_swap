# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/10 19:30:37 by lenivorb          #+#    #+#              #
#    Updated: 2026/07/03 15:30:44 by lenivorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------- variables --------------------

# library name

NAME			= 	./libftprintf.a

# MODE

DEBUGG_MODE		=	0

# for compile

Compile 		= 	cc

Flags 			= 	-Wall -Wextra -Werror

Include 		= 	-I

Dont_link 		= 	-c

Dest	 		= 	-o

Debugg_mode		=	-g

# directories

This_Dir		=	.

Core_Dir		= 	$(This_Dir)/core

Src_Dir			= 	$(This_Dir)/src

Struct_Dir		= 	$(This_Dir)/struct

# headers

User_Lib 		= 	ft_prinft.h

Incl_This		=	$(Include) $(This_Dir)

Incl_Core		=	$(Include) $(Core_Dir)

Incl_Struct		=	$(Include) $(Struct_Dir)

		# soruce files

SrcCore_Files	=	$(Src_Dir)/core_call_put_layer_0.c \
					$(Src_Dir)/core_call_put_layer_1_0.c \
					$(Src_Dir)/core_call_put_layer_1_1.c \
					$(Src_Dir)/core_flags.c \
					$(Src_Dir)/core_process.c \
					$(Src_Dir)/core_put_abstraction.c \
					$(Src_Dir)/core_put_chars.c \
    	            $(Src_Dir)/core_put_hexa_lowercase.c \
        	        $(Src_Dir)/core_put_hexa_uppercase.c \
					$(Src_Dir)/core_put_signed_nbr.c \
					$(Src_Dir)/core_put_unsigned_nbr.c \
					$(Src_Dir)/core_scan.c \
					$(Src_Dir)/core_utils_get_strlen.c \
    	            $(Src_Dir)/core_utils_put_nbr_to_base.c \
    	            $(Src_Dir)/core_utils_specifier.c

Printf_Files	=	$(Src_Dir)/ft_printf.c 

Printf_B_Files	=	$(Src_Dir)/ft_printf_bonus.c 

Src_Files		=	$(SrcCore_Files)	$(Printf_Files)

# --------------------> set default
default: all
# <-------------------- end default

SrcCore_Obj 	=	$(SrcCore_Files:.c=.o)

Printf_Obj 		=	$(Printf_Files:.c=.o)

All_Obj			=	$(SrcCore_Obj)	$(Printf_Obj)

Printf_B_Obj 	=	$(Printf_B_Files:.c=.o)

Bonus_Obj 		=	$(SrcCore_Obj)  $(Printf_B_Obj)

# -------------------- compile rules --------------------

$(SrcCore_Obj): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(Flags) $(Dont_link) $(Debugg_mode) \
		$(Incl_Core) $< $(Dest) $@; \
	else \
		$(Compile) $(Flags) $(Dont_link) \
		$(Incl_Core) $< $(Dest) $@; \
	fi

$(Printf_Obj): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(Flags) $(Dont_link) $(Debugg_mode) \
		$(Incl_Core) $(Incl_This) $< $(Dest) $@; \
	else \
		$(Compile) $(Flags) $(Dont_link) \
		$(Incl_Core) $(Incl_This) $< $(Dest) $@; \
	fi

$(Printf_B_Obj): %.o: %.c
	if [ "$(DEBUGG_MODE)" -eq "1" ]; then \
		$(Compile) $(Flags) $(Dont_link) $(Debugg_mode) \
		$(Incl_Core) $(Incl_This) $< $(Dest) $@; \
	else \
		$(Compile) $(Flags) $(Dont_link) \
		$(Incl_Core) $(Incl_This) $< $(Dest) $@; \
	fi

# -------------------- commands --------------------

all : $(NAME)

re : fclean all

bonus : $(NAME)

fclean: clean
	rm -f $(NAME)

clean: clean_printf clean_srccore

clean_printf:
	rm -f $(Printf_Obj) $@

clean_srccore:
	rm -f $(SrcCore_Obj) $@

# -------------------- library --------------------

$(NAME): $(All_Obj)
	ar rcs $(NAME) $(All_Obj)

# -------------------- PHONY --------------------

.PHONY: all re fclean clean clean_printf clean_src default bonus
