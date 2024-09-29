/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:51:15 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/29 08:50:45 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}

int	check_map_cells(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != 'E' && map[i][j] != '1'
				&& map[i][j] != 'P' && map[i][j] && map[i][j] != 'C'
				&& map[i][j] != '\n')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
