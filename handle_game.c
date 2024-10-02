/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:45:06 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/02 16:41:40 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		move_player(data, (*game).player.pos_y, (*game).player.pos_x - 1);
	else if (keysym == 0xff53)
		move_player(data, (*game).player.pos_y, (*game).player.pos_x + 1);
	else if (keysym == 0xff52)
		move_player(data, (*game).player.pos_y - 1, (*game).player.pos_x);
	else if (keysym == 0xff54)
		move_player(data, (*game).player.pos_y + 1, (*game).player.pos_x);
	return (0);
}
