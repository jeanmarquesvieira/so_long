NAME = so_long
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

PRINTF = aux/ft_printf/libftprintf.a
LIBFT = aux/libft/libft.a
MLX = minilibx-linux/libmlx.a

SRC_GNL = aux/get_next_line/get_next_line.c aux/get_next_line/get_next_line_utils.c

SRC = so_long.c main.c parse_map.c print_error.c check_map.c check_map2.c aux.c game_aux.c check_wall.c $(SRC_GNL)

OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(PRINTF):
	@echo "${YELLOW}Compiling printf...${RESET}"
	@make -s -C ./aux/ft_printf

$(MLX):
	@echo "${YELLOW}Compiling mlx...${RESET}"
	@make -s -C minilibx-linux

$(LIBFT):
	@echo "${YELLOW}Compiling libft...${RESET}"
	@make -s -C ./aux/libft

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	@echo "${YELLOW}Linking object files and libraries...${RESET}"
	@${CC} ${CFLAGS} ${OBJ} $(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "${GREEN}$(NAME) created successfully.${RESET}"

%.o: %.c
	@echo "${YELLOW}Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}Cleaning object files...${RESET}"
	@$(RM) $(OBJ)
	@make clean -s -C ./aux/ft_printf
	@make clean -s -C ./minilibx-linux
	@make clean -s -C ./aux/libft

fclean: clean
	@echo "${RED}Deleting executable and libraries...${RESET}"
	@$(RM) $(NAME)
	@$(RM) $(PRINTF)
	@$(RM) $(MLX)
	@$(RM) $(LIBFT)
	@echo "${RED}$(NAME) deleted successfully.${RESET}"

re: fclean all

run: all
	@echo "${YELLOW}Running $(NAME)...${RESET}"
	@./$(NAME) maps/map1.ber

va: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map1.ber

v: all
	@valgrind ./$(NAME) maps/map1.ber

.PHONY: all, clean, fclean, re, run, va, v