/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:54:08 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 14:54:38 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_set_flag_signed_number2(int sign, t_print *print,
	unsigned char **tmp, int length)
{
	int i;

	i = 0;
	while ((*tmp)[i] == ' ' && (*tmp)[i])
		i++;
	if ((*tmp)[i] == '0' && ft_atoi((char*)(*tmp)) != 0 &&
	print->precision <= (int)length)
		(*tmp)[i] = (sign == 1) ? '-' : '+';
	else if (i == 0 || ft_atoi((char*)(*tmp)) == 0)
	{
		if (sign == 1)
			(*tmp) = ft_printf_join((unsigned char*)"-", (*tmp));
		else if (ft_atoi((char*)(*tmp)) == 0 && print->width > 0)
			(*tmp)[i] = '+';
		else
			(*tmp) = ft_printf_join((unsigned char*)"+", (*tmp));
		i = 1;
		while ((*tmp)[i] <= '9' && (*tmp)[i] >= '0' && (*tmp)[i])
			i++;
		if ((*tmp)[i] == ' ')
			(*tmp) = (unsigned char*)ft_strsub((char*)(*tmp), 0,
			ft_strlen((char*)(*tmp)) - 1);
	}
	else
		(*tmp)[i - 1] = (sign == 1) ? '-' : '+';
}

unsigned char	*ft_set_flag_unsigned_number(char c, unsigned char *str,
	t_print *print)
{
	unsigned char	*tmp;
	unsigned int	length;

	length = ft_strlen((char*)str);
	tmp = (unsigned char*)ft_strdup((char*)str);
	if (print->hashtag == 1 && (c == 'o' || c == 'O'))
		tmp = ft_set_flag_hashtag(c, tmp);
	if (print->precision > (int)length)
		tmp = ft_add_zeros_precision(print, tmp);
	if (print->hashtag == 1 && (c == 'x' || c == 'X'))
		tmp = ft_set_flag_hashtag(c, tmp);
	if (print->minus == 1 && print->width > (int)ft_strlen((char*)tmp))
		tmp = ft_add_space(print, tmp);
	else if (print->width > (int)ft_strlen((char*)tmp) && print->zero > 0 &&
	print->precision == 0)
		tmp = ft_add_zeros(print, tmp, c);
	else if (print->width > (int)ft_strlen((char*)tmp))
		tmp = ft_add_space(print, tmp);
	return (tmp);
}

unsigned char	*ft_set_flag_char(unsigned char *str, t_print *print)
{
	unsigned char	*str2;
	int				i;

	i = 0;
	if (print->width > 1)
	{
		str2 = (unsigned char*)ft_strnew(print->width);
		while (i < (print->width))
		{
			str2[i] = (print->zero == 1) ? '0' : ' ';
			i++;
		}
		if (print->minus == 1)
		{
			str2[0] = str[0];
		}
		else
		{
			str2[i - 1] = str[0];
		}
	}
	else
		str2 = (unsigned char*)ft_strdup((char*)str);
	return (str2);
}

unsigned char	*ft_set_flag_string(unsigned char *str, t_print *print)
{
	unsigned char	*tmp;
	unsigned int	length;

	length = ft_strlen((char*)str);
	tmp = (unsigned char*)ft_strdup((char*)str);
	if (print->precision < (int)length && print->precision != 0)
	{
		if (print->precision == -1)
			print->precision = 0;
		tmp = (unsigned char*)ft_strsub((char*)tmp, 0, print->precision);
		if (print->precision != 0)
			tmp = ft_cut_wide_character(tmp);
	}
	if (print->width > (int)ft_strlen((char*)tmp))
	{
		if (print->zero == 1)
		{
			tmp = ft_add_zeros(print, tmp, 's');
		}
		else
		{
			tmp = ft_add_space(print, tmp);
		}
	}
	return (tmp);
}
