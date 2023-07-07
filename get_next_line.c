/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:33:05 by yushsato          #+#    #+#             */
/*   Updated: 2023/07/08 00:40:58 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_readchr(int fd, char *pre, char c)
{
	char	*buf;
	char	*cache;
	char	*ret;
	size_t	len;

	cache = ft_strjoin("", pre);
	len = 1;
	while (BUFFER_SIZE > 0 && ft_strchr(cache, c) == NULL && len > 0)
	{
		buf = ft_calloc(1, BUFFER_SIZE + 1);
		len = read(fd, buf, BUFFER_SIZE);
		ret = ft_strjoin(cache, buf);
		free(cache);
		cache = ret;
		ret = ft_strchr(buf, c);
		free(buf);
		if (ret != NULL)
			break ;
	}
	if (BUFFER_SIZE <= 0 || len <= 0)
		return (NULL);
	ret = cache;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*pre;
	char		*cache;
	char		*ret;
	char		*ptr;

	if (pre == NULL)
		pre = ft_calloc(1, 1);
	cache = gnl_readchr(fd, pre, '\n');
	if (cache == NULL)
		return (NULL);
	ptr = cache;
	while (*ptr != '\0' && *ptr != '\n')
		ptr++;
	if (*ptr == '\n')
		ptr++;
	free(pre);
	pre = ft_calloc(ft_strlen(ptr) + 1, 1);
	ft_memcpy(pre, ptr, ft_strlen(ptr));
	ret = ft_calloc(ptr - cache + 1, 1);
	ft_memcpy(ret, cache, ptr - cache);
	free(cache);
	return (ret);
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
