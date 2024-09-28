/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/28 11:59:07 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_graph	graph;
	t_data	data;
	int		i;

	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		if (parse_map(argv[1]))
			return (ft_printf("Error.\nMap format must be \".ber\".\n"));
		game.set_map.map = set_map(argv[1], &game, &game.set_map);
		i = validate_map(&game);
		if (i == -1)
		{
			final_free(game.set_map.map, game.set_map.height);
			exit(1);
		}
	}
	else
		return (ft_printf("Error.\nInvalid number of arguments.\n"));
	graph.mlx = mlx_init();
	graph.win = mlx_new_window(graph.mlx, (game.set_map.length - 1) * 32,
			game.set_map.height * 32, "so_long");
	data.graph = &graph;
	data.game = &game;
	draw_map(graph, &game.set_map, game);
	mlx_hook(graph.win, 2, 1L << 0, key_handler, &data);
	mlx_hook(graph.win, 17, 1L << 0, handle_close, &graph);
	mlx_loop(graph.mlx);
	final_free(game.set_map.map, game.set_map.height);
	return (0);
}
