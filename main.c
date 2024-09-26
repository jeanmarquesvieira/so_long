/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:18:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/26 15:16:40 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	my_mlx_pixel_put(t_graph *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_graph	img;
	void	*mlx;
	void	*mlx_win;
	int		i;

	if (argc == 2)
	{
		ft_bzero(&game, sizeof(t_game));
		if (parse_map(argv[1]))
			return (ft_printf("Map format must be \".ber\".\n"));
		game.set_map.map = set_map(argv[1], &game.set_map);
		i = validate_map(game);
		if (i == -1)
		{
			final_free(game.set_map.map, game.set_map.height);
			exit(1);
		}
	}
	else
		return (ft_printf("Invalid number of arguments.\n"));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 720, "Hello world!");
	img.img = mlx_new_image(mlx, 640, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	final_free(game.set_map.map, game.set_map.height);
	return (0);
}
