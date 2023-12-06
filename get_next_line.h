/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:44:39 by mrezki            #+#    #+#             */
/*   Updated: 2023/12/06 01:58:09 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 42
#endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(const char *s, int c);

#endif
