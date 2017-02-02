/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:34:29 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 14:49:23 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_add_zeros(t_print *print, unsigned char *tmp, char c)
{
	int				nb;
	unsigned char	*str;
	unsigned char	*str2;

	nb = print->width - ft_strlen((char*)tmp);
	str = (unsigned char*)ft_strnew(nb);
	if (!(str2 = (unsigned char*)ft_strnew(nb + ft_strlen((char*)tmp) + 1)))
		return (NULL);
	ft_fill_zero(&str, nb);
	if ((c == 'd' || c == 'D' || c == 'i') && print->minus == 1)
		str2 = ft_add_space(print, tmp);
	else if (print->minus == 1)
		str2 = ft_printf_join(tmp, str);
	else if (tmp[1] == 'x' || tmp[1] == 'X')
	{
		str2 = ft_printf_join(str, (unsigned char*)ft_strsub((char*)tmp, 2,
		ft_strlen((char*)tmp)));
		str2 = ft_set_flag_hashtag(c, str2);
	}
	else
		str2 = ft_printf_join(str, tmp);
	return (str2);
}

int				ft_fill_zero(unsigned char **str, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		(*str)[i] = '0';
		i++;
	}
	return (0);
}

unsigned char	*ft_add_space(t_print *print, unsigned char *tmp)
{
	int				nb;
	unsigned char	*str;
	unsigned char	*str2;
	int				i;

	i = 0;
	nb = print->width - ft_strlen((char*)tmp);
	str = (unsigned char*)ft_strnew(nb);
	while (i < nb)
	{
		str[i] = ' ';
		i++;
	}
	if (!(str2 = (unsigned char*)ft_strnew(nb + ft_strlen((char*)tmp) + 1)))
		return (NULL);
	if (print->minus == 1)
	{
		str2 = ft_printf_join(tmp, str);
	}
	else
	{
		str2 = ft_printf_join(str, tmp);
	}
	return (str2);
}
