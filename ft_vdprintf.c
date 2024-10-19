/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:53:10 by thomarna          #+#    #+#             */
/*   Updated: 2024/10/19 15:17:33 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(int fd, const char c, va_list ap)
{
	int	res;

	res = 0;
	if (c == 'c')
		ft_putchar_fd((char)va_arg(ap, int), fd, &res);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), fd, &res);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ap, int), fd, &res);
	else if (c == 'u')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789", fd, &res);
	else if (c == 'x')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789abcdef", fd,
			&res);
	else if (c == 'X')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789abcdef", fd,
			&res);
	else if (c == '%')
		ft_putchar_fd('%', fd, &res);
	return (res);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int	res;

	res = 0;
	if (!(*format))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				res += ft_convert(fd, *format, ap);
			else
				return (-1);
		}
		else
			res += write(fd, format, 1);
		format++;
	}
	return (res);
}
#include <stdio.h>

int	main(void)
{
	int		i;
	char	str[50] = "Graou";

	i = 0;
	// char c = 'z';
	printf("%p\n", str);
	i = ft_printf("%s", str);
	printf("\n%d\n", i);
}
