/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/19 20:29:26 by jalves-v         ###   ########.fr       */
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
	// while (i < get_map_height(argv[1]))
	// ft_printf("%s", game.set_map.map[i++]);
	// i = 0;
	check_map(&game.set_map, game.set_map.map, game.set_map.height);
	get_init_pos(game.set_map, &game.player, game.set_map.height);
	final_free(game.set_map.map, game.set_map.height);
	return (0);
}
