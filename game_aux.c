/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:49:25 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/29 08:13:00 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graph	sprite_paths(t_graph *graph, t_map map)
{
	(graph)->player_s.img = mlx_xpm_file_to_image((graph)->mlx,
			"./sprites/player.xpm", &map.height, &map.length);
	(graph)->wall_s.img = mlx_xpm_file_to_image((graph)->mlx,
			"./sprites/wall.xpm", &map.height, &map.length);
	(graph)->item_s.img = mlx_xpm_file_to_image((graph)->mlx,
			"./sprites/item.xpm", &map.height, &map.length);
	(graph)->exit_s.img = mlx_xpm_file_to_image((graph)->mlx,
			"./sprites/exit.xpm", &map.height, &map.length);
	return (*graph);
}

// void	init_game(t_data *data, t_graph *graph)
// {
// 	sprite_paths(graph, data->game->set_map);
// 	draw_map(graph, &(data)->game->set_map, *(data)->game);
// 	mlx_hook(graph->win, 2, 1L << 0, key_handler, &data);
// 	mlx_hook(graph->win, 17, 1L << 0, handle_close, graph);
// 	mlx_loop(graph->mlx);
// }

void	check_valid_map(t_game *game, char *map_path)
{
	int	is_valid;

	is_valid = parse_map(map_path);
	if (is_valid != 0)
		exit(ft_printf("Error.\nMap format must be \".ber\".\n"));
	game->set_map.map = set_map(map_path, game, &(game)->set_map);
	if (game->set_map.map == NULL)
		exit(ft_printf("Error loading map.\n"));
	if (check_map_cells(game->set_map.map) == -1)
		exit(ft_printf("Error.\nInvalid map.\n"));
	is_valid = validate_map(game);
	if (is_valid == -1)
	{
		final_free(game->set_map.map, game->set_map.height);
		exit(ft_printf("Error.\nInvalid map.\n"));
	}
}
