/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelili <ikhelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:58:22 by ikhelili          #+#    #+#             */
/*   Updated: 2024/10/31 19:39:21 by ikhelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		list;
	int			i;
	int			number_char_printed;

	va_start(list, format);
	number_char_printed = 0;
	i = 0;
	if (!format)
	{
		return (0);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			number_char_printed += check_conversions(list, format[i + 1]);
			i++;
		}
		else
			number_char_printed += ft_print_char(format[i]);
		i++;
	}
	va_end(list);
	return (number_char_printed);
}

int	check_conversions(va_list list, const char str)
{
	int	printed_char;

	printed_char = 0;
	if (str == 'c')
		printed_char += ft_print_char(va_arg(list, int));
	else if (str == 's')
		printed_char += ft_print_string(va_arg(list, char *));
	else if (str == 'p')
		printed_char += ft_putptr(va_arg(list, uintptr_t));
	else if (str == 'd' || str == 'i')
		printed_char += ft_put_nbr(va_arg(list, int));
	else if (str == 'u')
		printed_char += ft_printf_unsigned(va_arg(list, unsigned int));
	else if (str == 'x' || str == 'X')
		printed_char += ft_print_hex(va_arg(list, unsigned int), str);
	else if (str == '%')
		printed_char += ft_print_percent_sign();
	return (printed_char);
}
