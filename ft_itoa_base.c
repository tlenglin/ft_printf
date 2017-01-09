/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:45:28 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/09 12:06:13 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_ubase(uintmax_t unb, int base)
{
	char tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	uintmax_t	i;
	char	*res;
	uintmax_t j;

	j = 0;
	i = unb;
	if (i == 0)
		j = 1;
	while (i != 0)
	{
		i = i / base;
		j++;
	}
	res = ft_strnew(j);
	i = 1;
	while (unb != 0)
	{
		res[j - 1] = tab[unb % base];
		j--;
		unb = unb / base;
	}
	return (res);
}

void	ft_putunbr(uintmax_t nb)
{
	if (nb > 9)
	{
		ft_putunbr(nb / 10);
		ft_putunbr(nb % 10);
		return ;
	}
	ft_putchar('0' + nb);
}
