/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:29:24 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/03 23:17:32 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flag	*flag;

	if (!(flag = ft_memalloc(sizeof(flag))))
		return (0);
	va_start(ap, str);
	while (str)
	{
		if (ft_parsing(str, ap) == 0)
			return (0);
		str++;
	}
	return (0);
}
