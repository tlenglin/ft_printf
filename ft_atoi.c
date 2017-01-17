/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:27:23 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/16 22:55:27 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int		ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				sign;
	unsigned int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (nptr == NULL)
		return (0);
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' ||
					nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == '\f'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		if ((res == 214748364) && (nptr[i] == 8))
			return (-2147483648);
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * sign);
}
