/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:07:11 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/23 15:54:20 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

/*
	@brief Returns a substring of string s of length len beginning at index start
*/
char	*gnl_substr(char const *s, int start, size_t len)
{
	char		*p;
	size_t		substr_len;
	size_t		counter;

	substr_len = len;
	if (ft_strlen(s) - start < (int) len)
		substr_len = ft_strlen(s) - start;
	if (substr_len < 0 || ft_strlen(s) < start)
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
	size_t		counter;
	char		*p;

	counter = 0;
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	if (s2 == NULL)
		return ((char *) s1);
	p = (char *)malloc(s1size + s2size + 1);
	if (p == NULL)
		return (NULL);
	while (counter < s1size)
	{
		p[counter] = s1[counter];
		counter++;
	}
	while (counter < s1size + s2size)
	{
		p[counter] = s2[counter - s1size];
		counter++;
	}
	p[s1size + s2size] = '\0';
	return (p);
}
