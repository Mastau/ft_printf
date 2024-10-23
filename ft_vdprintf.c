/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:53:10 by thomarna          #+#    #+#             */
/*   Updated: 2024/10/22 19:23:46 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	const char	*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

static int	ft_convert(int fd, const char c, va_list ap)
{
	int	res;

	res = 0;
	if (c == 'c')
		ft_putchar_fd((char)va_arg(ap, int), fd, &res);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), fd, &res);
	else if (c == 'p')
		ft_putpointer_fd((unsigned long int)va_arg(ap, void *), fd, &res);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ap, int), fd, &res);
	else if (c == 'u')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789", fd, &res);
	else if (c == 'x')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789abcdef", fd,
			&res);
	else if (c == 'X')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", fd,
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
