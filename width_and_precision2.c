/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:57 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 15:27:21 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_parsing_width(unsigned char *copy, t_print *print,
	unsigned int current_cursor)
{
	while (copy[current_cursor] >= '0' && copy[current_cursor] <= '9')
	{
		print->width = print->width * 10 + copy[current_cursor] - '0';
		current_cursor++;
	}
	return (current_cursor);
}

int				ft_parsing_precision(unsigned char *copy, t_print *print,
	unsigned int current_cursor)
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
			print->precision = print->precision * 10 +
			copy[current_cursor] - '0';
			current_cursor++;
		}
		if (print->precision == 0)
			print->precision = -1;
	}
	return (current_cursor);
}

unsigned char	*ft_add_zeros_precision(t_print *print, unsigned char *tmp)
{
	int				nb;
	unsigned char	*str;
	unsigned char	*str2;
	int				i;

	i = 0;
	nb = print->precision - ft_strlen((char*)tmp);
	str = (unsigned char*)ft_strnew(nb);
	if (!(str2 = (unsigned char*)ft_strnew(nb + ft_strlen((char*)tmp) + 1)))
		return (NULL);
	while (i < nb)
	{
		str[i] = '0';
		i++;
	}
	str2 = ft_printf_join(str, tmp);
	return (str2);
}

unsigned char	*ft_global_parsing(unsigned char *copy, t_print *print,
	unsigned int cursor, va_list ap)
{
	int				current_cursor;
	unsigned char	*tmp;

	tmp = NULL;
	current_cursor = cursor + 1;
	ft_reset_flag(print);
	if ((current_cursor = ft_parsing_flag(copy, print, current_cursor)) == -1)
		return (NULL);
	if ((current_cursor = ft_parsing_width(copy, print, current_cursor)) == -1)
		return (NULL);
	if ((current_cursor = ft_parsing_precision(copy, print, current_cursor))
	== -1)
		return (NULL);
	if ((current_cursor = ft_parsing_length_modifier(copy, print,
		current_cursor)) == -1)
		return (NULL);
	if ((tmp = ft_set_conversion_specifier(copy, print, current_cursor, ap))
	== NULL)
		return (NULL);
	return (tmp);
}
