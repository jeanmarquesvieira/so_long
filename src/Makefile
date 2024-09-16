# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 13:36:58 by jalves-v          #+#    #+#              #
#    Updated: 2024/09/16 15:09:20 by jalves-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

GNL = ../aux/get_next_line/
FPF = ../aux/ft_printf/
LIB = ../aux/libft/

SRC_SL = so_long.c main.c parse_map.c
SRC_LIB = $(LIB)ft_split.c $(LIB)ft_calloc.c $(LIB)ft_bzero.c $(LIB)ft_strlen.c $(LIB)ft_strncmp.c $(LIB)ft_strjoin.c
SRC_GNL = $(GNL)get_next_line.c $(GNL)get_next_line_utils.c
SRC_FPF = $(FPF)ft_printf.c $(FPF)ft_putchar.c $(FPF)ft_putnbr.c $(FPF)ft_putstr.c

SRC = $(SRC_SL) $(SRC_LIB) $(SRC_GNL) $(SRC_FPF)

SRC_OBJ = obj/

OBJ = $(addprefix $(SRC_OBJ), $(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(SRC_OBJ)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM)r $(OBJ)
	@echo "Object files have been deleted successfully."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) has been deleted successfully."

re: fclean all

.PHONY: all, clean, fclean, re
