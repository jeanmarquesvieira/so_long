/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:45:06 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/28 12:46:03 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
