/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:24:54 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/24 07:42:37 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	@return		Index of first occurrence of x in str or -1
*/
int	get_first_char(char *str, char x)
{
	int		counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == x)
			return (counter);
		counter++;
	}
	return (-1);
}

/*
	@brief		Updates leftovers (lo) to start after \\n
	@return		Found line or NULL
*/
static char	*get_line(char	**lo)
{
	char		*current_line;
	char		*new_lo;
	int			nl;

	nl = get_first_char(*lo, '\n');
	if (nl > -1)
	{
		current_line = gnl_substr(*lo, 0, nl);
		new_lo = gnl_substr(*lo, nl + 1, ft_strlen(*lo) - nl - 1);
		if (!current_line || !new_lo)
			return (free(current_line), free(new_lo), NULL);
		free(*lo);
		*lo = new_lo;
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

	if (read(fd, "a", 0) < 0)
		return (NULL);
	if (!leftovers)
		leftovers = malloc(sizeof(char) * BUFFER_SIZE);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!leftovers || !buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	temp = get_line(&leftovers);
	if (temp != NULL)
		return (temp);
	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (read_ret == -1)
		return (free(buffer), NULL);
	temp = leftovers;
	leftovers = ft_strjoin(leftovers, buffer);
	free (temp);
	free (buffer);
	if (!leftovers)
		return (NULL);
	if (get_first_char(leftovers, '\n') == -1 && read_ret == 0)
		return (leftovers);
	return (get_next_line(fd));
}
