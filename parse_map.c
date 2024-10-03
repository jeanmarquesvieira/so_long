/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:38:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/03 09:07:20 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(char *is_map)
{
	int			i;
	int			len;
	const char	ber[5] = ".ber";

	len = ft_strlen(is_map);
	if (len >= 4)
	{
		i = len - 4;
		return (ft_strncmp(is_map + i, ber, 4));
	}
	return (1);
}

static int	get_line(int fd, t_map *new_map)
{
	char		*_2d_map;
	static int	i;
	int			j;

	_2d_map = get_next_line(fd);
	if (_2d_map == NULL)
		return (-1);
	new_map->map = populate_2d_map(new_map, _2d_map, i);
	if (new_map->map == NULL)
	{
		return (-1);
		free_str(new_map->map);
		exit(1);
	}
	i++;
	j = 0;
	while (_2d_map[j])
		j++;
	if (_2d_map[j - 1] == '\n')
	{
		free(_2d_map);
		return (1);
	}
	free(_2d_map);
	return (0);
}

char	**populate_2d_map(t_map *new_map, char *line, int index)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_strlen(line);
	if (line[line_len - 2] != '1' && line[line_len - 2] != '\0')
	{
		free_line_arr(new_map->map, line);
		return (NULL);
	}
	new_map->length = line_len;
	new_map->map[index] = malloc((sizeof(char) * line_len) + 1);
	if (!new_map->map[index])
		return (NULL);
	while (line[i])
	{
		new_map->map[index][i] = line[i];
		i++;
	}
	new_map->map[index][i] = '\0';
	return (new_map->map);
}

int	get_map_height(char *map_path)
{
	int		fd;
	int		map_height;
	char	*read_map;

	map_height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("Error.\nUnable to open map file.\n");
		exit(1);
	}
	read_map = get_next_line(fd);
	while (read_map != NULL)
	{
		free(read_map);
		map_height++;
		read_map = get_next_line(fd);
	}
	close(fd);
	return (map_height);
}

char	**set_map(char *map_path, t_game *game, t_map *new_map)
{
	int	map_height;
	int	fd;
	int	check_map;

	map_height = get_map_height(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd < 3)
		exit(ft_printf("Error.\nUnable to open map file.\n"));
	new_map->map = ft_calloc(sizeof(char *), map_height + 1);
	if (!new_map->map)
		return (close(fd), NULL);
	check_map = 1;
	while (check_map != 0)
	{
		check_map = get_line(fd, new_map);
		if (check_map == -1)
			fd_exit(fd);
	}
	game->set_map.height = map_height;
	close(fd);
	return (new_map->map);
}
