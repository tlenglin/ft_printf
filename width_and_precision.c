/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:34:29 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/15 12:07:21 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing_width(unsigned char *copy, t_print *print, unsigned int current_cursor)
{
	while (copy[current_cursor] >= '0' && copy[current_cursor] <= '9')
	{
		print->width = print->width * 10 + copy[current_cursor] - '0';
		current_cursor++;
	}
	return (current_cursor);
}

int	ft_parsing_precision(unsigned char *copy, t_print *print, unsigned int current_cursor)
{
	if (copy[current_cursor] != '.')
		return (current_cursor);
	current_cursor++;
	if (copy[current_cursor] < '0' || copy[current_cursor] > '9')
	{
		print->precision = -1;
		return (current_cursor);
	}
	if (copy[current_cursor] == '-')
	{
		print->precision = -1;
		return (current_cursor + 1);
	}
	if (copy[current_cursor] >= '0' && copy[current_cursor] <= '9')
	{
		while (copy[current_cursor] >= '0' && copy[current_cursor] <= '9')
		{
			print->precision = print->precision * 10 + copy[current_cursor] - '0';
			current_cursor++;
		}
		if (print->precision == 0)
			print->precision = -1;
	}
	return (current_cursor);
}

unsigned char	*ft_add_zeros_precision(t_print *print, unsigned char *tmp)
{
	int nb;
	unsigned char *str;
	unsigned char *str2;
	int i;

	i = 0;
	nb = print->precision - ft_strlen((char*)tmp);
	// ft_putstr("precision = ");
	// ft_putnbr(print->precision);
	// ft_putstr("length = ");
	// ft_putnbr(ft_strlen((char*)tmp));
	// ft_putchar('\n');
	str = (unsigned char*)ft_strnew(nb);
	while (i < nb)
	{
		str[i] = '0';
		i++;
	}
	str2 = ft_printf_join(str, tmp);
	return (str2);
}

unsigned char	*ft_add_zeros(t_print *print, unsigned char *tmp)
{
	int nb;
	unsigned char *str;
	unsigned char *str2;
	int i;

	i = 0;
	nb = print->width - ft_strlen((char*)tmp);
	// ft_putstr("width = ");
	// ft_putnbr(print->width);
	// ft_putstr("length = ");
	// ft_putnbr(ft_strlen((char*)tmp));
	// ft_putchar('\n');
	str = (unsigned char*)ft_strnew(nb);
	while (i < nb)
	{
		str[i] = '0';
		i++;
	}
	if (print->minus == 1)
	{
		str2 = ft_printf_join(tmp, str);
	}
	else
	{
		str2 = ft_printf_join(str, tmp);
	}
	return (str2);
}

unsigned char	*ft_add_space(t_print *print, unsigned char *tmp)
{
	int nb;
	unsigned char *str;
	unsigned char *str2;
	int i;

	i = 0;
	nb = print->width - ft_strlen((char*)tmp);
	str = (unsigned char*)ft_strnew(nb);
	while (i < nb)
	{
		str[i] = ' ';
		i++;
	}
	if (print->minus == 1)
	{
		str2 = ft_printf_join(tmp, str);
	}
	else
	{
		str2 = ft_printf_join(str, tmp);
	}
	return (str2);
}
