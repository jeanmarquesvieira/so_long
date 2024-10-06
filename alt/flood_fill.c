#include "so_long.h"

static void flood_fill_left(char **map_arr, t_map map, int *pos, int *count)
{
	int x;
	int y;
	static int count_items;

	y = pos[0];
	x = pos[1];
	if (x - 1 >= 0 && (map_arr[y][x - 1] == '0' || map_arr[y][x - 1] == 'C' || map_arr[y][x - 1] == 'E' || map_arr[y][x - 1] == 'X'))
	{
		if (map_arr[y][x - 1] == 'C' || map_arr[y][x - 1] == 'E')
			count_items++;
		map_arr[y][x - 1] = 'X';
		pos[1] = x - 1;
		flood_fill_left(map_arr, map, pos, count);
	}
	*count += count_items;
}

static void flood_fill_right(char **map_arr, t_map map, int *pos, int *count)
{
	int x;
	int y;
	static int count_items;

	y = pos[0];
	x = pos[1];
	if (x + 1 < map.length && (map_arr[y][x + 1] == '0' || map_arr[y][x + 1] == 'C' || map_arr[y][x + 1] == 'E' || map_arr[y][x + 1] == 'X'))
	{
		if (map_arr[y][x + 1] == 'C' || map_arr[y][x + 1] == 'E')
			count_items++;
		map_arr[y][x + 1] = 'X';
		pos[1] = x + 1;
		flood_fill_right(map_arr, map, pos, count);
	}
	*count += count_items;
}

static void flood_fill_down(char **map_arr, t_map map, int *pos, int *count)
{
	int x;
	int y;
	static int count_items;

	y = pos[0];
	x = pos[1];
	if (y - 1 >= 0 && (map_arr[y - 1][x] == '0' || map_arr[y - 1][x] == 'C' || map_arr[y - 1][x] == 'E' || map_arr[y - 1][x] == 'X'))
	{
		if (map_arr[y - 1][x] == 'C' || map_arr[y - 1][x] == 'E')
			count_items++;
		map_arr[y - 1][x] = 'X';
		pos[0] = y - 1;
		flood_fill_down(map_arr, map, pos, count);
	}
	*count += count_items;
}

static void flood_fill_up(char **map_arr, t_map map, int *pos, int *count)
{
	int x;
	int y;
	static int count_items;

	y = pos[0];
	x = pos[1];
	if (y + 1 < map.height && (map_arr[y + 1][x] == '0' || map_arr[y + 1][x] == 'C' || map_arr[y + 1][x] == 'E' || map_arr[y + 1][x] == 'X'))
	{
		if (map_arr[y + 1][x] == 'C' || map_arr[y + 1][x] == 'E')
			count_items++;
		map_arr[y + 1][x] = 'X';
		pos[0] = y + 1;
		flood_fill_up(map_arr, map, pos, count);
	}
	*count += count_items;
}

int flood_fill(char **map_arr, t_map map, int x, int y)
{
	static int count;
	int pos[2];

	pos[0] = y;
	pos[1] = x;
	flood_fill_left(map_arr, map, pos, &count);
	flood_fill_right(map_arr, map, pos, &count);
	flood_fill_up(map_arr, map, pos, &count);
	flood_fill_down(map_arr, map, pos, &count);
	print_map(map_arr, map.height);
	return (count);
}