# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 20:28:54 by jalves-v          #+#    #+#              #
#    Updated: 2024/04/29 11:05:14 by jalves-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_printf.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c 

OBJ_FILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rc $(NAME) $(OBJ_FILES)
	@echo "File $(NAME) has been created successfully."
	@ranlib $(NAME)
	@echo "File $(NAME) has been indexed successfully."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_FILES)
	@echo "Object files have been deleted successfully."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) has been deleted successfully."

re: fclean all

run:
	@cc main.c libftprintf.a && ./a.out | cat -e

.PHONY: all, clean, fclean, re, run