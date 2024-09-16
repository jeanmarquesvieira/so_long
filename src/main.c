/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/16 17:19:01 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	int		check_map;
	int		map_height;

	fd = 0;
	map_height = 0;
	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		fd = open(argv[1], O_RDONLY);
		if (fd < 3)
			return (-1);
		while (get_next_line(fd) != NULL)
			map_height++;
		close(fd);
		fd = open(argv[1], O_RDONLY);
		game.set_map.map = malloc(sizeof(char *) * 8);
		if (!game.set_map.map)
			return (-1);
		check_map = 1;
		while (check_map != 0)
			check_map = get_map(fd, game.set_map);
	}
	else
		return (-1);
	map_height = 0;
	while (map_height < 8)
	{
		ft_printf("%i >>> %s", map_height, game.set_map.map[map_height]);
		map_height++;
	}
	close(fd);
	return (0);
}
