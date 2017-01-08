/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 23:08:44 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/08 16:21:22 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sS_conversion(char **str, va_list ap)
{
	if ((*str[0]) == 's')
	{
		ft_putstr(va_arg(ap, char*));
	}
	/*else
	{

	}*/
	return (0);
}

int	ft_p_conversion(va_list ap)
{
	void *p;
	ft_putstr("0x");
	p = va_arg(ap, void*);
	ft_putstr(ft_get_hexa((uintmax_t)p, 'x'));
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
		unb = ft_get_octal(va_arg(ap, uintmax_t));
		ft_putnbr(unb);
	}
	else if ((*str[0]) == 'O')
	{
		unb = ft_get_octal(va_arg(ap, uintmax_t));
		ft_putnbr(unb);
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
	char res[4] = {0, 0, 0, 0};
	if ((*str[0]) == 'c')
	{
		res[0] = va_arg(ap, int);
		ft_putchar(res[0]);
	}
	/*else
	{

	}*/
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
