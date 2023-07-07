/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@doche.io>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:29:49 by yushsato          #+#    #+#             */
/*   Updated: 2023/07/08 00:17:13 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = (char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len;
	char	*ret;

	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	if (!s2)
		len2 = 0;
	else
		len2 = ft_strlen(s2);
	ret = (char *)malloc(len1 + len2 + sizeof(char));
	if (!ret)
		return (0);
	len = len1 + len2 + 1;
	while (len--)
		ret[len] = '\0';
	ft_memcpy(ret, s1, len1);
	ft_memcpy(ret + len1, s2, len2);
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	const char	cc = (const char)c;

	while (s != NULL && *s != cc)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (count && size && size > SIZE_MAX / count)
		return (0);
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	if (ptr)
	{
		i = 0;
		while (i < size * count)
			((char *)ptr)[i++] = '\0';
	}
	return (ptr);
}
