/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:36:42 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/14 16:54:42 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	while (j < i)
	{
		ptr[j] = stash[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*new_stash(char *stash)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i] == '\0')
		return (free_null(stash));
	ptr = malloc(sizeof(char) * ((stash_len(stash) - i) + 1));
	if (!ptr)
		return (free_null(stash));
	while (stash[i] != '\0')
		ptr[j++] = stash[i++];
	ptr[j] = '\0';
	free(stash);
	return (ptr);
}

char	*reader(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;

	bytes = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free_null(stash));
	while (stash_checker(stash) != 1 && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (free_null(stash));
		}
		if (bytes > 0)
		{
			buf[bytes] = '\0';
			stash = stash_join(stash, buf);
			if (stash == NULL)
				return (free_null(buf));
		}
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = reader(fd, stash);
	if (stash == NULL || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	if (line == NULL)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = new_stash(stash);
	return (line);
}
