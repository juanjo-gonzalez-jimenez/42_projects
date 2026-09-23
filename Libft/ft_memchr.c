/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:44:05 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/23 14:11:45 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		cc;

	ptr = (const unsigned char *)s;
	cc = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == cc)
		{
			return ((void *)ptr);
		}
		n--;
		ptr++;
	}
	return (NULL);
}
