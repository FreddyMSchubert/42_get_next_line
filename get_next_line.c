/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:24:54 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/19 11:39:12 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*char_src;
	char		*char_dst;
	size_t		counter;

	if (!src && !dst)
		return (NULL);
	char_src = (char *)src;
	char_dst = (char *)dst;
	counter = 0;
	while (counter < n)
	{
		char_dst[counter] = char_src[counter];
		counter++;
	}
	return (dst);
}

int	print_str(char *str)
{
	int		counter;
	char	temp_char;

	counter = 0;
	if (!str)
		return (print_str("(null)"));
	while (str[counter])
	{
		temp_char = (char)str[counter];
		if (write(1, &temp_char, 1) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	int			substr_len;
	int			s_len;

	substr_len = len;
	while (s[s_len])
		s_len++;
	if (s_len - start < len)
		substr_len = s_len - start;
	if (substr_len < 0)
		substr_len = 0;
	if (s_len < start)
		substr_len = 0;
	p = (char *)malloc(substr_len + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, &s[start], substr_len);
	p[substr_len] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	static int	curr_nl;
	int			last_nl;
	char		*buffer;

	last_nl = curr_nl;
	buffer = malloc(sizeof(char) * 500);
	read(fd, buffer, 500);
	while (buffer[curr_nl])
	{
		if (buffer[curr_nl] == '\n')
		{
			return (ft_substr(buffer, last_nl + 1, curr_nl - last_nl));
		}
		curr_nl++;
	}
	return (ft_substr(buffer, last_nl + 1, curr_nl - last_nl));
}
