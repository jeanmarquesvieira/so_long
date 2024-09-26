/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:54:04 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/26 13:08:45 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_str_arr(char **be_freed)
{
	int	i;

	i = 0;
	while (be_freed[i])
	{
		free(be_freed[i]);
		i++;
	}
	free(*be_freed);
	exit(1);
}

void	final_free(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

void	invalid_map(void)
{
	ft_printf("Invalid map.\n");
	exit(1);
}
