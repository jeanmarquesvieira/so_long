/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:38:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/16 17:18:57 by jalves-v         ###   ########.fr       */
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

int	get_map(int fd, t_map new_map)
{
	char		*_2d_map;
	static int	i;
	int			j;

	_2d_map = NULL;
	_2d_map = get_next_line(fd);
	if (_2d_map == NULL && i != 0)
	{
		new_map.map[i] = 0;
		return (0);
	}
	new_map.map = populate_2d_map(new_map, _2d_map, i);
	i++;
	j = 0;
	while (_2d_map[j])
		j++;
	if (_2d_map[j - 1] == '\n')
		return (1);
	return (0);
}

char	**populate_2d_map(t_map new_map, char *line, int index)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_strlen(line);
	new_map.map[index] = malloc((sizeof(char) * line_len) + 1);
	if (!new_map.map[index])
		return (NULL);
	while (line[i])
	{
		new_map.map[index][i] = line[i];
		i++;
	}
	new_map.map[index][i] = '\0';
	// ft_printf("%s", new_map.map[index]);
	return (new_map.map);
}



// char	**get_map(t_map new_map, char *is_map)
// {
// 	static char	**_2d_map = NULL;
// 	static int	i = 0;
// 	int			j;
// 	int			fd;

// 	fd = open(is_map, O_RDONLY);
// 	if (fd < 3)
// 		exit(1);
// 	j = 0;
// 	_2d_map[i] = get_next_line(fd);
// 	exit(0);
// 	while (_2d_map[i][j])
// 		j++;
// 	if (_2d_map[i][j - 1] == '\n')
// 	{
// 		i++;
// 		get_map(new_map, is_map);
// 	}
// 	close(fd);
// 	return (_2d_map);
// }
