/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:17:52 by jalves-v          #+#    #+#             */
/*   Updated: 2024/05/14 10:53:35 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_n(char *s)
{
	int	i;

	i = 0;
	if (s && *s)
	{
		while (s[i] != '\n' && s[i])
			i++;
		if (s[i] == '\n')
			i++;
	}
	return (i);
}

int	get_remaining_line(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			buf[i++] = '\0';
			while (buf[i])
			{
				buf[j++] = buf[i];
				buf[i++] = '\0';
			}
			buf[j] = '\0';
			return (1);
		}
		buf[i++] = '\0';
	}
	return (0);
}

char	*ft_strjoin_n(char *current_line, char *buf)
{
	char	*attached_str;
	int		final_len;
	int		i;

	final_len = ft_strlen_n(buf) + ft_strlen_n(current_line) + 1;
	attached_str = malloc(sizeof(char) * final_len);
	if (!attached_str)
		return (NULL);
	i = 0;
	while (current_line && current_line[i])
	{
		attached_str[i] = current_line[i];
		i++;
	}
	free(current_line);
	while (*buf)
	{
		attached_str[i++] = *buf;
		if (*buf++ == '\n')
			break ;
	}
	attached_str[i] = '\0';
	return (attached_str);
}
