/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:18:19 by yushsato          #+#    #+#             */
/*   Updated: 2023/07/15 21:18:42 by yushsato         ###   ########.fr       */
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
			ret[tlen + slen] = '\0';
		}
	}
	if (target)
		free(target);
	return (ret);
}

char	*gnl_nread(int fd, char *cache)
{
	char	*buf;
	ssize_t	len;

	if (BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	len = 1;
	while (gnl_strchr(cache, '\n') == NULL)
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
	if (len < 0)
		cache = NULL;
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*ptr;
	char		*tmp;
	char		*ret;

	cache = gnl_nread(fd, cache);
	if (cache == NULL)
		return (NULL);
	ptr = gnl_strchr(cache, '\n');
	if (ptr == NULL)
	{
		ptr = cache;
		cache = NULL;
		return (ptr);
	}
	tmp = gnl_strjoin(NULL, ptr + 1);
	ret = malloc(ptr - cache + 2);
	if (ret == NULL)
		return (NULL);
	ret[ptr - cache + 1] = '\0';
	ft_memcpy(ret, cache, ptr - cache + 1);
	free(cache);
	cache = tmp;
	return (ret);
}

//int	main(void)
//{
//	int		fd;
//	char	*line = "";
//
//	fd = open("./gnlTester/files/42_with_nl", O_RDONLY);
//	while (line)
//	{
//		line = get_next_line(fd);
//		printf("%s", line);
//		if (line)
//			free(line);
//	}
//	return (0);
//}
