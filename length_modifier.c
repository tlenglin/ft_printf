/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:37:18 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/17 06:53:11 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing_length_modifier(unsigned char *copy, t_print *print, unsigned int current_cursor)
{
	int count;

	count = 0;
	if (copy[current_cursor] == 'h' && copy[current_cursor + 1] == 'h')
	{
		print->hh = 1;
		current_cursor++;
		current_cursor++;
		count++;
	}
	if (copy[current_cursor] == 'l' && copy[current_cursor + 1] == 'l')
	{
		print->ll = 1;
		current_cursor++;
		current_cursor++;
		count++;
	}
	if (copy[current_cursor] == 'h')
	{
		print->h = 1;
		current_cursor++;
		count++;
	}
	if (copy[current_cursor] == 'l')
	{
		print->l = 1;
		current_cursor++;
		count++;
	}
	if (copy[current_cursor] == 'z')
	{
		print->z = 1;
		current_cursor++;
		count++;
	}
	if (copy[current_cursor] == 'j')
	{
		print->j = 1;
		current_cursor++;
		count++;
	}
	if (count > 1)
		return (-1);
	return (current_cursor);
}

long	ft_set_length_modifier_di(t_print *print, va_list ap, char c)
{
	long	nb;
	short int vshort;
	char	vchar;

	vshort = 0;
	vchar = 0;
	nb = 0;
	if (print->l == 1 || print->ll == 1 || print->j == 1 || print->z == 1 || c == 'D' || c == 'O')
	{
		nb = va_arg(ap, intmax_t);
	}
	else if (print->h == 1)
	{
		vshort = (short int)va_arg(ap, int);
		nb = (long)vshort;
	}
	else if (print->hh == 1)
	{
		vchar = (char)va_arg(ap, int);
		nb = (long)vchar;
	}
	return (nb);
}

unsigned long	ft_set_length_modifier_uox(t_print *print, va_list ap, char c)
{
	unsigned long	nb;
	unsigned short int	vshort;
	unsigned char	vchar;

	vshort = 0;
	vchar = 0;
	nb = 0;
	if (print->l == 1 || print->ll == 1 || print->j == 1 || print->z == 1 || c == 'U' || c == 'O')
	{
		nb = va_arg(ap, unsigned long);
	}
	else if (print->h == 1)
	{
		vshort = (unsigned short int)va_arg(ap, unsigned int);
		nb = (unsigned long)vshort;
	}
	else if (print->hh == 1)
	{
		vchar = (unsigned char)va_arg(ap, unsigned int);
		nb = (unsigned long)vchar;
	}
	return (nb);
}
