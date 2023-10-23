/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:24:54 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/23 08:23:44 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char	*str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

int		get_first_nl_index(char		*str)
{
	int		counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == '\n')
			return (counter);
		counter++;
	}
	return (-1);
}

/*
	@brief		Returns current line and updates leftovers if there is a new line, or returns NULL
*/
static char	*get_line(char	*leftovers)
{
	int			counter;
	char		*current_line;
	char		*updated_leftovers;

	counter = 0;
	if (get_first_nl_index(leftovers) > -1)
	{
		current_line = gnl_substr(leftovers, 0, counter);
		leftovers = gnl_substr(leftovers, counter, ft_strlen(leftovers));
		return (current_line);
	}
	return (NULL);
	return (gnl_substr(leftovers, 0, ft_strlen(leftovers)));
}

/*
	@brief (leftovers)		Keeps the content of str after the new line between function calls
*/
char	*get_next_line(int	fd)
{
	static char		*leftovers;
	char			*buffer;
	char			*temp_line;

	if (!leftovers)
		leftovers = malloc(sizeof(char) * BUFFER_SIZE);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!leftovers || !buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	temp_line = get_line(leftovers);
	if (temp_line != NULL)
		return (temp_line);
	read(fd, buffer, BUFFER_SIZE);
	if (buffer == -1)
		return (NULL);
	leftovers = ft_strjoin(leftovers, buffer);
	if (get_first_nl_index(leftovers) == -1 && buffer == 0)
		return (free(buffer), leftovers);
	free(buffer);
	return (get_next_line(fd));
}

/*
	- on the first iteration when leftovers is null, weird shit will happen with strjoin. instead, change strjoin to return the other string if either string is null
	- handle memory leaks all over but i can do that later
		- leftovers when its reassigned to strjoin
		- temp_line
*/