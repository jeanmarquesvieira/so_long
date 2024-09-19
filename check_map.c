/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:35:24 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/19 20:23:39 by jalves-v         ###   ########.fr       */
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

// t_map	flood_fill(char **map_arr, int x, int y)
// {
// 	t_map	test_map;

// 	if (map_arr[x][y] == 'P')
// 	{
// 		if (map_arr[x + 1][y] == '0')
// 			test_map.empty++;
// 		else if (map_arr[x + 1][y] == 'C')
// 			test_map.item++;
// 		else if (map_arr[x + 1][y] == 'E')
// 			test_map.exit++;
// 		map_arr[x + 1][y] = 'V';
// 		flood_fill(map_arr, x, y++);
// 	}
// 	else
// 		flood_fill(map_arr, x++, y);
// 	return (test_map);
// }
