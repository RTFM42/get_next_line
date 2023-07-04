/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:33:05 by yushsato          #+#    #+#             */
/*   Updated: 2023/07/04 23:28:13 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_read(int fd, char *left)
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
		cache = ft_strchr(buf, '\n');
		if (cahce == NULL)
			
	}
}

char	*get_next_line(int fd)
{
	static char	*left;

}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 
// 	line = "";
// 	fd = open("get_next_line.h", O_RDONLY);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
