# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 13:06:57 by hael-bri          #+#    #+#              #
#    Updated: 2020/03/02 15:48:30 by hael-bri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAMELIBFT = libft.a
LIBFT = libft
MAKE = make -C
FLAGS = -Wall -Wextra -Werror
CC = gcc
AR= ar rcs

INCLUDES = ./includes/

SRC =	srcs/ft_printf.c \
		srcs/check_in.c \
		srcs/parse_error.c \
		srcs/print_char.c \
		srcs/print_string.c \
		srcs/print_int.c \
		srcs/print_unsint.c \
		srcs/print_hex.c \
		srcs/hexa.c \
		srcs/print_pointer.c \
	
SRC_LIBFT = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_count_digit.c \
			ft_index_of.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putendl.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putunbr.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \

OBJ = $(SRC:.c=.o)

OBJ_LIBFT = $(addprefix $(LIBFT)/,$(SRC_LIBFT:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIBFT)
	@cp ./libft/libft.h ./includes
	@echo "making $(NAME) ... : done"
	@$(AR) $(NAME) $(OBJ) $(OBJ_LIBFT)
	@cp ./includes/*.h ./

%.o:%.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_LIBFT)
	@echo "cleaning objects  : done"

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/$(NAMELIBFT)
	@rm -rf *.h
	@rm -rf ./a.out
	@echo "All is clean"

re: fclean all
