/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanmarquesvieira <jeanmarquesvieira@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:54:04 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/05 10:14:41 by jeanmarques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_str_arr(char **be_freed)
{
	int i;

	i = 0;
	while (be_freed[i])
	{
		free(be_freed[i]);
		i++;
	}
	free(*be_freed);
	exit(1);
}

void final_free(char **map, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

void free_line_arr(char **map, char *line)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	free(line);
}

void invalid_map(void)
{
	ft_printf("Error.\nInvalid map.\n");
	exit(1);
}

void fd_exit(int fd)
{
	close(fd);
	invalid_map();
}
