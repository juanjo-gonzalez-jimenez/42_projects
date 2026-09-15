/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:49:53 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/10 12:27:26 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*ptr;

	i = 0;
	while (src[i] != '\0')
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*#include <stdio.h>

int main()
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
