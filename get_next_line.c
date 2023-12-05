/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:44:42 by mrezki            #+#    #+#             */
/*   Updated: 2023/12/05 23:34:40 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buffer(int fd, char *rest, char *buffer)
{
	int	check;
	int	i;

	i = 0;
	check = read(fd, buffer, BUFFER_SIZE);
	if (check < 0)
		return (NULL);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (ft_substr(buffer, 0, i + 1));
		i++;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer = ft_read_buffer(fd, rest, buffer);
	printf("%s\n", buffer);
	// line = ft_extract_line(rest, buffer);

	return (line);
}
