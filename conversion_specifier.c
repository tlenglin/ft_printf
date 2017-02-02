/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:39:50 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 14:51:17 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

unsigned char	*ft_percent_conversion(t_print *print)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)ft_strnew(1);
	tmp[0] = '%';
	if (print->hh == 1 || print->h == 1 || print->ll == 1 || print->j == 1 ||
		print->z == 1 || print->l == 1)
		return (NULL);
	if (print->width > 1)
	{
		if (print->zero == 1 && print->minus == 0)
			tmp = ft_add_zeros(print, tmp, '%');
		else
		{
			print->zero = 0;
			tmp = ft_add_space(print, tmp);
		}
	}
	return (tmp);
}

unsigned char	*ft_other_conversion(t_print *print, unsigned char c)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)ft_strnew(1);
	tmp[0] = c;
	if (print->hh == 1 || print->h == 1 || print->ll == 1 || print->j == 1 ||
		print->z == 1 || print->l == 1)
		return (NULL);
	if (print->width > 1)
	{
		if (print->zero == 1 && print->minus == 0)
			tmp = ft_add_zeros(print, tmp, '%');
		else
		{
			print->zero = 0;
			tmp = ft_add_space(print, tmp);
		}
	}
	return (tmp);
}
