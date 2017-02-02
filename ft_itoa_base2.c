/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:51:45 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 15:24:43 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_itoa_ubase(uintmax_t unb, int base)
{
	unsigned char	*tab;
	uintmax_t		i;
	unsigned char	*res;
	uintmax_t		j;

	j = 0;
	i = unb;
	tab = NULL;
	ft_init_tab(&tab);
	j = (i == 0) ? 1 : 0;
	while (i != 0)
	{
		i = i / base;
		j++;
	}
	j = (j == 0) ? 1 : j;
	res = (unsigned char*)ft_strnew(j);
	res[0] = '0';
	while (unb != 0)
	{
		res[j - 1] = tab[unb % base];
		j--;
		unb = unb / base;
	}
	return (res);
}

void			ft_putunbr(uintmax_t nb)
{
	if (nb > 9)
	{
		ft_putunbr(nb / 10);
		ft_putunbr(nb % 10);
		return ;
	}
	ft_putchar('0' + nb);
}

int				ft_strchr_position(unsigned char *str, unsigned char c)
{
	unsigned int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

unsigned char	*ft_get_wildchar(int nb, t_print *print)
{
	unsigned char		*multichar;

	multichar = NULL;
	if (nb <= 127)
	{
		ft_get_wildchar2(&multichar, nb, print);
	}
	else if (nb <= 2047)
	{
		ft_get_wildchar3(&multichar, nb, print);
	}
	else if (nb <= 65535)
	{
		ft_get_wildchar4(&multichar, nb, print);
	}
	else if (nb <= 2097151)
	{
		ft_get_wildchar5(&multichar, nb, print);
	}
	return (multichar);
}

int				ft_get_wildchar2(unsigned char **multichar, int nb,
	t_print *print)
{
	unsigned char		c4;

	c4 = 0;
	*multichar = (unsigned char*)ft_strnew(1);
	c4 = nb;
	(*multichar)[0] = c4;
	print->lc = (nb == 32) ? -1 : 0;
	return (0);
}
