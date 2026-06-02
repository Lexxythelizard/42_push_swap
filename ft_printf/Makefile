# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/11 15:07:41 by rcollet           #+#    #+#              #
#    Updated: 2026/05/15 19:27:55 by rcollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCL = incl

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

define CLEAN_NAME =
rm -f $(NAME)
endef

define COMPILE_OBJ = 
cc -c -I$(INCL) $(CFLAGS) $< -o $@
endef 

FILES = ft_printf.c print.c helper.c

HEADERS = ft_printf.h 

BONUS_HEADERS = $(HEADERS:_bonus.h=.h)

SRC = $(addprefix src/, $(FILES))

BONUS = $(SRC:.c=_bonus.c)

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

bonus: $(BONUS_OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rs $(NAME) $(BONUS_OBJ)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $@
	ar rs $(NAME) $(OBJ)

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT))

$(OBJ): %.o: %.c
	$(COMPILE_OBJ)

$(BONUS_OBJ): %.o: %.c
	$(COMPILE_OBJ)

clean-libft:
	$(MAKE) fclean -C $(dir $(LIBFT))

clean: clean-libft
	rm -f $(OBJ)

clean-bonus: clean-libft
	rm -f $(BONUS_OBJ)

clean-all: clean clean-bonus

fclean: clean
	$(CLEAN_NAME)

fclean-bonus: clean-bonus
	$(CLEAN_NAME)

fclean-all: clean-all
	$(CLEAN_NAME)

re: fclean-all all

re-bonus: fclean-all bonus

.PHONY: all bonus clean-libft clean clean-bonus clean-all fclean fclean-bonus \
		fclean-all re re-bonus
