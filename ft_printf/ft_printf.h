/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:16:44 by muganiev          #+#    #+#             */
/*   Updated: 2022/10/17 16:17:15 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_conversions(va_list ar, char ch);
int	ft_putchar(char ch);
int	ft_putstr(char *str);
int	ft_putuint(unsigned int n);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int n, char ch);
int	ft_putpointer(unsigned long n);
int	ft_lenpointer(unsigned long n);

#endif