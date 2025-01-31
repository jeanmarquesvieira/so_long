/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanmarquesvieira <jeanmarquesvieira@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:48:34 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/06 18:25:47 by jeanmarques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./aux/ft_printf/ft_printf.h"
#include "./aux/get_next_line/get_next_line.h"
#include "./aux/libft/libft.h"
#include "./minilibx-linux/mlx.h"

typedef struct s_map
{
	char **map;
	int map_is_valid;
	int empty;
	int wall;
	int item;
	int exit;
	int start;
	int exit_game;
	int height;
	int length;
} t_map;

typedef struct s_player
{
	int pos_x;
	int pos_y;
} t_player;

typedef struct s_game
{
	t_map set_map;
	t_player player;
	int game_is_over;
	int items_num;
	int moves;
} t_game;

typedef struct s_sprite
{
	int width;
	int height;
	void *img;
} t_sprite;

typedef struct s_graph
{
	void *img;
	void *mlx;
	void *win;
	char *addr;
	t_sprite wall_s;
	t_sprite item_s;
	t_sprite exit_s;
	t_sprite player_s;
	int line_length;
	int endian;
	int moves;
	int items_found;
} t_graph;

typedef struct s_data
{
	t_graph *graph;
	t_game *game;
} t_data;

/** parse_map.c **/
int parse_map(char *is_map);
char **populate_2d_map(t_map *new_map, char *line, int index);
int get_map_height(char *map_path);
char **set_map(char *map_path, t_game *game, t_map *new_map);

/** print_error.c **/
void free_str_arr(char **be_freed);
void final_free(char **map, int height);
void invalid_map(void);
void fd_exit(int fd);
void ft_window_err(void *mlx, char **map);

/** check_map.c **/
void check_map(t_map *new_map, char **_2d_map, int height);
void get_init_pos(t_map new_map, t_player *player, int height);
char **flood_fill(char **map_arr, t_map map, int x, int y);
int check_flood_fill(char **is_map, char **original);

/** check_map2.c **/
int is_map(t_map map, int count);
int validate_map(t_game *game);
int is_wall(char **map_arr, t_map map);
int is_map_rectangular(char **map, int length, int height);
void map_count(t_map *map);

/** aux.c **/
void free_str(char **str);
void print_map(char **map, int height);
void ft_mlx_error(char **map);

/** so_long.c **/
void draw_map(t_graph *graph, t_map *new_map, t_game game);
int key_handler(int keysym, t_data *data);

/** game_aux.c **/
void sprite_paths(t_graph *graph, t_map map);
void move_player(t_game *game, t_data *data, int new_y, int new_x);
void check_valid_map(t_game *game, char *map_path);

/** handle_game.c **/
int handle_close(t_data *data);
int key_handler(int keysym, t_data *data);

int check_map_cells(char **map);
void free_line_arr(char **map, char *line);

#endif
