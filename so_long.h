#ifndef SO_LONG_H
# define SO_LONG_H

# include "./aux/ft_printf/ft_printf.h"
# include "./aux/get_next_line/get_next_line.h"
# include "./aux/libft/libft.h"
# include "./minilibx-linux/mlx.h"

typedef struct s_map
{
	char		**map;
	int			map_is_valid;
	int			empty;
	int			wall;
	int			item;
	int			exit;
	int			start;
	int			exit_game;
	int			height;
	int			length;
}				t_map;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
}				t_player;

typedef struct s_game
{
	t_map		set_map;
	t_player	player;
	int			game_is_over;
	int			moves;
}				t_game;

/** parse_map.c **/
int				parse_map(char *is_map);
int				get_map(int fd, t_map set_map);
char			**populate_2d_map(t_map new_map, char *line, int index);
int				get_map_height(char *map_path);
char			**set_map(char *map_path, t_map *new_map);

/** print_error.c **/
void			free_str_arr(char **be_freed);
void			final_free(char **map, int height);
void			invalid_map(void);

/** check_map.c **/
void			check_map(t_map *new_map, char **_2d_map, int height);
void			get_init_pos(t_map new_map, t_player *player, int height);
char			**flood_fill(char **map_arr, t_map map, int x, int y);
int				check_flood_fill(char **is_map);

/** check_map2.c **/
int				is_map(t_map map, int count);
void			validate_map(t_game game);
int				is_wall(char **map_arr, t_map map);
int				is_map_rectangular(char **map, int length, int height);
void			map_count(t_map *map);

/** aux.c **/
void			free_str(char **str);
void			print_map(char **map, int height);
int			check_rows(char **map, int height);

/** so_long.c **/
// void			start_game(t_game *game);

#endif
