/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 07:18:01 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/25 11:04:35 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
	@brief		Finds the first new line in the string
	@return		The index or -1 if there's no new line
*/
int	get_first_nl_index(char *str)
{
	int	counter;

	counter = -1;
	if (!str)
		return (-1);
	while (str[++counter] != '\0')
		if (str[counter] == '\n')
			return (counter);
	return (-1);
}

/*
	@brief		Reads one chunk from filedes & appends it to left. 
	@brief		The return value of read gets written into read_ret.
*/
int	get_next_chunk(char **left, int filedes, int *read_ret)
{
	char			*temp;
	char			*buffer;
	int				counter;

	counter = BUFFER_SIZE;
	buffer = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buffer)
		return (0);
	buffer[BUFFER_SIZE] = '\0';
	*read_ret = read(filedes, buffer, BUFFER_SIZE);
	if (*read_ret < 0)
		return (free(buffer), 0);
	temp = *left;
	*left = ft_strjoin(temp, buffer);
	free (buffer);
	return (1);
}

/*
	@brief		Returns a full line & removes it from left

	problem (?) this function always assumes there is something after the split.
	actually no substr will return 
*/
char	*split_off_line(char **left, int split_i)
{
	char	*temp_left;
	char	*temp_return;

	temp_return = gnl_substr(*left, 0, split_i);
	temp_left = gnl_substr(*left, split_i, ft_strlen(*left) - split_i);
	free(*left);
	*left = temp_left;
	return (temp_return);
}

/*
	@brief	left:	chars read but not returned in last function call;
	@brief	read_ret:	return value of read call
*/
char	*get_next_line(int filedes)
{
	static char		*left;
	int				read_ret;

	if (read(filedes, "a", 1) < 0)
		return (NULL);
	read_ret = 1;
	while (get_first_nl_index(left) == -1 && read_ret != 0)
		get_next_chunk(&left, filedes, &read_ret);
	if (ft_strlen(left) > 0)
	{
		if (get_first_nl_index(left) == -1)
			return (split_off_line(&left, ft_strlen(left)));
		else
			return (split_off_line(&left, get_first_nl_index(left) + 1));
	}
	if (ft_strlen(left) <= 0 && read_ret == 0)
		return (free(left), NULL);
	return (NULL);
}
