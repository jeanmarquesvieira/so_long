/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:28:20 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/28 09:16:45 by jalves-v         ###   ########.fr       */
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

void	move_player(t_graph *graph, t_game *game, int new_y, int new_x)
{
	if (game->set_map.map[new_y][new_x] != '1')
	{
		ft_printf("test\n");
		game->set_map.map[game->player.pos_y][game->player.pos_x] = '0';
		game->set_map.map[new_y][new_x] = 'P';
		game->player.pos_y = new_y;
		game->player.pos_x = new_x;
		mlx_clear_window(graph->mlx, graph->win);
		draw_map(*graph, &game->set_map);
	}
}

int	handle_close(t_graph *graph)
{
	mlx_destroy_window((*graph).mlx, (*graph).win);
	// mlx_clear_window(graph.mlx, graph.win);
	exit(0);
}

int	key_handler(int keysym, t_graph *graph, t_game *game)
{
	if (keysym == 0xff1b)
		handle_close(graph);
	else if (keysym == 0xff51 && !(*game).game_is_over)
	{
		ft_printf("left\n");
		move_player(graph, game, (*game).player.pos_y, (*game).player.pos_x
			- 1);
	}
	else if (keysym == 0xff53 && !(*game).game_is_over)
	{
		ft_printf("right\n");
		move_player(graph, game, (*game).player.pos_y, (*game).player.pos_x
			+ 1);
	}
	else if (keysym == 0xff52 && !(*game).game_is_over)
	{
		ft_printf("up\n");
		move_player(graph, game, (*game).player.pos_y - 1,
			(*game).player.pos_x);
	}
	else if (keysym == 0xff54 && !(*game).game_is_over)
	{
		ft_printf("down\n");
		move_player(graph, game, (*game).player.pos_y + 1,
			(*game).player.pos_x);
	}
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
