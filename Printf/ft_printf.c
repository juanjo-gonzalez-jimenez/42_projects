/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:35:46 by vboxuser          #+#    #+#             */
/*   Updated: 2026/10/07 16:26:19 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_handle_format(char format, va_list *args)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_print_char(va_arg(*args, int));
	if (format == '%')
		counter += ft_print_char('%');
	if (format == 's')
		counter += ft_print_str(va_arg(*args, char *));
	if (format == 'd' || format == 'i')
		counter += ft_print_nmbr(va_arg(*args, int));
	if (format == 'u')
		counter += ft_print_base(va_arg(*args, unsigned int), "0123456789");
	if (format == 'x')
		counter += ft_print_base(va_arg(*args, unsigned int),
				"0123456789abcdef");
	if (format == 'X')
		counter += ft_print_base(va_arg(*args, unsigned int),
				"0123456789ABCDEF");
	if (format == 'p')
		counter += ft_print_p(va_arg(*args, void *));
	return (counter);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			counter += ft_handle_format(format[i + 1], &args);
			i = i + 2;
		}
		else
			counter += ft_print_char(format[i++]);
	}
	va_end(args);
	return (counter);
}
