/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:44:42 by mrezki            #+#    #+#             */
/*   Updated: 2023/12/10 15:58:02 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

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
	static char	*rest[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = ft_read_buffer(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = ft_extract_line(rest[fd]);
	rest[fd] = ft_get_rest(rest[fd]);
	return (line);
}

int main()
{
	int fd1 = open("empty.txt", O_RDWR);
	int fd2 = open("basic.txt", O_RDWR);
	if (!fd1)
	{
		perror("Error opening file");
		return (1);
	}
	int i = 1;
	char *line1 = NULL;
	while ((line1 = get_next_line(fd1)) != NULL)
	{
		printf("Line number %02d: -> %s\n", i, line1);
		free(line1);
        	i++;
	}
	char *line2 = NULL;
	while ((line2 = get_next_line(fd2)) != NULL)
	{
		printf("Line number %02d: -> %s\n", i, line2);
		free(line2);
        	i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
