/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/16 16:29:12 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	int		check_map;
	int		i;

	fd = 0;
	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		if (game.set_map.map == NULL)
			fd = open(argv[1], O_RDONLY);
		if (fd < 3)
			return (-1);
		check_map = get_map(fd, game.set_map);
		while (check_map == 1)
		{
			check_map = get_map(fd, game.set_map);
			get_map(fd, game.set_map);
		}
	}
	else
		return (-1);
	i = 0;
	close(fd);
	return (0);
}
