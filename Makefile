# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 22:19:48 by adjoly            #+#    #+#              #
#    Updated: 2024/10/15 11:43:03 by thomarna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft/libft.a

CC = clang
SRCS = 	ft_printf.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra

HEADER = ft_printf.h

$(NAME): $(OBJS)
	ar -rcs	$(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADER) $< -c -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
