/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:45:28 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/13 15:57:25 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*ft_itoa_ubase(uintmax_t unb, int base)
{
	unsigned char tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	uintmax_t	i;
	unsigned char	*res;
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
	res = (unsigned char*)ft_strnew(j);
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

int ft_strchr_position(unsigned char *str, unsigned char c)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			// ft_putstr("percent en position ");
			// ft_putnbr(i);
			// ft_putchar('\n');
			return (i);
		}
		i++;
	}
	// ft_putstr("strchrpos -1\n");
	return (-1);
}

unsigned char *ft_get_wildchar(int nb)
{
	unsigned char	*multichar;
	unsigned char		c1;
	unsigned char		c2;
	unsigned char		c3;
	unsigned char		c4;

	multichar = (unsigned char*)ft_strnew(4);
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

unsigned char	*ft_strupper(unsigned char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
		i++;
	}
	return (str);
}

int	ft_set_cursor(unsigned int cursor, unsigned char *copy)
{
	unsigned int i;

	i = cursor + 1;
	while (copy[i])
	{
		if (copy[i] == '%' || copy[i] == 'd' || copy[i] == 'D' || copy[i] == 'i'
		|| copy[i] == 'o' || copy[i] == 'O' || copy[i] == 'x' || copy[i] == 'X'
		|| copy[i] == 'u' || copy[i] == 'U' || copy[i] == 'c' || copy[i] == 'C'
		|| copy[i] == 's' || copy[i] == 'S' || copy[i] == 'p')
			return (i + 1);
		i++;
	}
	return (-1);
}

unsigned char	*ft_printf_join(unsigned char *str1, unsigned char *str2)
{
	unsigned char	*tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	tmp = NULL;
	if (str1 == NULL)
	{
		tmp = (unsigned char*)ft_strdup((char*)str2);
	}
	else if (str2 == NULL)
	{
		tmp = (unsigned char*)ft_strdup((char*)str1);
	}
	else
	{
		if (!(tmp = (unsigned char*)ft_strnew(ft_strlen((char*)str1) + ft_strlen((char*)str2) + 1)))
			return (NULL);
		while (str1[i])
		{
			tmp[i] = str1[i];
			i++;
		}
		while (str2[j])
		{
			tmp[i] = str2[j];
			i++;
			j++;
		}
	}
	return (tmp);
}
