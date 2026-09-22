/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:56:12 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/22 17:08:30 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	const char	*ptr;

	len = ft_strlen(s);
	ptr = len + s;
	while (ptr >= s)
	{
		if (*ptr == (char)c)
		{
			return ((char *)ptr);
		}
		ptr--;
	}
	return (NULL);
}
/*#include <stdio.h>

int	main(void)
{
	const char *s = "hola mundo";
	char *result;

	result = ft_strrchr(s, 'o');
	printf("%s", result);
}*/