/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:44:44 by mrezki            #+#    #+#             */
/*   Updated: 2023/12/10 15:35:46 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*helper(char *ptr, int *len, char *rest, char *buffer)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(rest);
	len2 = ft_strlen(buffer);
	*len = len1 + len2;
	ptr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_strjoin(char *rest, char *buffer)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	ptr = NULL;
	i = -1;
	if (rest == NULL && buffer == NULL)
		return (NULL);
	if (!rest)
	{
		rest = malloc(1);
		*rest = '\0';
	}
	if (!buffer)
		return (NULL);
	ptr = helper(ptr, &len, rest, buffer);
	while (rest[++i])
		ptr[i] = rest[i];
	j = -1;
	while (buffer[++j])
		ptr[i++] = buffer[j];
	ptr[len] = '\0';
	free(rest);
	return (ptr);
}
