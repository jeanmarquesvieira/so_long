/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanmarquesvieira <jeanmarquesvieira@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/16 22:47:38 by jeanmarques      ###   ########.fr       */
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
		if (parse_map(argv[1]))
			return (ft_printf("Map format must be \".ber\".\n"));
		game.set_map.map = set_map(argv[1], &game.set_map);
	}
	else
		return (ft_printf("Invalid number of arguments.\n"));
	i = 0;
	while (i < get_map_height(argv[1], game.set_map))
		ft_printf("%s", game.set_map.map[i++]);
	i = 0;
	check_map(&game.set_map);
	ft_printf("\nheight: %d\n", game.set_map.height);
	ft_printf("collectible: %d\n", game.set_map.item);
	ft_printf("length: %d\n", game.set_map.length);
	ft_printf("start: %d\n", game.set_map.start);
	ft_printf("wall: %d\n", game.set_map.wall);
	while (i < get_map_height(argv[1], game.set_map) - 1)
	{
		free(game.set_map.map[i]);
		i++;
	}
	free(game.set_map.map);
	return (0);
}
