/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:53:01 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/13 19:46:18 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_reset_flag(void)
{
	t_print	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_print))))
		return (0);
	return (tmp);
}

int	ft_parsing_flag(unsigned char *copy, t_print *print, unsigned int current_cursor)
{
	while (ft_strchr_position((unsigned char*)"%cCsSidDoOuUxX.123456789hljz", copy[current_cursor]) == -1)
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
	if (print->hashtag > 1)
		return (-1);
	if (print->plus > 1)
		return (-1);
	if (print->minus > 1)
		return (-1);
	if (print->space > 1)
		return (-1);
	if (print->zero > 1)
		return (-1);
	return (current_cursor);
}

unsigned char	*ft_set_flag_signed_number(char c, unsigned char *str, t_print *print)
{
	unsigned char *tmp;
	unsigned int	length;
	int	sign;

	sign = 0;
	length = ft_strlen((char*)str);
	if (str[0] == '-')
		sign = 1;
	tmp = (unsigned char*)ft_strdup((char*)str);
	if (print->hashtag == 1)
		return (NULL);
	if (print->precision > (int)(length - (unsigned int)sign))
	{
		if (sign == 1)
		{
			tmp = (unsigned char*)ft_strsub((char*)tmp, 1, length);
			tmp = ft_add_zeros_precision(print, tmp);
			tmp = ft_printf_join((unsigned char*)"-", tmp);
		}
		else
		{
			tmp = ft_add_zeros(print, tmp);
		}
	}
	if (print->plus == 1 || print->space == 1)
	{
		tmp = ft_set_flag_plus_space(c, tmp, print);
	}
	if (print->width > (int)ft_strlen((char*)tmp) && print->zero == 1)
	{
		tmp = ft_add_zeros(print, tmp);
	}
	else if (print->width > (int)ft_strlen((char*)tmp))
	{
		tmp = ft_add_space(print, tmp);
	}
	return (tmp);
}

unsigned char	*ft_set_flag_unsigned_number(char c, unsigned char *str, t_print *print)
{
	unsigned char *tmp;
	unsigned int	length;

	length = ft_strlen((char*)str);
	if (print->plus == 1 || print->space == 1)
		return (NULL);
	tmp = (unsigned char*)ft_strdup((char*)str);
	if (print->precision > (int)length)
	{
		tmp = ft_add_zeros_precision(print, tmp);
	}
	if (print->hashtag == 1)
	{
		tmp = ft_set_flag_hashtag(c, tmp);
	}
	if (print->width > (int)ft_strlen((char*)tmp) && print->zero == 1 && print->precision == 0)
	{
		tmp = ft_add_zeros(print, tmp);
	}
	else if (print->width > (int)ft_strlen((char*)tmp))
	{
		tmp = ft_add_space(print, tmp);
	}
	return (tmp);
}

unsigned char	*ft_set_flag_char(unsigned char *str, t_print *print)
{
	unsigned char	*tmp;
	unsigned int	length;

	length = ft_strlen((char*)str);
	if (print->plus == 1 || print->space == 1 || print->hashtag == 1 || print->zero == 1)
		return (NULL);
	tmp = (unsigned char*)ft_strdup((char*)str);
	if (print->precision < (int)length)
	{
		tmp = (unsigned char*)ft_strsub((char*)str, 0, print->precision);
	}
	if (print->width > (int)ft_strlen((char*)tmp))
	{
		tmp = ft_add_space(print, tmp);
	}
	return (tmp);
}

unsigned char	*ft_set_flag(char c, unsigned char *str, t_print *print)
{
	unsigned char *tmp;

	tmp = (unsigned char*)ft_strdup((char*)str);
	if (c == 'd' || c == 'D' || c == 'i')
	{
		tmp = ft_set_flag_signed_number(c, tmp, print);
	}
	else if (c == 'c' || c == 'C' || c == 's' || c == 'S')
	{
		tmp = ft_set_flag_char(tmp, print);
	}
	else if (c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' || c == 'X')
	{
		tmp = ft_set_flag_unsigned_number(c, tmp, print);
	}
	return (tmp);
}

unsigned char	*ft_set_flag_plus_space(char c, unsigned char *str, t_print *print)
{
	unsigned char *tmp;

	tmp = (unsigned char*)ft_strdup((char*)str);
	if (print->plus == 1)
	{
		if (c == 'D' || c == 'i' || c == 'd')
		{
			if (tmp[0] != '-')
				tmp = (unsigned char*)ft_strjoin("+", (char*)tmp);
		}
		return (tmp);
	}
	if (print->space == 1)
	{
		if (c == 'D' || c == 'i' || c == 'd')
		{
			if (tmp[0] != '-')
				tmp = (unsigned char*)ft_strjoin(" ", (char*)tmp);
		}
	}
	return (tmp);
}

unsigned char	*ft_set_flag_hashtag(char c, unsigned char *str)
{
	unsigned char *tmp;

	tmp = NULL;
	if (c == 'o' || c == 'O')
	{
		tmp = (unsigned char*)ft_strjoin("0", (char*)str);
	}
	else if (c == 'x')
	{
		tmp = (unsigned char*)ft_strjoin("0x", (char*)str);
	}
	else if (c == 'X')
	{
		tmp = (unsigned char*)ft_strjoin("0X", (char*)str);
	}
	else
		return (str);
	return (tmp);
}
