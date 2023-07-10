/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:33:05 by yushsato          #+#    #+#             */
/*   Updated: 2023/07/10 10:46:33 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_concat(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	len1 = 0;
	len2 = 0;
	if (s1 != 0x0)
		while (s1[len1] != '\0')
			len1++;
	if (s2 != 0x0)
		while (s2[len2] != '\0')
			len2++;
	ret = malloc(len1 + len2 + 1);
	if (s1 != 0x0)
		while (*s1)
			*ret++ = *s1++;
	if (s2 != 0x0)
		while (*s2)
			*ret++ = *s2++;
	*ret = '\0';
	return (ret);
}

static char	*gnl_readchr(int fd, char *cache)
{
	char	*ret;
	char	*tmp;
	char	*buf;
	ssize_t	len;

	buf = malloc(BUFFER_SIZE + 1);
	ret = gnl_concat(cache, 0x0);
	len = 1;
	while (len > 0 && ft_strchr(ret, '\n') == NULL)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
			return (0x0);
		buf[len] = '\0';
		tmp = ret;
		ret = gnl_concat(ret, buf);
		free(tmp);
	}
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*tmp;
	char		*ptr;
	char		*ret;

	tmp = gnl_readchr(fd, cache);
	if (cache != 0x0)
		free(cache);
	ptr = ft_strchr(tmp, '\n');
	cache = gnl_concat(ptr, NULL);
	ret = malloc(ptr - tmp + 2);
	ret[ptr - tmp + 1] = '\0';
	ft_memcpy(ret, tmp, ptr - tmp + 1);
	free(tmp);
	return (ret);
}

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("./get_next_line.h", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}
