/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:24:54 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/20 07:25:02 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// delete these later
#include <stdio.h>


/*
	@return		First index of \\n or -42
*/
int		get_line(char	*str)
{
	int		counter;

	counter = 0;
	while (str[counter] != '\0')
		if (str[counter] == '\n')
			return (counter);
	return (-42);
}

/*
	@brief		Mallocates if there is no space mallocated yet
*/
char	*defifndef(char	*str)
{
	if (str != NULL)
		return (str);
	else
		return (malloc(sizeof(char) * BUFFER_SIZE));
}

/*
	@brief		Concetanates two strings by mallocating newly and freeing the old dest
	@return		Concatenated String
*/
char	*cat_strings(char *dest, char *src)
{
	int		destlen;
	int		srclen;
	char	*new_dest;
	int		counter;

	while (dest[destlen])
		destlen++;
	while (src[srclen])
		srclen++;
	new_dest = malloc(sizeof(char) * (destlen + srclen));
	if (!new_dest)
		return (NULL);
	counter = 0;
	while (counter < destlen)
		new_dest[counter] = dest[counter];
	while (counter < destlen + srclen)
		new_dest[destlen + counter] = src[counter];
	free (dest);
	return (new_dest);
	
}

/*
	@brief Returns line by line from a file descriptor on repeated calls
	@var next_line:	Keeps the excess chars from last execution
	@var this_line:	Keeps chars until they form a new line
	@var buffer:	Buffer for read() to read into
*/
char	*get_next_line(int fd)
{
	static char		*next_line;
	char			*this_line;
	char			*buffer;
	int				new_line_index;

	next_line = defifndef(next_line);
	if (!next_line)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	new_line_index = get_line(next_line);
	if (new_line_index > -1)
	{
		next_line = gnl_substr(next_line, new_line_index, gnl_strlen(next_line));
		return (gnl_substr(next_line, 0, new_line_index));
	}
	else
		this_line = cat_strings(this_line, next_line);
	while (1)
	{
		read(fd, buffer, BUFFER_SIZE);
		this_line = cat_strings(this_line, buffer);
		new_line_index = get_line(next_line);
		if (new_line_index > -1)
		{
			next_line = gnl_substr(this_line, new_line_index, gnl_strlen(this_line));
			return (gnl_substr(this_line, 0, new_line_index));
		}
	}
}
