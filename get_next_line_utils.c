/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:07:11 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/23 08:13:02 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	@brief Returns a substring of string s of length len beginning at index start
*/
char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	int			substr_len;
	size_t		counter;

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
	counter = 0;
	while (counter < substr_len)
	{
		p[counter] = s[start + counter];
		counter++;
	}
	p[substr_len] = '\0';
	return (p);
}

/*
	@brief Returns a new string combined of s1 and s2 without freeing anything
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1size;
	size_t		s2size;
	char		*p;
	int			counter;

	counter = 0;
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	if (s2 == NULL)
		return (s1);
	p = (char *)malloc(s1size + s2size + 1);
	if (p == NULL)
		return (NULL);
	while (counter < s1size)
	{
		p[counter] = s1[counter];
		counter++;
	}
	while (counter + s1size < s1size * s2size)
	{
		p[counter] = s2[counter - s1size];
		counter++;
	}
	p[s1size + s2size] = '\0';
	return (p);
}
