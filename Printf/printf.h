/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:45:16 by juan-jos          #+#    #+#             */
/*   Updated: 2026/10/07 16:36:58 by juan-jos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*Function Prototypes*/
int	ft_print_char(char c);
int	ft_print_str(char const *str);
int	ft_print_nmbr(int nmbr);
int	ft_print_base(unsigned long nmbr, char const *digits);
int	ft_print_p(void *ptr);
int	ft_handle_format(char format, va_list *args);
int	ft_printf(char const *format, ...);

#endif