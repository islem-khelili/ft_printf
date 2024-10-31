/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelili <ikhelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:53:46 by ikhelili          #+#    #+#             */
/*   Updated: 2024/10/31 19:22:25 by ikhelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_ptr(uintptr_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

static void	ft_put_ptr(uintptr_t nb)
{
	if (nb >= 16)
		ft_put_ptr(nb / 16);
	if (nb % 16 <= 9)
		ft_print_char(nb % 16 + '0');
	else
		ft_print_char(nb % 16 - 10 + 'a');
}

int	ft_putptr(uintptr_t ptr)
{
	int	char_printed;

	char_printed = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		char_printed += write(1, "0x", 2);
		ft_put_ptr(ptr);
		char_printed += len_ptr(ptr);
	}
	return (char_printed);
}
