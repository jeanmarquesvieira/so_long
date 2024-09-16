/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:06 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/20 10:24:34 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_delimiters(char const *s, char c)
{
	int	delimiters;
	int	i;

	delimiters = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			delimiters++;
			while (s[i] && s[i] != c)
				i++;
			if (s[i] == '\0')
				return (delimiters);
		}
		i++;
	}
	return (delimiters);
}

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**populate_array(char const *s, char c, char **arr,
		int delimiters_num)
{
	int	i;
	int	j;

	i = 0;
	while (*s && i < delimiters_num)
	{
		while (*s == c && *s)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		arr[i] = ft_calloc(j + 1, sizeof(char));
		if (!arr[i])
			return (ft_free(arr), NULL);
		j = 0;
		while (*s != c && *s)
		{
			arr[i][j++] = *s;
			s++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**final_arr;
	int		delimiters_num;

	if (!s)
		return (NULL);
	delimiters_num = count_delimiters(s, c);
	final_arr = malloc(sizeof(char *) * (delimiters_num + 1));
	if (!final_arr)
		return (NULL);
	populate_array(s, c, final_arr, delimiters_num);
	return (final_arr);
}

// int	main(void)
// {
// 	int		i;
// 	char	c;
// 	char	s1[] = "this is a test";
// 	char	**split1;

// 	i = 0;
// 	c = ' ';
// 	// char s2[] = "    a   b   c  d     ";
// 	// char s3[] = "";
// 	// char s4[] = " ";
// 	split1 = ft_split(s1, c);
// 	// char **split2 = ft_split(s2, c);
// 	// char **split3 = ft_split(s3, c);
// 	// char **split4 = ft_split(s4, c);
// 	if (!split1)
// 		return (printf("null value returned\n"));
// 	while (split1[i])
// 		printf("s1: %s\n", split1[i++]);
// 	return (0);
// }