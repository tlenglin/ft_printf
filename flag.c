/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:53:01 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/15 15:54:27 by tlenglin         ###   ########.fr       */
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
	if (print->hashtag > 1 || print->plus > 1 || print->minus > 1 || print->space > 1 || print->zero > 1)
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
	if (print->hashtag == 1)
		return (NULL);
	if (!(tmp = (unsigned char*)ft_strdup((char*)str)))
		return (NULL);
	if (print->precision > (int)(length - (unsigned int)sign))
	{
		if (sign == 1)
		{
			if (!(tmp = (unsigned char*)ft_strsub((char*)tmp, 1, length)))
				return (NULL);
			if (!(tmp = ft_add_zeros_precision(print, tmp)))
				return (NULL);
			if (!(tmp = ft_printf_join((unsigned char*)"-", tmp, 2)))
				return (NULL);
		}
		else
		{
			if (!(tmp = ft_add_zeros(print, tmp)))
				return (NULL);
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
	if (print->hashtag == 1 && (c == 'o' || c == 'O'))
	{
		tmp = ft_set_flag_hashtag(c, tmp);
	}
	if (print->precision > (int)length)
	{
		tmp = ft_add_zeros_precision(print, tmp);
	}
	if (print->hashtag == 1 && (c == 'x' || c == 'X'))
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
	if (print->plus == 1 || print->space == 1 || print->hashtag == 1 || print->zero == 1 || print->precision != 0)
		return (NULL);
	tmp = (unsigned char*)ft_strdup((char*)str);
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
				tmp = ft_printf_join((unsigned char*)"+", tmp, 2);
		}
		return (tmp);
	}
	if (print->space == 1)
	{
		if (c == 'D' || c == 'i' || c == 'd')
		{
			if (tmp[0] != '-')
				tmp = ft_printf_join((unsigned char*)" ", tmp, 2);
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
		tmp = ft_printf_join((unsigned char*)"0", str, 2);
	}
	else if (c == 'x')
	{
		tmp = ft_printf_join((unsigned char*)"0x", str, 2);
	}
	else if (c == 'X')
	{
		tmp = ft_printf_join((unsigned char*)"0X", str, 2);
	}
	else
		return (str);
	return (tmp);
}
