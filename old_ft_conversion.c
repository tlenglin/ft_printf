/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:08:44 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/10 18:24:52 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int	ft_sS_conversion(char **str, va_list ap)
{
	if ((*str[0]) == 's')
	{
		ft_putstr(va_arg(ap, char*));
	}
	else
	{
		ft_putwstr(va_arg(ap, int*));
	}
	return (0);
}

int	ft_p_conversion(va_list ap)
{
	void *p;
	ft_putstr("0x");
	p = va_arg(ap, void*);
	ft_putstr(ft_itoa_ubase((uintmax_t)p, 16));
	return (0);
}

int	ft_number_conversion(char **str, va_list ap)
{
	intmax_t	nb;
	uintmax_t	unb;
	char *res;

	if ((*str[0]) == 'i' || (*str[0]) == 'd')
	{
		nb = va_arg(ap, intmax_t);
		ft_putnbr(nb); //a modifier pour prendre n compte les nb superieur a int
	}
	else if ((*str[0]) == 'D')
	{
		nb = va_arg(ap, intmax_t);
		ft_putnbr(nb); //idem que precedent car sur nos machines on est deja en long ?

	}
	else if ((*str[0]) == 'o')
	{
		res = ft_itoa_ubase(va_arg(ap, uintmax_t), 8);
		ft_putstr(res);
	}
	else if ((*str[0]) == 'O')
	{
		res = ft_itoa_ubase(va_arg(ap, uintmax_t), 8);
		ft_putstr(res);
	}
	else if ((*str[0]) == 'u')
	{
		unb = va_arg(ap, uintmax_t);
		ft_putnbr(unb); //a ;odifier pour mme raison que i et d
	}
	else if ((*str[0]) == 'U')
	{
		unb = va_arg(ap, uintmax_t);
		ft_putnbr(unb); //a ;odifier pour mme raison que D
	}
	else if ((*str[0]) == 'x')
	{
		unb = va_arg(ap, uintmax_t);
		res = ft_get_hexa(unb, 'x');
		ft_putstr(res);
	}
	else
	{
		unb = va_arg(ap, uintmax_t);
		res = ft_get_hexa(unb, 'X');
		ft_putstr(res);
	}
	return (0);
}

int	ft_cC_conversion(char **str, va_list ap)
{
	int	c;
	if ((*str[0]) == 'c')
	{
		c = va_arg(ap, int);
		ft_putchar(c);
	}
	else
	{
		c = va_arg(ap, int);
		ft_get_wildchar(c);
	}
	return (0);
}

uintmax_t	ft_get_octal(uintmax_t unb)
{
	uintmax_t i;
	uintmax_t res;

	i = 1;
	while (unb != 0)
	{
		res = res + i * (unb % 8);
		i = i * 10;
		unb = unb / 8;
	}
	return (res);
}

char *ft_get_hexa(uintmax_t unb, char c)
{
	char base[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	uintmax_t	i;
	char	*res;
	uintmax_t j;

	j = 0;
	i = unb;
	if (i == 0)
		j = 1;
	while (i != 0)
	{
		i = i / 10;
		j++;
	}
	res = ft_strnew(j);
	i = 1;
	while (unb != 0)
	{
		res[j - 1] = base[unb % 16];
		if (c == 'X')
			res[j - 1] = ft_toupper(res[j - 1]);
		j--;
		unb = unb / 16;
	}
	return (res);
}

char *ft_get_wildchar(int nb)
{
	unsigned char	*multichar;
	unsigned char		c1;
	unsigned char		c2;
	unsigned char		c3;
	unsigned char		c4;

	multichar = ft_strnew(4);
	c1 = 0;
	c2 = 0;
	c3 = 0;
	c4 = 0;
	if (nb <= 127)
	{
		c4 = nb;
	}
	else if (nb <= 2047)
	{
		c3 = nb >> 6;
		c4 = nb - (c3 << 6);
		c3 = c3 + 192;
		c4 = c4 + 128;
	}
	else if (nb <= 65535)
	{
		c2 = nb >> 12;
		c3 = (nb - (c2 << 12)) >> 6;
		c4 = (nb - (c2 << 12) - (c3 << 6));
		c2 = c2 + 224;
		c3 = c3 + 128;
		c4 = c4 + 128;
	}
	else if (nb <= 2097151)
	{
		c1 = nb >> 18;
		c2 = (nb - (c1 << 18)) >> 12;
		c3 = (nb - (c1 << 18) - (c2 << 12)) >> 6;
		c4 = nb - (c1 << 18) - (c2 << 12) - (c3 << 6);
		c1 = c1 + 240;
		c2 = c2 + 128;
		c3 = c3 + 128;
		c4 = c4 + 128;
	}
	return (multichar);
}

void	ft_putwstr(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_get_wildchar(tab[i]);
		i++;
	}
}
