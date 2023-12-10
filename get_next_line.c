/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:44:42 by mrezki            #+#    #+#             */
/*   Updated: 2023/12/10 14:42:13 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/_types/_null.h>

static char	*ft_read_buffer(int fd, char *rest)
{
	char	*buffer;
	int		check;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(rest), free(buffer), NULL);
	check = 1;
	while (check > 0 && !(ft_strchr(rest, '\n')))
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check < 0)
			return (free(rest), free(buffer), NULL);
		buffer[check] = '\0';
		rest = ft_strjoin(rest, buffer);
		if (!rest)
			return (NULL);
	}
	free(buffer);
	return (rest);
}

static char	*ft_extract_line(char *rest)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!rest[i] || !rest[0])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	i += (rest[i] == '\n');
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (free(tmp), NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		tmp[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = 0;
	return (tmp);
}

static char	*ft_get_rest(char *rest)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\0')
		return (free(rest), NULL);
	i += (rest[i] == '\n');
	tmp = malloc((ft_strlen(rest) - i + 1));
	if (!tmp)
		return (NULL);
	while (rest[i])
		tmp[j++] = rest[i++];
	tmp[j] = '\0';
	free(rest);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read_buffer(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_extract_line(rest);
	rest = ft_get_rest(rest);
	return (line);
}
