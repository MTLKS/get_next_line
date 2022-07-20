/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 02:22:13 by maliew            #+#    #+#             */
/*   Updated: 2022/07/21 05:11:24 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

void	gnl_bzero(void *s, int n);
int		gnl_strlen(char *s);
char	*gnl_strchr(char *s, char c);
char	*gnl_strdup(char *s1);
char	*gnl_strjoin(char *s1, char *s2);

#endif