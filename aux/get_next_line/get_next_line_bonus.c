/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:02:54 by jalves-v          #+#    #+#             */
/*   Updated: 2024/05/21 17:40:30 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*current_line;
	int			bytes_read;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	current_line = NULL;
	bytes_read = 1;
	while (bytes_read != 0)
	{
		if (!*buffer[fd])
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read == 0)
			return (current_line);
		if (bytes_read < 0 && current_line)
			free(current_line);
		if (bytes_read < 0)
			return (NULL);
		current_line = ft_strjoin_n(current_line, buffer[fd]);
		if (get_remaining_line(buffer[fd]))
			return (current_line);
	}
	return (NULL);
}
