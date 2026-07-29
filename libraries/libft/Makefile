# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/04 11:31:59 by lenivorb          #+#    #+#              #
#    Updated: 2026/05/12 22:53:54 by lenivorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------- variables --------------------

Compile 	= cc

Flags 		= -Wall -Wextra -Werror

Dont_link 	= -c

NAME		= ./libft.a

Includes 	= libft.h

Include 	= -I $(Includes)

Source		=	ft_atoi.c		ft_bzero.c 			ft_calloc.c \
				ft_isalnum.c	ft_isalpha.c		ft_isascii.c \
				ft_isdigit.c	ft_isprint.c		ft_memchr.c \
				ft_memcmp.c		ft_memcpy.c			ft_memmove.c \
				ft_memset.c		ft_strchr.c			ft_strdup.c \
				ft_strlcat.c	ft_strlcpy.c		ft_strlen.c \
				ft_strncmp.c	ft_strnstr.c		ft_strrchr.c \
				ft_tolower.c	ft_toupper.c \
				ft_substr.c		ft_strjoin.c		ft_strtrim.c \
				ft_split.c		ft_itoa.c			ft_strmapi.c \
				ft_striteri.c	ft_putchar_fd.c		ft_putstr_fd.c \
				ft_putendl_fd.c	ft_putnbr_fd.c \
				ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c \
				ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c \
				ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

Objects = $(Source:.c=.o)

# -------------------- commands --------------------

all : ./libft.a

re : fclean ./libft.a

fclean: clean
	rm -f ./libft.a

clean:
	rm -f $(Objects) $@

# -------------------- library --------------------

$(NAME) : $(Objects) $(Includes)
	ar rcs ./libft.a $(Objects)

# -------------------- object files --------------------

# --------> Basic Functions

./ft_atoi.o : ./ft_atoi.c $(Includes)
	$(Compile) $(Flags) ./ft_atoi.c $(Dont_link) $(Inlcude) -o ./ft_atoi.o

./ft_bzero.o : ./ft_bzero.c $(Includes)
	$(Compile) $(Flags) ./ft_bzero.c $(Inlcude) $(Dont_link) -o ./ft_bzero.o

./ft_calloc.o : ./ft_calloc.c $(Includes)
	$(Compile) $(Flags) ./ft_calloc.c $(Inlcude) $(Dont_link) -o ./ft_calloc.o

./ft_isalnum.o : ./ft_isalnum.c $(Includes)
	$(Compile) $(Flags) ./ft_isalnum.c $(Inlcude) $(Dont_link) -o ./ft_isalnum.o

./ft_isalpha.o : ./ft_isalpha.c $(Includes)
	$(Compile) $(Flags) ./ft_isalpha.c $(Inlcude) $(Dont_link) -o ./ft_isalpha.o

./ft_isascii.o : ./ft_isascii.c $(Includes)
	$(Compile) $(Flags) ./ft_isascii.c $(Inlcude) $(Dont_link) -o ./ft_isascii.o

./ft_isdigit.o : ./ft_isdigit.c $(Includes)
	$(Compile) $(Flags) ./ft_isdigit.c $(Inlcude) $(Dont_link) -o ./ft_isdigit.o

./ft_isprint.o : ./ft_isprint.c $(Includes)
	$(Compile) $(Flags) ./ft_isprint.c $(Inlcude) $(Dont_link) -o ./ft_isprint.o

./ft_memchr.o : ./ft_memchr.c $(Includes)
	$(Compile) $(Flags) ./ft_memchr.c $(Inlcude) $(Dont_link) -o ./ft_memchr.o

./ft_memcmp.o : ./ft_memcmp.c $(Includes)
	$(Compile) $(Flags) ./ft_memcmp.c $(Inlcude) $(Dont_link) -o ./ft_memcmp.o

./ft_memcpy.o : ./ft_memcpy.c $(Includes)
	$(Compile) $(Flags) ./ft_memcpy.c $(Inlcude) $(Dont_link) -o ./ft_memcpy.o

./ft_memmove.o : ./ft_memmove.c $(Includes)
	$(Compile) $(Flags) ./ft_memmove.c $(Inlcude) $(Dont_link) -o ./ft_memmove.o

./ft_memset.o : ./ft_memset.c $(Includes)
	$(Compile) $(Flags) ./ft_memset.c $(Inlcude) $(Dont_link) -o ./ft_memset.o

./ft_strchr.o : ./ft_strchr.c $(Includes)
	$(Compile) $(Flags) ./ft_strchr.c $(Inlcude) $(Dont_link) -o ./ft_strchr.o

./ft_strdup.o : ./ft_strdup.c $(Includes)
	$(Compile) $(Flags) ./ft_strdup.c $(Inlcude) $(Dont_link) -o ./ft_strdup.o

./ft_strlcat.o : ./ft_strlcat.c $(Includes)
	$(Compile) $(Flags) ./ft_strlcat.c $(Inlcude) $(Dont_link) -o ./ft_strlcat.o

./ft_strlcpy.o : ./ft_strlcpy.c $(Includes)
	$(Compile) $(Flags) ./ft_strlcpy.c $(Inlcude) $(Dont_link) -o ./ft_strlcpy.o

./ft_strlen.o : ./ft_strlen.c $(Includes)
	$(Compile) $(Flags) ./ft_strlen.c $(Inlcude) $(Dont_link) -o ./ft_strlen.o

./ft_strncmp.o : ./ft_strncmp.c $(Includes)
	$(Compile) $(Flags) ./ft_strncmp.c $(Inlcude) $(Dont_link) -o ./ft_strncmp.o

./ft_strnstr.o : ./ft_strnstr.c $(Includes)
	$(Compile) $(Flags) ./ft_strnstr.c $(Inlcude) $(Dont_link) -o ./ft_strnstr.o

./ft_strrchr.o : ./ft_strrchr.c $(Includes)
	$(Compile) $(Flags) ./ft_strrchr.c $(Inlcude) $(Dont_link) -o ./ft_strrchr.o

./ft_tolower.o : ./ft_tolower.c $(Includes)
	$(Compile) $(Flags) ./ft_tolower.c $(Inlcude) $(Dont_link) -o ./ft_tolower.o

./ft_toupper.o : ./ft_toupper.c $(Includes)
	$(Compile) $(Flags) ./ft_toupper.c $(Inlcude) $(Dont_link) -o ./ft_toupper.o

# --------> Advanced Functions

./ft_substr.o : ./ft_substr.c $(Includes)
	$(Compile) $(Flags) ./ft_substr.c $(Inlcude) $(Dont_link) -o ./ft_substr.o

./ft_strjoin.o : ./ft_strjoin.c $(Includes)
	$(Compile) $(Flags) ./ft_strjoin.c $(Inlcude) $(Dont_link) -o ./ft_strjoin.o

./ft_strtrim.o : ./ft_strtrim.c $(Includes)
	$(Compile) $(Flags) ./ft_strtrim.c $(Inlcude) $(Dont_link) -o ./ft_strtrim.o

./ft_split.o : ./ft_split.c $(Includes)
	$(Compile) $(Flags) ./ft_split.c $(Inlcude) $(Dont_link) -o ./ft_split.o

./ft_itoa.o : ./ft_itoa.c $(Includes)
	$(Compile) $(Flags) ./ft_itoa.c $(Inlcude) $(Dont_link) -o ./ft_itoa.o

./ft_strmapi.o : ./ft_strmapi.c $(Includes)
	$(Compile) $(Flags) ./ft_strmapi.c $(Inlcude) $(Dont_link) -o ./ft_strmapi.o

./ft_striteri.o : ./ft_striteri.c $(Includes)
	$(Compile) $(Flags) ./ft_striteri.c $(Inlcude) $(Dont_link) -o ./ft_striteri.o

./ft_putchar_fd.o : ./ft_putchar_fd.c $(Includes)
	$(Compile) $(Flags) ./ft_putchar_fd.c $(Inlcude) $(Dont_link) -o ./ft_putchar_fd.o

./ft_putstr_fd.o : ./ft_putstr_fd.c $(Includes)
	$(Compile) $(Flags) ./ft_putstr_fd.c $(Inlcude) $(Dont_link) -o ./ft_putstr_fd.o

./ft_putendl_fd.o : ./ft_putendl_fd.c $(Includes)
	$(Compile) $(Flags) ./ft_putendl_fd.c $(Inlcude) $(Dont_link) -o ./ft_putendl_fd.o

./ft_putnbr_fd.o : ./ft_putnbr_fd.c $(Includes)
	$(Compile) $(Flags) ./ft_putnbr_fd.c $(Inlcude) $(Dont_link) -o ./ft_putnbr_fd.o

# --------> linked list Functions

./ft_lstnew.o : ./ft_lstnew.c $(Includes)
	$(Compile) $(Flags) ./ft_lstnew.c $(Inlcude) $(Dont_link) -o ./ft_lstnew.o

./ft_lstadd_front.o : ./ft_lstadd_front.c $(Includes)
	$(Compile) $(Flags) ./ft_lstadd_front.c $(Inlcude) $(Dont_link) -o ./ft_lstadd_front.o

./ft_lstsize.o : ./ft_lstsize.c $(Includes)
	$(Compile) $(Flags) ./ft_lstsize.c $(Inlcude) $(Dont_link) -o ./ft_lstsize.o

./ft_lstlast.o : ./ft_lstlast.c $(Includes)
	$(Compile) $(Flags) ./ft_lstlast.c $(Inlcude) $(Dont_link) -o ./ft_lstlast.o

./ft_lstadd_back.o : ./ft_lstadd_back.c $(Includes)
	$(Compile) $(Flags) ./ft_lstadd_back.c $(Inlcude) $(Dont_link) -o ./ft_lstadd_back.o

./ft_lstdelone.o : ./ft_lstdelone.c $(Includes)
	$(Compile) $(Flags) ./ft_lstdelone.c $(Inlcude) $(Dont_link) -o ./ft_lstdelone.o

./ft_lstclear.o : ./ft_lstclear.c $(Includes)
	$(Compile) $(Flags) ./ft_lstclear.c $(Inlcude) $(Dont_link) -o ./ft_lstclear.o

./ft_lstiter.o : ./ft_lstiter.c $(Includes)
	$(Compile) $(Flags) ./ft_lstiter.c $(Inlcude) $(Dont_link) -o ./ft_lstiter.o

./ft_lstmap.o : ./ft_lstmap.c $(Includes)
	$(Compile) $(Flags) ./ft_lstmap.c $(Inlcude) $(Dont_link) -o ./ft_lstmap.o

# -------------------- PHONY --------------------

# follolws

.PHONY: all re fclean clean
