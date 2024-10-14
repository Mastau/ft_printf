# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 22:19:48 by thomarna          #+#    #+#              #
#    Updated: 2024/10/14 20:22:53 by thomarna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
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

bonus: $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
