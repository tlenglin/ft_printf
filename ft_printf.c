/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:29:24 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/13 16:30:22 by tlenglin         ###   ########.fr       */
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
	print = ft_reset_flag();
	if ((current_cursor = ft_parsing_flag(copy, print, current_cursor)) == -1)
	{
		// ft_putstr("aaaa\n");
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
	t_print			*print;
	int	cursor;
	unsigned char	*tmp;
	unsigned int	count;

	result = NULL;
	cursor = 0;
	count = 0;
	// ft_putstr("debut du programme\n");
	copy = (unsigned char*)ft_strdup((char*)str);
	if (!str)
		return (0);
	if (!(print = ft_memalloc(sizeof(t_print))))
		return (0);
	va_start(ap, str);
	// ft_putstr("initialisation\n");
	// ft_putstr("copy = ");
	// ft_putstr((char*)copy);
	while ((cursor = ft_strchr_position(copy, '%')) != -1)
	{
		// ft_putstr("\npercent trouve");
		result = ft_printf_join(result, (unsigned char*)ft_strsub((char*)copy, 0, cursor));
		if (ft_set_cursor(cursor, copy) == -1)
			break ;
		tmp = ft_global_parsing(copy, print, cursor, ap);
		// ft_putstr("\nnew tmp = ");
		// ft_putstr((char*)tmp);
		result = ft_printf_join(result, tmp);
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
	result = ft_printf_join(result, copy);
	ft_putstr((char*)result);
	//ft_putnbr(ft_strlen((char*)result));
	va_end(ap);
	return (ft_strlen((char*)result));
}
