/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanmarquesvieira <jeanmarquesvieira@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:42:45 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/05 10:29:20 by jeanmarques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_bottom_top(char **map_arr, t_map map)
{
	int i;
	int j;

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

static int check_left_right(char **map_arr, t_map map)
{
	int i;
	int j;
	int len;
	int temp_len;

	i = 0;
	while (i >= 0 && i < map.height)
	{
		j = 0;
		len = ft_strlen(map_arr[i]);
		ft_printf("len = %d\n", len);
		if (i == 0)
			temp_len = len;
		if (len != temp_len && len != temp_len - 1)
		{
			ft_printf("len = %d\n", len);
			return (0);
		}
		while (j >= 0 && j < len - 1)
		{
			if ((j == 0 || j == len - 2) && map_arr[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int is_wall(char **map_arr, t_map map)
{
	if (check_left_right(map_arr, map) == 0 || check_bottom_top(map_arr,
																map) == 0)
		return (0);
	return (1);
}
