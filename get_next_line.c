/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:18:19 by yushsato          #+#    #+#             */
/*   Updated: 2023/07/15 15:43:56 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *target, char *str)
{
	size_t	tlen;
	size_t	slen;
	char	*ret;

	tlen = 0;
	if (target != NULL)
		tlen = ft_strlen(target);
	slen = 0;
	if (str != NULL)
		slen = ft_strlen(str);
	ret = NULL;
	if (tlen + slen != 0)
	{
		ret = malloc(tlen + slen + 1);
		if (ret)
		{
			ft_memcpy(ret, target, tlen);
			ft_memcpy(ret + tlen, str, slen);
			ret[tlen+slen] = '\0';
		}
	}
	if (target)
		free(target);
	return (ret);
}

char	*gnl_uread(int fd, char *cache)
{
	char	*buf;
	ssize_t	len;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ft_strchr(cache, '\n') == NULL)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buf[len] = '\0';
		cache = gnl_strjoin(cache, buf);
		if (cache == NULL)
			break ;
	}
	free(buf);
	if (len < 0 && cache != NULL)
		free(cache);
	if (cache == NULL || len < 0)
		return (NULL);
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;

	cache = gnl_uread(fd, cache);
	return (cache);
}

int	main(void)
{
	int		fd;
	char	*line = "";

	fd = open("./get_next_line.h", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}
