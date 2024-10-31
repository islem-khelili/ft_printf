/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelili <ikhelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:53:56 by ikhelili          #+#    #+#             */
/*   Updated: 2024/10/30 23:12:35 by ikhelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_u_len(unsigned int nb)
{
	int	len;

	len = 0 ;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int nb)
{
	int		len;
	char	*str_u;

	len = ft_u_len(nb);
	str_u = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_u)
		return (NULL);
	str_u[len] = '\0';
	while (nb != 0)
	{
		str_u[len - 1] = nb % 10 + 48 ;
		nb = nb / 10;
		len--;
	}
	return (str_u);
}

int	ft_printf_unsigned(unsigned int nb)
{
	int		char_printed;
	char	*str;

	char_printed = 0 ;
	if (nb == 0)
		char_printed += write(1, "0", 1);
	else
	{
		str = ft_uitoa(nb);
		char_printed += ft_print_string(str);
		free(str);
	}
	return (char_printed);
}
