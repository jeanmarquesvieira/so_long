/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/16 19:54:08 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		if (parse_map(argv[1]))
			return (ft_printf("Map format must be \".ber\".\n"));
		game.set_map.map = set_map(game.set_map, argv[1]);
	}
	else
		return (ft_printf("Invalid number of arguments.\n"));
	i = 0;
	while (i < get_map_height(argv[1]))
		ft_printf("%s", game.set_map.map[i++]);
	i = 0;
	while (i < get_map_height(argv[1] - 1))
	{
		free(game.set_map.map[i]);
		i++;
	}
	free(game.set_map.map);
	return (0);
}
