# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-bri <hael-bri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 20:43:19 by ikharbou          #+#    #+#              #
#    Updated: 2020/03/02 15:46:33 by hael-bri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

INCLUDES = libft.h

SRC =		ft_atoi.c \
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

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c $(INCLUDES)
	@gcc $(FLAG) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

