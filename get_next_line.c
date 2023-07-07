/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:33:05 by yushsato          #+#    #+#             */
/*   Updated: 2023/07/07 17:03:51 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_readchr(int fd, char *pre, char c)
{
	char	*buf;
	char	*cache;
	char	*ret;
	size_t	len;

	ret = ft_strjoin("", pre);
	len = 1;
	while (BUFFER_SIZE > 0 && ft_strchr(ret, c) != NULL)
	{
		buf = ft_calloc(1, BUFFER_SIZE + 1);
		len = read(fd, buf, BUFFER_SIZE);
		cache = ft_strjoin(ret, buf);
		free(ret);
		ret = cache;
		cache = ft_strchr(buf, c);
		free(buf);
		if (len <= 0 || cache != NULL)
			break ;
	}
	if (BUFFER_SIZE <= 0 || len <= 0)
		return (NULL);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*pre;
	char		*str;
	char		*ptr;
	char		*ret;

	if (pre == NULL)
		pre = ft_calloc(1, 1);
	str = gnl_readchr(fd, pre, '\n');
	free(pre);
	ptr = ft_strchr(str, '\n');
	if (ptr == NULL)
		return (str);
	ret = ft_calloc(ptr - str + 2, 1);
	ft_memcpy(ret, str, ptr - str + 1);
	pre = ft_calloc(ft_strlen(ptr) + 1, 1);
	ft_memcpy(pre, str, ft_strlen(ptr));
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
