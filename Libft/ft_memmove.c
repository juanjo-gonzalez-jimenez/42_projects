/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:49:59 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/21 19:30:32 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destptr;
	const unsigned char	*srcptr;

	destptr = (unsigned char *)dest;
	srcptr = (const unsigned char *)src;
	if (dest < src)
	{
		while (0 < n)
		{
			*destptr = *srcptr;
			srcptr++;
			destptr++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			destptr[n] = srcptr[n];
		}
	}
	return (dest);
}
