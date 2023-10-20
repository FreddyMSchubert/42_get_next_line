/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:43:51 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/20 06:52:26 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	@return			Substring

	@param s		Input String
	@param start	Substring Start Index
	@param len		Substring length
*/
char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	int			substr_len;

	substr_len = len;
	if (ft_strlen(s) - start < len)
		substr_len = ft_strlen(s) - start;
	if (substr_len < 0)
		substr_len = 0;
	if (ft_strlen(s) < start)
		substr_len = 0;
	p = (char *)malloc(substr_len + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, &s[start], substr_len);
	p[substr_len] = '\0';
	return (p);
}

/*
	@return (size_t)Length of inputted string
*/
size_t	gnl_strlen(const char *s)
{
	size_t		counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}
