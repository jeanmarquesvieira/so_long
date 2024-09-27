/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:28:20 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/27 13:03:37 by jalves-v         ###   ########.fr       */
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
	x = 8;
	y = (*new_map).height;
	i = 0;
	ft_printf("length: %d\n", (*new_map).length);
	while (i < (*new_map).height)
	{
		j = 0;
		while (j < 13)
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

int	handle_close(t_graph graph)
{
	mlx_destroy_window(graph.mlx, graph.win);
	// mlx_clear_window(graph.mlx, graph.win);
	exit(0);
}

int	key_handler(int keycode, t_graph graph, t_game game)
{
	if (keycode == 27 || keycode == 65307)
		handle_close(graph);
	(void)game;
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
