/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/22 12:32:59 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		ft_bzero(&game.set_map, (sizeof(t_map)));
		if (parse_map(argv[1]))
			return (ft_printf("Map format must be \".ber\".\n"));
		game.set_map.map = set_map(argv[1], &game.set_map);
	}
	else
		return (ft_printf("Invalid number of arguments.\n"));
	i = 0;
	// ft_printf("\n");
	// while (i < get_map_height(argv[1]))
	// 	ft_printf("%s", game.set_map.map[i++]);
	// i = 0;
	check_map(&game.set_map, game.set_map.map, game.set_map.height);
	get_init_pos(game.set_map, &game.player, game.set_map.height);
	flood_fill(game.set_map.map, game.set_map, game.player.pos_x,
		game.player.pos_y);
	final_free(game.set_map.map, game.set_map.height);
	ft_printf("\n***********\n\nempty: %d\n", game.set_map.empty);
	ft_printf("exit: %d\n", game.set_map.exit);
	ft_printf("height: %d\n", game.set_map.height);
	ft_printf("item: %d\n", game.set_map.item);
	ft_printf("length: %d\n", game.set_map.length);
	ft_printf("start: %d\n", game.set_map.start);
	ft_printf("wall: %d\n", game.set_map.wall);
	return (0);
}
