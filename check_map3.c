/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:42:45 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/02 18:48:21 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_bottom_top(char **map_arr, t_map map)
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
	return (1);
}

static int	check_left_right(char **map_arr, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i >= 0 && i < map.height)
	{
		j = 0;
		while (j >= 0 && j < map.length - 1)
		{
			if ((j == 0 || j == map.length - 2) && map_arr[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_wall(char **map_arr, t_map map)
{
	if (check_left_right(map_arr, map) == 0 || check_bottom_top(map_arr,
			map) == 0)
		return (0);
	return (1);
}
