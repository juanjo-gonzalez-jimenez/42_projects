/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:45:48 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/23 14:26:25 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (s1[i] == s2[i]) && (s1[i] != '\0'))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include <stdio.h>
int	main(void)
{
	char string1[] = "hola";
	char string2[] = "hole munde";

	printf ("%d\n", ft_strncmp(string1, string2, 10));
	return (0);
}*/
