/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:49:53 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/22 15:36:18 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i] != '\0')
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "hola";
	char *dup;

	dup = ft_strdup(str);

	if (dup == NULL)
	{
		printf("memory allocation failed!\n");
		return (1);
	}

	printf("Original: %s\n", str);
	printf("Duplicate: %s\n", dup);

	free(dup);

	return (0);
}*/
