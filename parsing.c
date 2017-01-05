/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 21:29:50 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/05 22:16:20 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_parsing(char *str, va_list ap, t_flag *flag)
{
	(void)ap;
	if (str[0] == '%')
	{
		str++;
		while (str[0] == '#' || str[0] == '0' || str[0] == '+' || str[0] == '-' || str[0] == ' ' || str[0] == 'z' || str[0] == 'j' || str[0] == 'l' || str[0] == 'h')
		{
			if (set_flag(&str, flag) == 0)
				return (NULL);
			str++;
		}
		/*if (ft_parsing_conversion(str, ap) == 0)
			return (0);*/
	}
	else
	{
		ft_putchar(str[0]);
		str++;
	}
	return (str);
}

/*int	ft_parsing_conversion(char *str, va_list ap)
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
	return (0);
}*/

int	set_flag(char **str, t_flag *flag)
{
	if (flag->hashtag == 0 && (*str)[0] == '#')
	{
		flag->hashtag = 1;
	}
	else if (flag->zero == 0 && (*str)[0] == '0')
	{
		flag->zero = 1;
	}
	else if (flag->plus == 0 && (*str)[0] == '+')
	{
		flag->plus = 1;
	}
	else if (flag->minus == 0 && (*str)[0] == '-')
	{
		flag->minus = 1;
	}
	else if (flag->space == 0 && (*str)[0] == ' ')
	{
		flag->space = 1;
	}
	else if (flag->h == 0 && (*str)[0] == 'h')
	{
		if ((*str)[1] == 'h')
		{
			flag->h = 2;
			(*str)++;
		}
		else
			flag->h = 1;
	}
	else if (flag->l == 0 && (*str)[0] == 'l')
	{
		if ((*str)[1] == 'l')
		{
			flag->l = 2;
			(*str)++;
		}
		else
			flag->l = 1;
	}
	else if (flag->j == 0 && (*str)[0] == 'j')
	{
		flag->j = 1;
	}
	else if (flag->z == 0 && (*str)[0] == 'z')
	{
		flag->z = 1;
	}
	else
	{
		ft_putstr("ccc\n");
		return (0);
	}
	return (1);
}
