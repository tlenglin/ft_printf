/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:50:28 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 14:51:10 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_s_conversion(t_print *print, va_list ap, char c)
{
	int				*nb;
	unsigned char	*tmp;

	tmp = NULL;
	nb = NULL;
	if (c == 's')
		tmp = ft_s_conversion1(print, ap, &nb);
	else
		tmp = ft_s_conversion2(print, ap, &nb);
	if (((c == 's' && print->l == 1) || c == 'S') && (nb == NULL || nb[0] == 0))
		tmp = (unsigned char*)"";
	if (tmp == NULL)
		tmp = (unsigned char*)"(null)";
	if (((c == 's' && print->l == 1) || c == 'S') && nb == NULL)
		tmp = (unsigned char*)"(null)";
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_s_conversion2(t_print *print, va_list ap, int **nb)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = NULL;
	*nb = va_arg(ap, int*);
	while (*nb != NULL && (*nb)[i] != 0)
	{
		tmp = ft_printf_join(tmp, ft_get_wildchar((*nb)[i], print));
		i++;
	}
	return (tmp);
}

unsigned char	*ft_s_conversion1(t_print *print, va_list ap, int **nb)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	tmp = NULL;
	if (print->l == 1)
	{
		*nb = va_arg(ap, int*);
		while ((*nb)[i] != 0)
		{
			tmp = ft_printf_join(tmp, ft_get_wildchar((*nb)[i], print));
			i++;
		}
	}
	else
	{
		tmp = (unsigned char*)va_arg(ap, char*);
	}
	return (tmp);
}

unsigned char	*ft_c_conversion(t_print *print, va_list ap, char c)
{
	int				nb;
	unsigned char	*tmp;

	tmp = NULL;
	nb = va_arg(ap, int);
	if (c == 'c')
	{
		tmp = (unsigned char*)ft_strnew(1);
		tmp[0] = (unsigned char)nb;
		if (tmp[0] == 0)
		{
			tmp = ft_set_flag(c, tmp, print);
			return (tmp);
		}
		if (tmp[0] == 32)
			print->lc = -1;
		if (print->l == 1)
			tmp = ft_get_wildchar(nb, print);
	}
	else
		tmp = ft_get_wildchar(nb, print);
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_p_conversion(t_print *print, va_list ap)
{
	void			*p;
	unsigned char	*tmp;

	tmp = NULL;
	p = va_arg(ap, void*);
	tmp = ft_itoa_ubase((unsigned long)p, 16);
	if (ft_atoi((char*)tmp) == 0 && print->precision < 0)
		return ((unsigned char*)"0x");
	if (print->precision > 0)
		tmp = ft_add_zeros_precision(print, tmp);
	tmp = ft_printf_join((unsigned char*)"0x", tmp);
	if (print->width > (int)ft_strlen((char*)tmp))
	{
		if (print->minus == 1)
			tmp = ft_add_space(print, tmp);
		else if (print->zero == 1)
		{
			print->minus = 1;
			tmp = ft_add_zeros(print, tmp, 'p');
		}
		else
			tmp = ft_add_space(print, tmp);
	}
	return (tmp);
}
