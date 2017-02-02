/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:29:24 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 15:27:10 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				ft_printf(const char *str, ...)
{
	va_list			ap;
	t_print			print;

	if (!str)
		return (0);
	ft_bzero(&print, sizeof(t_print));
	va_start(ap, str);
	ft_printf2(str, ap, &print);
	va_end(ap);
	return (print.length);
}

int				ft_printf2(const char *str, va_list ap, t_print *print)
{
	unsigned char	*result;
	unsigned char	*copy;

	result = NULL;
	if (!(copy = (unsigned char*)ft_strdup((char*)str)))
		return (0);
	result = ft_printf4(&copy, print, ap);
	result = ft_printf_join_bis(result, copy, print->length,
		ft_strlen((char*)copy));
	print->length = print->length + ft_strlen((char*)copy);
	write(1, result, print->length);
	return (0);
}

unsigned char	*ft_printf4(unsigned char **copy, t_print *print, va_list ap)
{
	int				cursor;
	unsigned char	*result;
	unsigned char	*tmp;
	int				i;

	result = NULL;
	cursor = 0;
	i = 0;
	tmp = NULL;
	while ((cursor = ft_strchr_position(*copy, '%')) != -1)
	{
		result = ft_printf_join_bis(result,
			(unsigned char*)ft_strsub((char*)(*copy), 0, cursor), print->length,
			ft_strlen(ft_strsub((char*)(*copy), 0, cursor)));
		print->length = print->length + ft_strlen(ft_strsub((char*)(*copy),
		0, cursor));
		tmp = ft_global_parsing((*copy), print, cursor, ap);
		cursor++;
		i = ft_printf5(&cursor, print, (*copy), tmp);
		result = ft_printf_join_bis(result, tmp, print->length, i);
		print->length = print->length + i;
		(*copy) = (unsigned char*)ft_strsub((char*)(*copy), cursor + 1,
		(int)ft_strlen((char*)(*copy)));
	}
	return (result);
}

int				ft_printf5(int *cursor, t_print *print, unsigned char *copy,
	unsigned char *tmp)
{
	int i;

	i = 0;
	while (ft_strchr_position((unsigned char*)"0123456789.hljz#+- ",
	(copy)[(*cursor)]) != -1)
	{
		(*cursor)++;
	}
	if ((copy)[*cursor] == 'c' || (copy)[*cursor] == 'C')
	{
		i = ft_printf3(print, tmp);
	}
	else
		i = ft_strlen((char*)tmp);
	return (i);
}

int				ft_printf3(t_print *print, unsigned char *tmp)
{
	int i;

	i = 0;
	if (print->width > 0)
	{
		i = print->width;
	}
	else
	{
		if (tmp[0] == ' ')
		{
			while (tmp[i] == ' ')
				i++;
			i = (print->lc == 0) ? i + 1 : i + print->lc + 1;
		}
		else
		{
			i = (print->lc == 0) ? i + 1 : i + print->lc + 1;
			while (tmp[i] == ' ')
				i++;
		}
	}
	return (i);
}
