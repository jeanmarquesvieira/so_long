#include "so_long.h"

void	check_map(t_map *new_map)
{
	int		i;
	int		j;
	char	**_2d_map;

	i = 0;
	_2d_map = (*new_map).map;
	// printf("len: %d\n", (int)ft_strlen(*_2d_map));
	while (*_2d_map && _2d_map[i] && i < 8)
	{
		j = 0;
		while (_2d_map[i][j])
		{
			if (_2d_map[i][j] == '1')
				(*new_map).wall++;
			else if (_2d_map[i][j] == '0')
				(*new_map).empty++;
			else if (_2d_map[i][j] == 'C')
				(*new_map).item++;
			else if (_2d_map[i][j] == 'P')
				(*new_map).start++;
			else if (_2d_map[i][j] == 'E')
				(*new_map).exit++;
			j++;
		}
		i++;
	}
	(*new_map).length = ft_strlen(*_2d_map);
}
