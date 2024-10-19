/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:13:37 by thomarna          #+#    #+#             */
/*   Updated: 2024/10/19 15:17:35 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *str)
{
	const char	*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	if (!c || !fd || !count)
		return ;
	write(fd, &c, 1);
	*count += 1;
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (!s || !fd || !count)
		return ;
	write(fd, s, ft_strlen(s));
	*count += ft_strlen(s);
}

void	ft_putnbr_fd(int nb, int fd, int *count)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd, count);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd, count);
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd, count);
		return ;
	}
	ft_putnbr_fd(nb / 10, fd, count);
	ft_putnbr_fd(nb % 10, fd, count);
}

void	ft_putnbr_base_fd(unsigned long int nb, char *base, int fd, int *count)
{
	unsigned long int	base_size;

	if (!nb || !base || !fd || !count)
		return ;
	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbr_base_fd(nb / base_size, base, fd, count);
		ft_putnbr_base_fd(nb % base_size, base, fd, count);
	}
	else
		ft_putchar_fd(base[nb], fd, count);
}
