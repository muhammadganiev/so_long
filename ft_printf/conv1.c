/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:18:39 by muganiev          #+#    #+#             */
/*   Updated: 2022/10/17 16:18:47 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[len])
		len++;
	if (str)
		write(1, str, len);
	return (len);
}

int	ft_putuint(unsigned int n)
{
	int	len;

	len = 1;
	if (n >= 10)
		len += ft_putuint(n / 10);
	ft_putchar(n % 10 + '0');
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (len);
}