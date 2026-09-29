/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:02:08 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/29 16:44:19 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		count;
	int		num;
	int		digit;
	char	*ptr;

	count = ft_counter(n);
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (NULL);
	ptr[count] = '\0';
	num = n;
	while (count > 0)
	{
		digit = (num % 10);
		if (digit < 0)
			digit = -digit;
		ptr[count - 1] = digit + '0';
		num = num / 10;
		count--;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
