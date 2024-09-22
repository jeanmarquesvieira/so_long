/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:35:24 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/22 13:43:20 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map *new_map, char **_2d_map, int height)
{
	int	i;
	int	j;

	i = 0;
	(*new_map).length = ft_strlen(*_2d_map);
	while (i < height)
	{
		j = 0;
		while (_2d_map[i][j])
		{
			if (_2d_map[i][j] == '1')
				(*new_map).wall++;
			else if (_2d_map[i][j] == '0')
				(*new_map).empty++;
			else if (_2d_map[i][j] == 'C')
				(*new_map).item++;
			else if (_2d_map[i][j] == 'P')
				(*new_map).start++;
			else if (_2d_map[i][j] == 'E')
				(*new_map).exit++;
			j++;
		}
		i++;
	}
}

void	get_init_pos(t_map new_map, t_player *player, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (new_map.map[i][j])
		{
			if (new_map.map[i][j] == 'P')
			{
				player->pos_x = j;
				player->pos_y = i;
			}
			j++;
		}
		i++;
	}
}

t_map	flood_fill(char **map_arr, t_map map, int x, int y)
{
	static t_map	test_map;

	ft_printf("x: %d * y: %d\n", x, y);
	// ft_printf("%c\n", map_arr[y][x]);
	// exit(0);
	if (x >= 0 && y >= 0 && x < map.length && y < map.height)
	{
		if (map_arr[y + 1][x] == '0')
		{
			test_map.empty++;
			ft_printf("Empty space found\n");
			map_arr[y + 1][x] = 'X';
			flood_fill(map_arr, map, x, y + 1);
		}
		else if (map_arr[y + 1][x] == 'C')
		{
			test_map.item++;
			ft_printf("Item found\n");
			map_arr[y + 1][x] = 'X';
			flood_fill(map_arr, map, x, y + 1);
		}
		else if (map_arr[y + 1][x] == 'E')
		{
			test_map.exit++;
			ft_printf("Exit found\n");
			map_arr[y + 1][x] = 'X';
			flood_fill(map_arr, map, x, y + 1);
		}
		else if (map_arr[y + 1][x] == '1')
		{
			test_map.wall++;
			ft_printf("Wall found\n");
			map_arr[y + 1][x] = 'X';
			flood_fill(map_arr, map, x - 1, y);
		}
		else if (map_arr[y + 1][x] == 'X')
		{
			ft_printf("X found\n");
			flood_fill(map_arr, map, x, y + 1);
		}
	}
	else
	{
		ft_printf("\nempty: %d\n", test_map.empty);
		ft_printf("exit: %d\n", test_map.exit);
		ft_printf("height: %d\n", test_map.height);
		ft_printf("item: %d\n", test_map.item);
		ft_printf("length: %d\n", test_map.length);
		ft_printf("start: %d\n", test_map.start);
		ft_printf("wall: %d\n\n", test_map.wall);
		print_map(map_arr);
	}
	return (test_map);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_printf("%s", map[i++]);
	ft_printf("\n");
}
