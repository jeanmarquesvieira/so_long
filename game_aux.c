/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:49:25 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/03 09:54:21 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_paths(t_graph *graph, t_map map)
{
	(graph)->player_s.img = mlx_xpm_file_to_image((graph)->mlx,
			"./sprites/player.xpm", &map.height, &map.length);
	(graph)->wall_s.img = mlx_xpm_file_to_image((graph)->mlx,
			"./sprites/wall.xpm", &map.height, &map.length);
	(graph)->item_s.img = mlx_xpm_file_to_image((graph)->mlx,
			"./sprites/item.xpm", &map.height, &map.length);
	(graph)->exit_s.img = mlx_xpm_file_to_image((graph)->mlx,
			"./sprites/exit.xpm", &map.height, &map.length);
}

void	check_valid_map(t_game *game, char *map_path)
{
	int	is_valid;

	is_valid = parse_map(map_path);
	if (is_valid != 0)
		exit(ft_printf("Error.\nMap format must be \".ber\".\n"));
	game->set_map.map = set_map(map_path, game, &(game)->set_map);
	if (game->set_map.map == NULL)
	{
		exit(ft_printf("Error.\nFailed to load map.\n"));
	}
	if (check_map_cells(game->set_map.map) == -1)
	{
		ft_printf("Error.\nInvalid map.\n");
		exit(1);
	}
	is_valid = validate_map(game);
	if (is_valid == -1)
	{
		final_free(game->set_map.map, game->set_map.height);
		exit(1);
	}
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->graph->mlx, data->graph->player_s.img);
	mlx_destroy_image(data->graph->mlx, data->graph->wall_s.img);
	mlx_destroy_image(data->graph->mlx, data->graph->exit_s.img);
	mlx_destroy_image(data->graph->mlx, data->graph->item_s.img);
	mlx_destroy_window(data->graph->mlx, data->graph->win);
	mlx_destroy_display(data->graph->mlx);
	free(data->graph->mlx);
	free_str(data->game->set_map.map);
	exit(0);
}

int	key_handler(int keysym, t_data *data)
{
	t_game	*game;

	game = data->game;
	if (keysym == 0xff1b)
		handle_close(data);
	else if (keysym == 0xff51)
		move_player(game, data, game->player.pos_y, game->player.pos_x - 1);
	else if (keysym == 0xff53)
		move_player(game, data, game->player.pos_y, game->player.pos_x + 1);
	else if (keysym == 0xff52)
		move_player(game, data, game->player.pos_y - 1, game->player.pos_x);
	else if (keysym == 0xff54)
		move_player(game, data, game->player.pos_y + 1, game->player.pos_x);
	return (0);
}
