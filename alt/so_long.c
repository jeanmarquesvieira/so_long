/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:28:20 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/04 21:46:21 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_map_aux(t_graph *graph, t_map *new_map, t_game game, int *pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < pos[0])
	{
		j = 0;
		while (j < pos[1])
		{
			if (new_map->map[i][j] == '1')
				mlx_put_image_to_window(graph->mlx, graph->win,
					graph->wall_s.img, j * 32, i * 32);
			else if (new_map->map[i][j] == 'P')
				mlx_put_image_to_window(graph->mlx, graph->win,
					graph->player_s.img, j * 32, i * 32);
			else if (new_map->map[i][j] == 'C')
				mlx_put_image_to_window(graph->mlx, graph->win,
					graph->item_s.img, j * 32, i * 32);
			else if (game.game_is_over == 1 && new_map->map[i][j] == 'E')
				mlx_put_image_to_window(graph->mlx, graph->win,
					graph->exit_s.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	draw_map(t_graph *graph, t_map *new_map, t_game game)
{
	int	x;
	int	y;
	int	pos[2];

	x = new_map->length;
	y = new_map->height;
	pos[0] = y;
	pos[1] = x;
	draw_map_aux(graph, new_map, game, pos);
}

static void	new_move(int pos_y, int pos_x, t_graph *graph, t_game *game)
{
	game->set_map.map[pos_y][pos_x] = 'P';
	game->player.pos_y = pos_y;
	game->player.pos_x = pos_x;
	mlx_clear_window(graph->mlx, graph->win);
	draw_map(graph, &game->set_map, *game);
}

static void	check_end_game(t_data *data, char curr, int moves)
{
	if (data->game->game_is_over != 0 && curr == 'E')
	{
		ft_printf("Moves: %d\n", ++moves);
		handle_close(data);
	}
}

void	move_player(t_game *game, t_data *data, int new_y, int new_x)
{
	static unsigned long long	moves;
	static int					exit_game = 0;

	check_end_game(data, game->set_map.map[new_y][new_x], moves);
	if (game->set_map.map[new_y][new_x] != '1')
	{
		ft_printf("Moves: %d\n", ++moves);
		if (game->set_map.map[new_y][new_x] == 'C')
		{
			game->set_map.item--;
			if (game->set_map.item <= 0)
				game->game_is_over = 1;
		}
		if (exit_game)
		{
			game->set_map.map[game->player.pos_y][game->player.pos_x] = 'E';
			exit_game = 0;
		}
		else
			game->set_map.map[game->player.pos_y][game->player.pos_x] = '0';
		if (game->set_map.map[new_y][new_x] == 'E')
			exit_game = 1;
		new_move(new_y, new_x, data->graph, game);
	}
}
