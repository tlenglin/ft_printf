/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:34:29 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/17 00:19:50 by tlenglin         ###   ########.fr       */
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
	{
		return (current_cursor);
	}
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
	// ft_putunbr(print->precision);
	// ft_putstr("length = ");
	// ft_putunbr(ft_strlen((char*)tmp));
	// ft_putchar('\n');
	str = (unsigned char*)ft_strnew(nb);
	if (!(str2 = (unsigned char*)ft_strnew(nb + ft_strlen((char*)tmp) + 1)))
		return (NULL);
	while (i < nb)
	{
		str[i] = '0';
		i++;
	}
	str2 = ft_printf_join(str, tmp, 3);
	return (str2);
}

unsigned char	*ft_add_zeros(t_print *print, unsigned char *tmp, char c)
{
	int nb;
	unsigned char *str;
	unsigned char *str2;
	int i;

	i = 0;
	// if (sign == 1)
	// 	tmp = (unsigned char*)ft_strsub((char*)tmp, 1, ft_strlen((char*)tmp));
	nb = print->width - ft_strlen((char*)tmp);
	// ft_putstr("width = ");
	// ft_putnbr(print->width);
	// ft_putstr("length = ");
	// ft_putnbr(ft_strlen((char*)tmp));
	// ft_putchar('\n');
	str = (unsigned char*)ft_strnew(nb);
	if (!(str2 = (unsigned char*)ft_strnew(nb + ft_strlen((char*)tmp) + 1)))
		return (NULL);
	while (i < nb)
	{
		str[i] = '0';
		i++;
	}
	if ((c == 'd' || c == 'D' || c == 'i') && print->minus == 1)
	{
		str2 = ft_add_space(print, tmp);
	}
	else if (print->minus == 1)
	{
		str2 = ft_printf_join(tmp, str, 3);
	}
	else if (tmp[1] == 'x' || tmp[1] == 'X')
	{
		str2 = ft_printf_join(str, (unsigned char*)ft_strsub((char*)tmp, 2, ft_strlen((char*)tmp)), 3);
		str2 = ft_set_flag_hashtag(c, str2);
	}
	else
	{
		str2 = ft_printf_join(str, tmp, 3);
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
	if (!(str2 = (unsigned char*)ft_strnew(nb + ft_strlen((char*)tmp) + 1)))
		return (NULL);
	if (print->minus == 1)
	{
		str2 = ft_printf_join(tmp, str, 3);
	}
	else
	{
		str2 = ft_printf_join(str, tmp, 3);
	}
	return (str2);
}
