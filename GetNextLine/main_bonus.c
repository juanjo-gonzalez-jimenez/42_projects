/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:49:18 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/15 10:53:15 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line_bonus.h"

#define MAX_FILES 10

int	main(int argc, char **argv)
{
	int		fds[MAX_FILES];
	int		open_count;
	int		active;
	int		i;
	char	*line;

	open_count = argc - 1;
	i = 0;
	while (i < open_count)
	{
		fds[i] = open(argv[i + 1], O_RDONLY);
		i++;
	}
	active = 1;
	while (active)
	{
		active = 0;
		i = 0;
		while (i < open_count)
		{
			if (fds[i] != -1)
			{
				line = get_next_line(fds[i]);
				if (line == NULL)
				{
					printf("[%s] -> NULL (EOF)\n", argv[i + 1]);
					close(fds[i]);
					fds[i] = -1;
				}
				else
				{
					active = 1;
					printf("[%s] -> %s", argv[i + 1], line);
					free(line);
				}
			}
			i++;
		}
	}
	return (0);
}