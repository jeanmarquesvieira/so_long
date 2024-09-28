/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:28:20 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/28 12:08:51 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_graph graph, t_map *new_map, t_game game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	graph = sprite_paths(&graph, *new_map);
	x = (*new_map).length;
	y = (*new_map).height;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((*new_map).map[i][j] == '1')
				mlx_put_image_to_window(graph.mlx, graph.win, graph.wall_s.img,
					j * 32, i * 32);
			else if ((*new_map).map[i][j] == 'P')
				mlx_put_image_to_window(graph.mlx, graph.win,
					graph.player_s.img, j * 32, i * 32);
			else if ((*new_map).map[i][j] == 'C')
				mlx_put_image_to_window(graph.mlx, graph.win, graph.item_s.img,
					j * 32, i * 32);
			else if (game.game_is_over == 1 && (*new_map).map[i][j] == 'E')
				mlx_put_image_to_window(graph.mlx, graph.win, graph.exit_s.img,
					j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	move_player(t_graph *graph, t_game *game, int new_y, int new_x)
{
	static int	moves;

	if (game->game_is_over != 0 && game->set_map.map[new_y][new_x] == 'E')
	{
		ft_printf("Moves: %d\n", ++moves);
		handle_close(graph);
	}
	else if (game->set_map.map[new_y][new_x] != '1')
	{
		ft_printf("Moves: %d\n", ++moves);
		if (game->set_map.map[new_y][new_x] == 'C')
		{
			game->set_map.item--;
			if (game->set_map.item <= 0)
				game->game_is_over = 1;
		}
		game->set_map.map[game->player.pos_y][game->player.pos_x] = '0';
		game->set_map.map[new_y][new_x] = 'P';
		game->player.pos_y = new_y;
		game->player.pos_x = new_x;
		mlx_clear_window(graph->mlx, graph->win);
		draw_map(*graph, &game->set_map, *game);
	}
}

int	handle_close(t_graph *graph)
{
	mlx_destroy_window((*graph).mlx, (*graph).win);
	exit(0);
}

int	key_handler(int keysym, t_data *data)
{
	t_graph	*graph;
	t_game	*game;

	game = data->game;
	graph = data->graph;
	if (keysym == 0xff1b)
		handle_close(graph);
	else if (keysym == 0xff51 /*&&  !(*game).game_is_over */)
		move_player(graph, game, (*game).player.pos_y, (*game).player.pos_x
			- 1);
	else if (keysym == 0xff53 /*&&  !(*game).game_is_over */)
		move_player(graph, game, (*game).player.pos_y, (*game).player.pos_x
			+ 1);
	else if (keysym == 0xff52 /*&&  !(*game).game_is_over */)
		move_player(graph, game, (*game).player.pos_y - 1,
			(*game).player.pos_x);
	else if (keysym == 0xff54 /*&&  !(*game).game_is_over */)
		move_player(graph, game, (*game).player.pos_y + 1,
			(*game).player.pos_x);
	return (0);
}
