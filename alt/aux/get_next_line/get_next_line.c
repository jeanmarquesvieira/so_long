/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:41:40 by jalves-v          #+#    #+#             */
/*   Updated: 2024/05/15 22:28:29 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*current_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_line = NULL;
	bytes_read = 1;
	while (bytes_read != 0)
	{
		if (!*buffer)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (current_line);
		if (bytes_read < 0 && current_line)
			free(current_line);
		if (bytes_read < 0)
			return (NULL);
		current_line = ft_strjoin_n(current_line, buffer);
		if (get_remaining_line(buffer))
			return (current_line);
	}
	return (NULL);
}
