/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:28:20 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/27 15:13:17 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_graph graph, t_map *new_map)
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
					i * 32, j * 32);
			else if ((*new_map).map[i][j] == 'P')
				mlx_put_image_to_window(graph.mlx, graph.win,
					graph.player_s.img, i * 32, j * 32);
			else if ((*new_map).map[i][j] == 'C')
				mlx_put_image_to_window(graph.mlx, graph.win, graph.item_s.img,
					i * 32, j * 32);
			j++;
		}
		i++;
	}
}

int	handle_close(t_graph *graph)
{
	mlx_destroy_window((*graph).mlx, (*graph).win);
	// mlx_clear_window(graph.mlx, graph.win);
	exit(0);
}

int	key_handler(int keysym, t_graph graph, t_game game)
{
	if (keysym == 0xff1b)
		handle_close(&graph);
	else if (keysym == 0xff51 && !game.game_is_over)
		move_player(graph, &game, game.player.pos_y, game.player.pos_x - 1);
	else if (keysym == 0xff53 && !game.game_is_over)
		move_player(graph, &game, game.player.pos_y, game.player.pos_x + 1);
	else if (keysym == 0xff52 && !game.game_is_over)
		move_player(graph, &game, game.player.pos_y - 1, game.player.pos_x);
	else if (keysym == 0xff54 && !game.game_is_over)
		move_player(graph, &game, game.player.pos_y + 1, game.player.pos_x);
	// else if (keycode == 2 && !game.game_is_over)
	// 	update_player_position(graph, (t_point){graph->player.pos.px_x + 1,
	// 												graph->player.pos.px_y});
	// else if (keycode == 0 && !graph->won)
	// 	update_player_position(graph, (t_point){graph->player.pos.px_x - 1,
	// 												graph->player.pos.px_y});
	// else if (keycode == 13 && !graph->won)
	// 	update_player_position(graph, (t_point){graph->player.pos.px_x,
	// 											graph->player.pos.px_y - 1});
	// else if (keycode == 1 && !graph->won)
	// 	update_player_position(graph, (t_point){graph->player.pos.px_x,
	// 											graph->player.pos.px_y + 1});
	return (0);
}

void	update_player_position(t_graph *graph, t_game game)
{
	ft_printf("Total moves: %d\n", ++game.moves);
	if (game.player.pos_x < game.set_map.height
		&& game.player.pos_y < game.set_map.height)
	{
		if (game.set_map.map[game.player.pos_y][game.player.pos_x] == 'C')
		{
			game.items_num++;
			game.set_map.map[game.player.pos_y][game.player.pos_x] = '0';
			if (game.items_num == game.set_map.item)
				game.set_map.exit_game = 1;
		}
		else if (game.set_map.map[game.player.pos_y][game.player.pos_x] == 'E'
			&& game.set_map.exit_game == 1)
		{
			// vars->player.pos = np;
			game.game_is_over = 1;
		}
		// else if (game.set_map.map[game.player.pos_y][game.player.pos_x] != '1')
		// vars->player.pos = np;
	}
}

// void	update_player_position(t_vars *vars, t_point np)
// {
// 	ft_printf("Total moves: %d\n", ++vars->moves);
// 	if (np.px_x < vars->map.g_w && np.px_y < vars->map.g_h)
// 	{
// 		if (vars->map.grid[np.px_y][np.px_x] == COLLECT)
// 		{
// 			vars->collected++;
// 			vars->map.grid[np.px_y][np.px_x] = FLOOR;
// 			if (vars->collected == vars->collectibles)
// 				vars->exit_unlocked = 1;
// 			vars->player.pos = np;
// 		}
// 		else if (vars->map.grid[np.px_y][np.px_x] == EXIT
// 			&& vars->exit_unlocked)
// 		{
// 			vars->player.pos = np;
// 			vars->won = 1;
// 		}
// 		else if (vars->map.grid[np.px_y][np.px_x] != WALL)
// 			vars->player.pos = np;
// 	}
// }

void	compose_map(t_graph graph, t_sprite sprite, char block)
{
	if (block == '1')
		mlx_put_image_to_window(graph.mlx, graph.win, graph.wall_s.img,
			sprite.height, sprite.width);
	else if (block == 'C')
		mlx_put_image_to_window(graph.mlx, graph.win, graph.item_s.img,
			sprite.height, sprite.width);
	else if (block == 'P')
	{
		mlx_put_image_to_window(graph.mlx, graph.win, graph.player_s.img,
			sprite.height, sprite.width);
	}
	else if (block == 'E')
	{
		mlx_put_image_to_window(graph.mlx, graph.win, graph.exit_s.img,
			sprite.height, sprite.width);
	}
}
