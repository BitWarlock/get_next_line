/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:44:44 by mrezki            #+#    #+#             */
/*   Updated: 2023/12/06 01:52:56 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_strchr(const char *s, int c)
{
        c = (unsigned char)c;
        while (*s)
        {
                if ((unsigned char)*s == c)
                        return ((char *)s);
                s++;
        }
        if (c == '\0')
                return ((char *)s);
        return (NULL);
}

char    *ft_strjoin(char *s1, char *s2)
{
        char    *ptr;
        int             len1;
        int             len2;
	int		i;
	int		j;

	i = -1;
        if (s1 == NULL || s2 == NULL)
                return (NULL);
        len1 = ft_strlen(s1);
        len2 = ft_strlen(s2);
        ptr = malloc(sizeof(char) * len1 + len2 + 1);
        if (!ptr)
                return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	j = -1;
	while (s2[++j])
		ptr[i++] = s2[j];
	ptr[len1 + len2] = '\0';
        return (ptr);
}
