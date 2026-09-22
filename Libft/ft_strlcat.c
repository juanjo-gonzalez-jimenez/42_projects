/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:41:13 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/22 15:46:28 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	src_len = 0;
	while (dst[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	i = 0;
	while (src[i] != '\0' && size > (dest_len + i + 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*int	main(void)
{
	char src[] = "Malaga";
	char dest[5] = "Hola ";
	size_t result;

	result = ft_strlcat (dest, src, 11);
	printf ("%s\n", dest);
	//printf ("%u\n", result);

}*/
