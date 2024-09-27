/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/27 12:32:07 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	my_mlx_pixel_put(t_graph *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	main(int argc, char **argv)
{
	t_game	game;
	t_graph	graph;
	int		i;

	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		if (parse_map(argv[1]))
			return (ft_printf("Map format must be \".ber\".\n"));
		game.set_map.map = set_map(argv[1], &game, &game.set_map);
		i = validate_map(&game);
		ft_printf("main %d\n", game.set_map.length);
		if (i == -1)
		{
			final_free(game.set_map.map, game.set_map.height);
			exit(1);
		}
	}
	else
		return (ft_printf("Invalid number of arguments.\n"));
	graph.mlx = mlx_init();
	graph.win = mlx_new_window(graph.mlx, 256, 384, "so_long");
	draw_map(graph, &game.set_map);
	mlx_hook(graph.win, 2, 1L << 0, key_handler, &graph);
	mlx_hook(graph.win, 17, 1L << 0, handle_close, &graph);
	mlx_loop(graph.mlx);
	final_free(game.set_map.map, game.set_map.height);
	return (0);
}
