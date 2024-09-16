/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:38:29 by jalves-v          #+#    #+#             */
/*   Updated: 2024/09/16 16:29:15 by jalves-v         ###   ########.fr       */
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
	char	*_2d_map;
	int		i;

	_2d_map = NULL;
	_2d_map = get_next_line(fd);
	if (_2d_map == NULL)
		return (0);
	new_map.line = _2d_map;
	ft_printf("%s", new_map.line);
	i = 0;
	while (_2d_map[i])
		i++;
	if (_2d_map[i - 1] == '\n')
		return (1);
	return (0);
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
