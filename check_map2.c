/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:17:05 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/24 21:41:12 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map(t_map map, int count)
{
	int	count_map;

	count_map = map.empty + map.exit + map.item;
	if (count_map == count)
		return (1);
	return (0);
}

int	is_wall(char **map_arr, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i >= 0 && i < map.height)
	{
		j = 0;
		while (j >= 0 && j < map.length - 1)
		{
			if ((i == 0 || i == map.height - 1) && map_arr[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i >= 0 && i < map.height)
	{
		j = 1;
		while (j > 0 && j < map.length - 1)
		{
			if ((j == 0 || j == map.length - 1) && map_arr[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_rectangular(char **map, int length, int height)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != length)
			return (0);
		i++;
	}
	if (i != height)
		return (0);
	return (1);
}

void	validate_map(t_game game)
{
	char	**map_arr;
	int		count;

	check_map(&game.set_map, game.set_map.map, game.set_map.height);
	get_init_pos(game.set_map, &game.player, game.set_map.height);
	map_arr = flood_fill(game.set_map.map, game.set_map, game.player.pos_x,
			game.player.pos_y);
	// count = check_flood_fill(map_arr);
	// ft_printf("is_wall: %d\n", is_wall(game.set_map.map, game.set_map));
	count = is_map_rectangular(game.set_map.map, game.set_map.length,
			game.set_map.height);
	ft_printf("count %d\n", count);
	// if (is_map(game.set_map, count))
	// ft_printf("map is valid\n");
	// else
	// ft_printf("invalid map\n");
	print_map(map_arr);
}
