/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:12:46 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/15 13:04:12 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argv, char **argc)
{
	int fd;
	int i;

	i = 1;
	fd = 0;
	if (argv >= 1)
	{
		while (argc[i] != NULL)
		{
			fd = open(argc[i], O_RDONLY);
			char *line;
			while ((line = get_next_line(fd)) != NULL)
			{
				printf("%s", line);
                //printf("\n");
				free(line);
			}
            close(fd);
            i++;
		}
	}
}