/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:43:01 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/17 06:34:23 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void		itoa_isnegative(long *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

unsigned char	*ft_itoa(long n)
{
	long		buffer;
	unsigned int	len;
	int		negative;
	unsigned char	*str;

	buffer = n;
	len = 2;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (buffer /= 10)
		len++;
	len += negative;
	if ((str = (unsigned char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) <= 0 ? -(n % 10) + '0' : n % 10 + '0';
		n = (n / 10) < 0 ? -(n / 10) : n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
