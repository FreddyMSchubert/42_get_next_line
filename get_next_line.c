/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:24:54 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/23 15:45:15 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_first_nl(char *str)
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
	@brief		Updates leftovers if there is new line, returns curr line or NULL
*/
static char	*get_line(char	*leftovers)
{
	char		*current_line;
	char		*new_leftovers;
	int			first_nl;

	first_nl = get_first_nl(leftovers);
	if (first_nl > -1)
	{
		current_line = gnl_substr(leftovers, 0, first_nl);
		new_leftovers = gnl_substr(leftovers, first_nl, ft_strlen(leftovers));
		free(leftovers);
		leftovers = new_leftovers;
		return (current_line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*leftovers;
	char			*buffer;
	char			*temp;
	int				read_ret;

	if (!leftovers)
		leftovers = malloc(sizeof(char) * BUFFER_SIZE);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!leftovers || !buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	temp = get_line(leftovers);
	if (temp != NULL)
		return (temp);
	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (read_ret == -1)
		return (free(buffer), NULL);
	temp = leftovers;
	leftovers = ft_strjoin(leftovers, buffer);
	free (temp);
	if (get_first_nl(leftovers) == -1 && read_ret == 0)
		return (free(buffer), leftovers);
	free(buffer);
	return (get_next_line(fd));
}
