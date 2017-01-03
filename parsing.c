/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 21:29:50 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/03 23:07:49 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing(char *str, va_list ap, t_flag *flag)
{
	if (str == '%')
	{
		str++;
		while (str == '#' || str == '0' || str == '+' || str == '-' || str == ' ')
		{
			if (set_flag(str, flag) == 0)
				return (0);
			str++;
		}
		if (ft_parsing_conversion(str, ap) == 0)
			return (0);
	}
	else
	{
		ft_putchar(str);
	}
	return (1);
}

int	ft_parsing_conversion(char *str, va_list ap)
{
	if (str == 's' || str == 'S')
	{
		ft_sS_conversion(str, ap);
	}
	if (str == 'p')
	{
		ft_p_conversion(str, ap);
	}
	if (str == 'i' || str == 'd' || str == 'D' || str == 'o' || str == 'O' ||
	str == 'u' || str == 'U' || str == 'x' || str == 'X')
	{
		ft_number_conversion(str, ap);
	}
	if (str == 'c' || str == 'C')
	{
		ft_cC_conversion(str, ap);
	}
}

int	set_flag(char *str, t_flag *flag)
{
	if (flag->hashtag == 0 && str == '#')
	{
		flag->hashtag = 1;
	}
	else if (flag->zero == 0 && str == '0')
	{
		flag->zero = 1;
	}
	else if (flag->plus == 0 && str == '+')
	{
		flag->plus = 1;
	}
	else if (flag->minus == 0 && str == '-')
	{
		flag->minus = 1;
	}
	else if (flag->space == 0 && str == ' ')
	{
		flag->space = 1;
	}
	else if (flag->h == 0 && str == 'h')
	{
		if (str[1] == 'h')
		{
			flag->h = 2;
			str++;
		}
		else
			flag->h = 1;
	}
	else if (flag->l == 0 && str == 'l')
	{
		if (str[1] == 'l')
		{
			flag->l = 2;
			str++;
		}
		else
			flag->l = 1;
	}
	else if (flag->j == 0 && str == 'j')
	{
		flag->j = 1;
	}
	else if (flag->z == 0 && str == 'z')
	{
		flag->z = 1;
	}
	else
		return (0);
	return (1);
}
