/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/02 18:40:42 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game;
	static t_graph	graph;
	static t_data	data;

	if (argc == 2)
		check_valid_map(&game, argv[1]);
	else
		return (ft_printf("Error.\nInvalid number of arguments.\n"));
	graph.mlx = mlx_init();
	if (graph.mlx == NULL)
		ft_mlx_error(game.set_map.map);
	graph.win = mlx_new_window(graph.mlx, (game.set_map.length - 1) * 32,
			game.set_map.height * 32, "so_long");
	if (graph.win == NULL)
		ft_window_err(graph.mlx, game.set_map.map);
	data.graph = &graph;
	data.game = &game;
	sprite_paths(&graph, game.set_map);
	draw_map(&graph, &game.set_map, game);
	mlx_hook(graph.win, 2, 1L << 0, key_handler, &data);
	mlx_hook(graph.win, 17, 1L << 0, handle_close, &data);
	mlx_loop(graph.mlx);
	final_free(game.set_map.map, game.set_map.height);
	return (0);
}
