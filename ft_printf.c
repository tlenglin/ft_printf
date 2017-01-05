/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:29:24 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/05 21:29:49 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flag	*flag;
	char	*str2;

	str2 = ft_strdup(str);
	if (!(flag = ft_memalloc(sizeof(t_flag))))
		return (0);
	va_start(ap, str);
	while (str2[0] != '\0')
	{
		if ((str2 = ft_parsing(str2, ap, flag)) == 0)
			return (0);
	}
	ft_putstr("\nflag-># = ");
	ft_putnbr(flag->hashtag);
	ft_putstr("\nflag->0 = ");
	ft_putnbr(flag->zero);
	ft_putstr("\nflag->+ = ");
	ft_putnbr(flag->plus);
	ft_putstr("\nflag->- = ");
	ft_putnbr(flag->minus);
	ft_putstr("\nflag->space = ");
	ft_putnbr(flag->space);
	ft_putstr("\nflag->h = ");
	ft_putnbr(flag->h);
	ft_putstr("\nflag->l = ");
	ft_putnbr(flag->l);
	ft_putstr("\nflag->j = ");
	ft_putnbr(flag->j);
	ft_putstr("\nflag->z = ");
	ft_putnbr(flag->z);
	return (0);
}
