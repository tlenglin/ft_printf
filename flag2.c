/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:53:47 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 14:54:25 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_reset_flag(t_print *print)
{
	print->hashtag = 0;
	print->zero = 0;
	print->plus = 0;
	print->minus = 0;
	print->space = 0;
	print->width = 0;
	print->precision = 0;
	print->h = 0;
	print->hh = 0;
	print->l = 0;
	print->ll = 0;
	print->j = 0;
	print->z = 0;
	print->lc = 0;
	return (0);
}

int				ft_parsing_flag(unsigned char *copy, t_print *print,
	unsigned int current_cursor)
{
	while (ft_strchr_position((unsigned char*)"#+- 0",
	copy[current_cursor]) != -1)
	{
		if (copy[current_cursor] == '#')
			print->hashtag++;
		else if (copy[current_cursor] == '+')
			print->plus++;
		else if (copy[current_cursor] == '-')
			print->minus++;
		else if (copy[current_cursor] == ' ')
			print->space++;
		else if (copy[current_cursor] == '0')
			print->zero++;
		else
			return (-1);
		current_cursor++;
	}
	if (print->hashtag > 1 || print->minus > 1)
		return (-1);
	return (current_cursor);
}

unsigned char	*ft_set_flag_signed_number(char c,
	unsigned char *str, t_print *print)
{
	unsigned char	*tmp;
	unsigned int	length;
	int				sign;

	sign = 0;
	tmp = (unsigned char*)ft_strdup((char*)str);
	length = ft_strlen((char*)str);
	if (str[0] == '-')
	{
		sign = 1;
		length--;
		tmp = (unsigned char*)ft_strsub((char*)tmp, 1, length);
	}
	if (print->precision > (int)length)
		tmp = ft_add_zeros_precision(print, tmp);
	if (print->width > (int)ft_strlen((char*)tmp))
	{
		if (print->zero == 1)
			tmp = ft_add_zeros(print, tmp, c);
		else
			tmp = ft_add_space(print, tmp);
	}
	ft_set_flag_signed_number3(sign, print, &tmp, length);
	return (tmp);
}

void			ft_set_flag_signed_number3(int sign, t_print *print,
	unsigned char **tmp, int length)
{
	if (sign == 1 || print->plus > 0)
		ft_set_flag_signed_number2(sign, print, tmp, length);
	else if (print->space > 0)
	{
		if ((*tmp)[0] == '0')
			(*tmp)[0] = ' ';
		else if ((*tmp)[0] != ' ' && (*tmp)[0] != '0')
		{
			*tmp = ft_printf_join((unsigned char*)" ", *tmp);
		}
	}
}
