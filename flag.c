/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:53:01 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 15:27:52 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

unsigned char	*ft_set_flag(char c, unsigned char *str, t_print *print)
{
	unsigned char *tmp;

	tmp = (unsigned char*)ft_strdup((char*)str);
	if (c == 'd' || c == 'D' || c == 'i')
	{
		tmp = ft_set_flag_signed_number(c, tmp, print);
	}
	else if (c == 'c' || c == 'C')
	{
		tmp = ft_set_flag_char(tmp, print);
	}
	else if (c == 's' || c == 'S')
	{
		tmp = ft_set_flag_string(tmp, print);
	}
	else if (c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' ||
	c == 'X')
	{
		tmp = ft_set_flag_unsigned_number(c, tmp, print);
	}
	return (tmp);
}

unsigned char	*ft_set_flag_plus_space(char c, unsigned char *str,
	t_print *print, int sign)
{
	unsigned char *tmp;

	tmp = (unsigned char*)ft_strdup((char*)str);
	if (print->plus > 0)
	{
		if (c == 'D' || c == 'i' || c == 'd')
		{
			if (sign == 1)
				tmp = ft_printf_join((unsigned char*)"-", tmp);
			else
				tmp = ft_printf_join((unsigned char*)"+", tmp);
		}
		return (tmp);
	}
	if (print->space > 0 && sign == 0)
	{
		if (c == 'D' || c == 'i' || c == 'd')
		{
			if (tmp[0] != '-')
				tmp = ft_printf_join((unsigned char*)" ", tmp);
		}
	}
	return (tmp);
}

unsigned char	*ft_set_flag_hashtag(char c, unsigned char *str)
{
	unsigned char *tmp;

	tmp = (unsigned char*)ft_strdup((char*)str);
	if (c == 'o' || c == 'O')
	{
		if (str[0] != '0')
			tmp = ft_printf_join((unsigned char*)"0", str);
	}
	else if (c == 'x')
	{
		tmp = ft_printf_join((unsigned char*)"0x", str);
	}
	else if (c == 'X')
	{
		tmp = ft_printf_join((unsigned char*)"0X", str);
	}
	else
		return (str);
	return (tmp);
}

int				ft_init_tab(unsigned char **tab)
{
	*tab = (unsigned char*)ft_strnew(16);
	(*tab)[0] = '0';
	(*tab)[1] = '1';
	(*tab)[2] = '2';
	(*tab)[3] = '3';
	(*tab)[4] = '4';
	(*tab)[5] = '5';
	(*tab)[6] = '6';
	(*tab)[7] = '7';
	(*tab)[8] = '8';
	(*tab)[9] = '9';
	(*tab)[10] = 'a';
	(*tab)[11] = 'b';
	(*tab)[12] = 'c';
	(*tab)[13] = 'd';
	(*tab)[14] = 'e';
	(*tab)[15] = 'f';
	return (0);
}
