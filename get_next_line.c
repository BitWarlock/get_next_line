/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:44:42 by mrezki            #+#    #+#             */
/*   Updated: 2023/12/06 01:54:12 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_rest(int fd, char *rest)
{
	char	*buffer;
	int	check;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rest = strdup("");
	check = read(fd, buffer, BUFFER_SIZE);
	while (check && !(ft_strchr(rest, '\n')))
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check < 0)
			return (free(buffer), NULL);
		rest = ft_strjoin(rest, buffer);
		rest[check] = '\0';
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_rest(fd, rest);
	if (!rest)
		return (NULL);
	// line = ft_extract_line(rest);

	return (line);
}
