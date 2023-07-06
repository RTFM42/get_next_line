/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:33:05 by yushsato          #+#    #+#             */
/*   Updated: 2023/07/07 00:34:57 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_readchr(int fd, char c)
{
	char	*buf;
	char	*cache;
	char	*ret;
	size_t	len;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	ret = malloc(1);
	*ret = '\0';
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		cache = ft_strjoin(ret, buf);
		free(ret);
		ret = cache;
		cache = ft_strchr(buf, c);
		if (len <= 0 || cache != NULL)
			break ;
	}
	free(buf);
	if (len <= 0)
		return (NULL);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str;

	str = gnl_readchr(fd, '\n');
	return (str);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("get_next_line.h", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}
