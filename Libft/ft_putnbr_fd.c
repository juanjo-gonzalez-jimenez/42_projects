/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:23:52 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/01 11:51:34 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;
	char	c;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = number * -1;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	c = number % 10 + '0';
	write(fd, &c, 1);
}
