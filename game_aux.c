/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:49:25 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/27 14:53:34 by jalves-v         ###   ########.fr       */
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
	return (*graph);
}

void	move_player(t_graph graph, t_game *game, int pos_x, int pos_y)
{
	mlx_clear_window(graph.mlx, graph.win);
	draw_map(graph, &(game->set_map));
}
