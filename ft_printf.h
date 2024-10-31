/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhelili <ikhelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:57:02 by ikhelili          #+#    #+#             */
/*   Updated: 2024/10/31 18:37:36 by ikhelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int			ft_printf(const char *format, ...);
int			check_conversions(va_list list, const char str);
int			ft_print_char(int c);
int			ft_print_string(char *s);
int			ft_putptr(uintptr_t ptr);
int			ft_print_percent_sign(void);
int			ft_put_nbr(int n);
int			ft_printf_unsigned(unsigned int nb);
int			ft_print_hex(unsigned int nb, const char format);

char		*ft_itoa(int n);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);

#endif
