/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:13:37 by thomarna          #+#    #+#             */
/*   Updated: 2024/10/22 19:30:33 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, int *count)
{
	if (!fd || !count)
		return ;
	write(fd, &c, 1);
	*count += 1;
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (!fd || !count)
		return ;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		*count += 6;
	}
	else
	{
		write(fd, s, ft_strlen(s));
		*count += ft_strlen(s);
	}
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
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd, count);
		ft_putchar_fd(nb % 10 + '0', fd, count);
	}
}

void	ft_putnbr_base_fd(unsigned long int nb, char *base, int fd, int *count)
{
	unsigned long int	base_size;

	if (!base || !fd || !count)
		return ;
	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		ft_putnbr_base_fd(nb / base_size, base, fd, count);
		ft_putchar_fd(base[nb % base_size], fd, count);
	}
	else
		ft_putchar_fd(base[nb], fd, count);
}

void	ft_putpointer_fd(unsigned long int ptr, int fd, int *count)
{
	if (!ptr)
		ft_putstr_fd("(nil)", fd, count);
	else
	{
		ft_putstr_fd("0x", fd, count);
		ft_putnbr_base_fd(ptr, "0123456789abcdef", fd, count);
	}
}
