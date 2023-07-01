/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:33:05 by yushsato          #+#    #+#             */
/*   Updated: 2023/06/29 22:19:31 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_read()
{

}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*prev_buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	prev_buf = gnl_read(fd, prev_buf);

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
