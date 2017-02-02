/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:50:02 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 14:50:53 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_set_conversion_specifier(unsigned char *copy,
	t_print *print, unsigned int current_cursor, va_list ap)
{
	unsigned char	*tmp;

	tmp = NULL;
	if (copy[current_cursor] == 'i' || copy[current_cursor] == 'd' ||
	copy[current_cursor] == 'D')
		tmp = ft_id_conversion(print, ap, copy[current_cursor]);
	else if (copy[current_cursor] == 'u' || copy[current_cursor] == 'U')
		tmp = ft_u_conversion(print, ap, copy[current_cursor]);
	else if (copy[current_cursor] == 'x' || copy[current_cursor] == 'X')
		tmp = ft_x_conversion(print, ap, copy[current_cursor]);
	else if (copy[current_cursor] == 'o' || copy[current_cursor] == 'O')
		tmp = ft_o_conversion(print, ap, copy[current_cursor]);
	else if (copy[current_cursor] == 'p')
		tmp = ft_p_conversion(print, ap);
	else if (copy[current_cursor] == 'c' || copy[current_cursor] == 'C')
		tmp = ft_c_conversion(print, ap, copy[current_cursor]);
	else if (copy[current_cursor] == 's' || copy[current_cursor] == 'S')
		tmp = ft_s_conversion(print, ap, copy[current_cursor]);
	else if (copy[current_cursor] == '%')
		tmp = ft_percent_conversion(print);
	else if (copy[current_cursor - 1] != 0)
		tmp = ft_other_conversion(print, copy[current_cursor]);
	else
		return (NULL);
	return (tmp);
}

unsigned char	*ft_id_conversion(t_print *print, va_list ap, char c)
{
	long			nb;
	unsigned char	*tmp;

	tmp = NULL;
	if (print->precision != 0 && print->zero != 0)
		print->zero = 0;
	if (print->h == 1 || print->hh == 1 || print->ll == 1 || print->l == 1 ||
		c == 'D' || print->z == 1 || print->j == 1)
		nb = ft_set_length_modifier_di(print, ap, c);
	else
		nb = va_arg(ap, int);
	tmp = ft_itoa(nb);
	if (nb == 0 && print->precision == -1)
		tmp = (unsigned char*)"";
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_u_conversion(t_print *print, va_list ap, char c)
{
	unsigned long	nb;
	unsigned char	*tmp;

	tmp = NULL;
	if (print->h == 1 || print->hh == 1 || print->ll == 1 || print->l == 1 ||
		print->z == 1 || print->j == 1 || c == 'U')
		nb = ft_set_length_modifier_uox(print, ap, c);
	else
		nb = (unsigned int)va_arg(ap, long);
	tmp = ft_itoa_ubase(nb, 10);
	if (nb == 0)
	{
		print->hashtag = 0;
		if (print->precision == -1)
			tmp = (unsigned char*)"";
	}
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_x_conversion(t_print *print, va_list ap, char c)
{
	unsigned long	nb;
	unsigned char	*tmp;

	tmp = NULL;
	if (print->h == 1 || print->hh == 1 || print->ll == 1 || print->l == 1 ||
		print->z == 1 || print->j == 1)
		nb = ft_set_length_modifier_uox(print, ap, c);
	else
		nb = va_arg(ap, unsigned int);
	tmp = ft_itoa_ubase(nb, 16);
	if (nb == 0)
	{
		print->hashtag = 0;
		if (print->precision == -1)
			tmp = (unsigned char*)"";
	}
	if (c == 'X')
		tmp = ft_strupper(tmp);
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_o_conversion(t_print *print, va_list ap, char c)
{
	unsigned long	nb;
	unsigned char	*tmp;

	tmp = NULL;
	if (print->h == 1 || print->hh == 1 || print->ll == 1 || print->l == 1 ||
		print->z == 1 || print->j == 1 || c == 'O')
		nb = ft_set_length_modifier_uox(print, ap, c);
	else
		nb = va_arg(ap, unsigned int);
	if (nb == 0 && print->precision != 0)
		tmp = (unsigned char*)"";
	else
		tmp = ft_itoa_ubase(nb, 8);
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}
