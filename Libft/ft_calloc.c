/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:22:44 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/23 17:04:34 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	void	*ptr; //pointer to the allocated memory
	size_t	total_size; //total size of the memory to be allocated

	total_size = nmemb * size; //total size of the memory to be allocated
	ptr = malloc(total_size); //memory assignated to the pointer
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size); //converting all the bits in the memory to 0
	return (ptr); //return pointer
}