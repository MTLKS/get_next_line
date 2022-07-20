/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:13:14 by maliew            #+#    #+#             */
/*   Updated: 2022/07/21 04:33:28 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_read(char **buffer, int fd)
{
	char	*new_buffer;
	char	*temp;
	int		read_output;

	new_buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!new_buffer)
		return (-1);
	gnl_bzero(new_buffer, BUFFER_SIZE + 1);
	if (!*buffer)
		*buffer = gnl_strjoin("", "");
	read_output = 1;
	while (!gnl_strchr(*buffer, '\n') && read_output > 0)
	{
		read_output = read(fd, new_buffer, BUFFER_SIZE);
		if (read_output == -1)
			break ;
		temp = gnl_strjoin(*buffer, new_buffer);
		free(*buffer);
		*buffer = temp;
		gnl_bzero(new_buffer, BUFFER_SIZE);
	}
	free(new_buffer);
	return (read_output);
}

char	*gnl_get_lines(char **buffer)
{
	char	*res;
	char	*temp;
	int		index;

	if (gnl_strchr(*buffer, '\n'))
		index = (int)(gnl_strchr(*buffer, '\n') - *buffer);
	else
		index = gnl_strlen(*buffer);
	res = gnl_substr(*buffer, 0, index + 1);
	temp = gnl_substr(*buffer, index + 1, gnl_strlen(*buffer));
	free(*buffer);
	*buffer = temp;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			read_output;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	read_output = gnl_read(&buffer, fd);
	if (read_output == -1 || (!*buffer && !read_output))
	{
		free(buffer);
		return (NULL);
	}
	return (gnl_get_lines(&buffer));
}
