# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeanmarquesvieira <jeanmarquesvieira@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 13:36:58 by jalves-v          #+#    #+#              #
#    Updated: 2024/09/16 00:28:43 by jeanmarques      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

$(RM) = rm -rf

$(FPF) = ../aux/ft_printf/
$(GNL) = ../aux/get_next_line/
$(LIB) = ../aux/libft/

SRC_SL =
SRC_LIB = $(LIB)ft_split.c $(LIB)ft_atoi.c $(LIB)ft_isdigit.c $(LIB)ft_calloc.c $(LIB)ft_bzero.c
SRC_GNL = $(GNL)get_next_line.c $(GNL)get_next_line_utils.c

SRC = $(SRC_SL) $(SRC_LIB) $(SRC_GNL)

SRC_OBJ = obj/

OBJ = $(addprefix $(SRC_OBJ), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(SRC_OBJ)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRC_OBJ)
	@echo "Object files have been deleted successfully."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) has been deleted successfully."

re: fclean all

.PHONY: all, clean, fclean
