/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:35:24 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/04 21:51:03 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map *new_map, char **_2d_map, int height)
{
	int	i;
	int	j;

	i = 0;
	if (!_2d_map || !*_2d_map)
		return ;
	while (i < height)
	{
		j = 0;
		while (_2d_map[i][j])
		{
			if (_2d_map[i][j] == '1')
				(*new_map).wall++;
			// else if (_2d_map[i][j] == '0')
			// 	(*new_map).empty++;
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

static char	**flood_fill_aux(char **map_arr, t_map map, int x, int y)
{
	if (x - 1 >= 0 && (map_arr[y][x - 1] == '0' || map_arr[y][x - 1] == 'C'
			|| map_arr[y][x - 1] == 'E'))
	{
		map_arr[y][x - 1] = 'X';
		flood_fill_aux(map_arr, map, x - 1, y);
	}
	if (x + 1 < map.length && (map_arr[y][x + 1] == '0' || map_arr[y][x
			+ 1] == 'C' || map_arr[y][x + 1] == 'E'))
	{
		map_arr[y][x + 1] = 'X';
		flood_fill_aux(map_arr, map, x + 1, y);
	}
	if (y - 1 >= 0 && (map_arr[y - 1][x] == '0' || map_arr[y - 1][x] == 'C'
			|| map_arr[y - 1][x] == 'E'))
	{
		map_arr[y - 1][x] = 'X';
		flood_fill_aux(map_arr, map, x, y - 1);
	}
	if (y + 1 < map.height && (map_arr[y + 1][x] == '0' || map_arr[y
			+ 1][x] == 'C' || map_arr[y + 1][x] == 'E'))
	{
		map_arr[y + 1][x] = 'X';
		flood_fill_aux(map_arr, map, x, y + 1);
	}
	return (map_arr);
}

char	**flood_fill(char **map_arr, t_map map, int x, int y)
{
	char	**checked_map;
	int		i;

	i = 0;
	checked_map = malloc(sizeof(char *) * (map.height + 1));
	if (!checked_map)
		return (NULL);
	while (i < map.height)
	{
		checked_map[i] = ft_strdup(map_arr[i]);
		if (!checked_map[i])
		{
			while (i >= 0)
				free(checked_map[i--]);
			free(checked_map);
			return (NULL);
		}
		i++;
	}
	checked_map[i] = NULL;
	flood_fill_aux(checked_map, map, x, y);
	return (checked_map);
}

int	check_flood_fill(char **is_map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	// print_map(is_map, 6);
	while (is_map[i])
	{
		j = 0;
		while (is_map[i][j])
		{
			if (is_map[i][j] == 'X')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
