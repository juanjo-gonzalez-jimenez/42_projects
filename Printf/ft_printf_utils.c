/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:35:58 by vboxuser          #+#    #+#             */
/*   Updated: 2026/10/07 16:51:58 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char const *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nmbr(int nmbr)
{
	long	number;
	char	c;
	int		counter;

	counter = 0;
	number = nmbr;
	if (number < 0)
	{
		counter++;
		write(1, "-", 1);
		number = number * -1;
	}
	if (number >= 10)
		counter += ft_print_nmbr(number / 10);
	c = number % 10 + '0';
	counter++;
	write(1, &c, 1);
	return (counter);
}

int	ft_print_base(unsigned long nmbr, char const *digits)
{
	unsigned long	base;
	int				counter;

	counter = 0;
	base = 0;
	while (digits[base] != '\0')
		base++;
	if (nmbr >= base)
		counter += ft_print_base(nmbr / base, digits);
	counter++;
	write(1, &digits[nmbr % base], 1);
	return (counter);
}

int	ft_print_p(void *ptr)
{
	unsigned long	number;
	int				counter;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	number = (unsigned long)ptr;
	write(1, "0x", 2);
	counter = 2;
	counter += ft_print_base(number, "0123456789abcdef");
	return (counter);
}
