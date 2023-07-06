/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:33:05 by yushsato          #+#    #+#             */
/*   Updated: 2023/07/06 22:37:17 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_until_read(int fd, char c)
{
	char	*buf;
	char	*cache;
	char	*ret;
	size_t	len;

	buf = malloc(BUFFER_SIZE + 1);
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		cache = ft_strjoin(ret, buf);
		free(ret);
		ret = cache;
		cache = ft_strchr(buf, c);
		if (len <= 0 || cahce != NULL)
			break ;
	}
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*left;
	gnl_until_read(fd, '\n');
}

#include <stdio.h>

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
