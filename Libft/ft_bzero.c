/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:51:23 by juan-jos          #+#    #+#             */
/*   Updated: 2026/09/21 16:01:13 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (0 < n)
	{
		*ptr = 0;
		n--;
		ptr++;
	}
}

/*#include <stdio.h>

int main()
{
	unsigned char	a[] = "holas mun";

	printf("%s\n", a);

	ft_bzero(a, 6);

	printf("%s\n", a);

	return (0);
}*/
