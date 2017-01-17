/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:29:24 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/17 08:40:24 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned char	*ft_global_parsing(unsigned char *copy, t_print *print, unsigned int cursor, va_list ap)
{
	int	current_cursor;
	unsigned char	*tmp;

	tmp = NULL;
	current_cursor = cursor + 1;
	// ft_reset_flag(print);
	ft_reset_flag(print);
	if ((current_cursor = ft_parsing_flag(copy, print, current_cursor)) == -1)
	{
		return (NULL);
	}
	if ((current_cursor = ft_parsing_width(copy, print, current_cursor)) == -1)
	{
		// ft_putstr("bbbb\n");
		return (NULL);
	}
	if ((current_cursor = ft_parsing_precision(copy, print, current_cursor)) == -1)
	{
		// ft_putstr("cccc\n");
		return (NULL);
	}
	if ((current_cursor = ft_parsing_length_modifier(copy, print, current_cursor)) == -1)
	{
		// ft_putstr("dddd\n");
		return (NULL);
	}

	// ft_putnbr(current_cursor);
	if ((tmp = ft_set_conversion_specifier(copy, print, current_cursor, ap)) == NULL)
	{
		// ft_putstr("eeee\n");
		return (NULL);
	}
	// ft_putstr("zzzz\n");
	return (tmp);
}

int	ft_printf(const char *str, ...)
{
	unsigned char	*result;
	unsigned char	*copy;
	va_list			ap;
	t_print			print;
	int	cursor;
	unsigned char	*tmp;

	result = NULL;
	cursor = 0;
	// ft_putstr("debut du programme\n");
	copy = (unsigned char*)ft_strdup((char*)str);
	if (!str || !copy)
		return (0);
	// if (!(print = ft_memalloc(sizeof(t_print))))
	// 	return (0);
	ft_bzero(&print, sizeof(t_print));
	va_start(ap, str);
	// ft_putstr("initialisation\n");
	// ft_putstr("copy = ");
	// ft_putstr((char*)copy);
	while ((cursor = ft_strchr_position(copy, '%')) != -1)
	{
		//ft_putstr("\npercent trouve");
		print.length = print.length + ft_strlen(ft_strsub((char*)copy, 0, cursor));
		result = ft_printf_join(result, (unsigned char*)ft_strsub((char*)copy, 0, cursor), 1);
		if (ft_set_cursor(cursor, copy) == -1)
			break ;
		tmp = ft_global_parsing(copy, &print, cursor, ap);
		// ft_putstr("\nnew tmp = ");
		// ft_putstr((char*)tmp);
		if (tmp[0] == 0 && tmp[1] != 0)
		{
			print.length = print.length + ft_strlen((char*)(tmp + 1));
		}
		else
			print.length = print.length + ft_strlen((char*)tmp);
		result = ft_printf_join(result, tmp, 3);
		// ft_putstr("\nold cursor = ");
		// ft_putnbr(cursor);
		cursor = ft_set_cursor(cursor, copy);
		// ft_putstr("\nnew cursor = ");
		// ft_putnbr(cursor);
		// ft_putchar('\n');
		copy = (unsigned char*)ft_strsub((char*)copy, cursor, (int)ft_strlen((char*)copy));
		// ft_putstr("\nnew result = ");
		// ft_putstr((char*)result);
		// ft_putstr("\nnew copy = ");
		// ft_putstr((char*)copy);
	}
	// ft_putstr("pas de percent trouve\n");
	print.length = print.length + ft_strlen((char*)copy);
	result = ft_printf_join(result, copy, 3);
	// ft_putstr((char*)result);
	// ft_putstr("\nlength = ");
	// ft_putunbr(print.length);
	write(1, result, print.length);
	//ft_putnbr(ft_strlen((char*)result));
	va_end(ap);
	return (print.length);
}
