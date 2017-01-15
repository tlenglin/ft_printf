/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:39:50 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/15 12:32:05 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_set_conversion_specifier(unsigned char *copy, t_print *print, unsigned int current_cursor, va_list ap)
{
	unsigned char	*tmp;

	tmp = NULL;
	if (copy[current_cursor] == 'i' || copy[current_cursor] == 'd' || copy[current_cursor] == 'D')
	{
		tmp = ft_id_conversion(print, ap, copy[current_cursor]);
	}
	else if (copy[current_cursor] == 'u' || copy[current_cursor] == 'U')
	{
		tmp = ft_u_conversion(print, ap, copy[current_cursor]);
	}
	else if (copy[current_cursor] == 'x' || copy[current_cursor] == 'X')
	{
		tmp = ft_x_conversion(print, ap, copy[current_cursor]);
	}
	else if (copy[current_cursor] == 'o' || copy[current_cursor] == 'O')
	{
		tmp = ft_o_conversion(print, ap, copy[current_cursor]);
	}
	else if (copy[current_cursor] == 'p')
	{
		tmp = ft_p_conversion(print, ap);
	}
	else if (copy[current_cursor] == 'c' || copy[current_cursor] == 'C')
	{
		tmp = ft_c_conversion(print, ap, copy[current_cursor]);
	}
	else if (copy[current_cursor] == 's' || copy[current_cursor] == 'S')
	{
		tmp = ft_s_conversion(print, ap, copy[current_cursor]);
	}
	else if (copy[current_cursor] == '%')
	{
		// ft_putstr("kkkk\n");
		tmp = ft_percent_conversion(print);
	}
	else
		return (NULL);
	return (tmp);
}

unsigned char	*ft_id_conversion(t_print *print, va_list ap, char c)
{
	long nb;
	unsigned char	*tmp;

	tmp = NULL;
	if (print->h == 1 || print->hh == 1 || print->ll == 1 || print->l == 1 || c == 'D')
	{
		nb = ft_set_length_modifier_di(print, ap, c);
	}
	else
		nb = va_arg(ap, int);
	tmp = (unsigned char*)ft_itoa(nb);
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_u_conversion(t_print *print, va_list ap, char c)
{
	unsigned long int	nb;
	unsigned char	*tmp;

	tmp = NULL;
	if (print->h == 1 || print->hh == 1 || print->ll == 1 || print->l == 1 || c == 'U')
	{
		nb = ft_set_length_modifier_uox(print, ap, c);
	}
	else
		nb = va_arg(ap, unsigned int);
	tmp = (unsigned char*)ft_itoa(nb);
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_x_conversion(t_print *print, va_list ap, char c)
{
	unsigned int nb;
	unsigned char	*tmp;

	tmp = NULL;
	if (print->h == 1 || print->hh == 1 || print->ll == 1 || print->l == 1)
	{
		nb = ft_set_length_modifier_uox(print, ap, c);
	}
	else
		nb = va_arg(ap, unsigned int);
	tmp = ft_itoa_ubase(nb, 16);
	if (c == 'X')
		tmp = ft_strupper(tmp);
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_o_conversion(t_print *print, va_list ap, char c)
{
	unsigned int nb;
	unsigned char	*tmp;

	tmp = NULL;
	if (print->h == 1 || print->hh == 1 || print->ll == 1 || print->l == 1)
	{
		nb = ft_set_length_modifier_uox(print, ap, c);
	}
	else
		nb = va_arg(ap, unsigned int);
	tmp = ft_itoa_ubase(nb, 8);
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_s_conversion(t_print *print, va_list ap, char c)
{
	int *nb;
	int i;
	unsigned char	*tmp;

	tmp = NULL;
	nb = NULL;
	i = 0;
	if (c == 's')
	{
		if (print->l == 1)
		{
			nb = va_arg(ap, int*);
			while (nb[i] != 0)
			{
				tmp = ft_printf_join(tmp, ft_get_wildchar(nb[i]));
				i++;
			}
		}
		else if (print->hh == 1 || print->h == 1 || print->ll == 1 || print->j == 1 || print->z == 1)
			return (NULL);
		tmp = (unsigned char*)va_arg(ap, char*);
	}
	else
	{
		if (print->l == 1 || print->hh == 1 || print->h == 1 || print->ll == 1 || print->j == 1 || print->z == 1)
			return (NULL);
		nb = va_arg(ap, int*);
		while (nb[i] != 0)
		{
			tmp = ft_printf_join(tmp, ft_get_wildchar(nb[i]));
			i++;
		}
	}
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_c_conversion(t_print *print, va_list ap, char c)
{
	int nb;
	unsigned char	*tmp;

	tmp = NULL;
	nb = va_arg(ap, int);
	if (c == 'c')
	{
		tmp = (unsigned char*)ft_strnew(1);
		tmp[0] = (unsigned char)nb;
		if (print->l == 1)
			tmp = ft_get_wildchar(nb);
		else if (print->hh == 1 || print->h == 1 || print->ll == 1 || print->j == 1 || print->z == 1)
			return (NULL);
	}
	else
	{
		tmp = ft_get_wildchar(nb);
	}
	tmp = ft_set_flag(c, tmp, print);
	return (tmp);
}

unsigned char	*ft_p_conversion(t_print *print, va_list ap)
{
	void	*p;
	unsigned char	*tmp;

	tmp = NULL;
	if (print->precision != 0)
		return (0);
	if (print->hh == 1 || print->h == 1 || print->ll == 1 || print->j == 1 || print->z == 1 || print->l == 1)
		return (NULL);
	if (print->zero == 1 || print->hashtag == 1 || print->plus == 1 || print->space == 1)
		return (NULL);
	p = va_arg(ap, void*);
	tmp = ft_printf_join((unsigned char*)"0x", ft_itoa_ubase((unsigned long)p, 16));
	if (print->width > (int)ft_strlen((char*)tmp))
	{
		tmp = ft_add_space(print, tmp);
	}
	return (tmp);
}

unsigned char *ft_percent_conversion(t_print *print)
{
	unsigned char *tmp;

	tmp = (unsigned char*)ft_strnew(1);
	tmp[0] = '%';
	if (print->hh == 1 || print->h == 1 || print->ll == 1 || print->j == 1 || print->z == 1 || print->l == 1)
	{
		// ft_putstr("ggg\n");
		return (NULL);
	}
	// ft_putstr("\nwidth = ");
	// ft_putnbr(print->width);
	// ft_putchar('\n');
	if (print->width > 1)
	{
		// ft_putstr("hhh\n");
		if (print->zero == 1 && print->minus == 0)
		{
			tmp = ft_add_zeros(print, tmp);
		}
		else
		{
			print->zero = 0;
			tmp = ft_add_space(print, tmp);
		}
	}
	// ft_putstr("iii\n");
	// ft_putstr((char*)tmp);
	return (tmp);
}
