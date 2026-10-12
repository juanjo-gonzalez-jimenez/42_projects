/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:36:42 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/12 20:29:28 by juan-jos         ###   ########.fr       */
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
    i = i + 1;
    if (stash[i] == '\0')
    {
        free(stash);
        return (NULL);
    }
    
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;
	ssize_t		bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (stash_checker(stash) != 1 && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes > 0)
		{
			buf[bytes] = '\0';
			stash = stash_join(stash, buf);
			if (stash == NULL)
			{
				free(buf);
				return (NULL);
			}
		}
	}
	free(buf);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
}
