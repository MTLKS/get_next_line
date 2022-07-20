/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:14:16 by maliew            #+#    #+#             */
/*   Updated: 2022/07/21 05:15:22 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_substr(char *s, int start, int len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (gnl_strlen(s) < start)
		return (gnl_strdup(""));
	if (gnl_strlen(s + start) < len)
		len = gnl_strlen(s + start);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	len++;
	i = 0;
	s += start;
	while (len-- > 1 && *s)
		res[i++] = *s++;
	res[i] = '\0';
	return (res);
}

static int	gnl_read(char **buffer, int fd)
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

static char	*gnl_pop_buffer(char **buffer)
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
	static char	*buffer[1024];
	int			read_output;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	read_output = gnl_read(&buffer[fd], fd);
	if (read_output == -1 || (!*buffer[fd] && !read_output))
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	return (gnl_pop_buffer(&buffer[fd]));
}
