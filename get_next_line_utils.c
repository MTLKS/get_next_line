/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 04:23:26 by maliew            #+#    #+#             */
/*   Updated: 2022/07/21 03:51:24 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_bzero(void *s, int n)
{
	while (n-- > 0)
		*((char *) s++) = '\0';
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *s, char c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return (s);
	return (0);
}

char	*gnl_substr(char *s, int start, int len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (gnl_strlen(s) < start)
		return (gnl_strjoin("", ""));
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

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}
