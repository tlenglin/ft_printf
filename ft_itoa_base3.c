/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:52:09 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 14:53:12 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_get_wildchar3(unsigned char **multichar, int nb,
	t_print *print)
{
	unsigned char		c3;
	unsigned char		c4;

	c3 = 0;
	c4 = 0;
	*multichar = (unsigned char*)ft_strnew(2);
	c3 = nb >> 6;
	c4 = nb - (c3 << 6);
	c3 = c3 + 192;
	c4 = c4 + 128;
	(*multichar)[0] = c3;
	(*multichar)[1] = c4;
	print->lc = 1;
	return (0);
}

int				ft_get_wildchar4(unsigned char **multichar, int nb,
	t_print *print)
{
	unsigned char		c2;
	unsigned char		c3;
	unsigned char		c4;

	c2 = 0;
	c3 = 0;
	c4 = 0;
	*multichar = (unsigned char*)ft_strnew(3);
	c2 = nb >> 12;
	c3 = (nb - (c2 << 12)) >> 6;
	c4 = (nb - (c2 << 12) - (c3 << 6));
	c2 = c2 + 224;
	c3 = c3 + 128;
	c4 = c4 + 128;
	(*multichar)[0] = c2;
	(*multichar)[1] = c3;
	(*multichar)[2] = c4;
	print->lc = 2;
	return (0);
}

int				ft_get_wildchar5(unsigned char **multichar, int nb,
	t_print *print)
{
	unsigned char		c1;
	unsigned char		c2;
	unsigned char		c3;
	unsigned char		c4;

	c1 = 0;
	c2 = 0;
	c3 = 0;
	c4 = 0;
	*multichar = (unsigned char*)ft_strnew(4);
	c1 = nb >> 18;
	c2 = (nb - (c1 << 18)) >> 12;
	c3 = (nb - (c1 << 18) - (c2 << 12)) >> 6;
	c4 = nb - (c1 << 18) - (c2 << 12) - (c3 << 6);
	c1 = c1 + 240;
	c2 = c2 + 128;
	c3 = c3 + 128;
	c4 = c4 + 128;
	(*multichar)[0] = c1;
	(*multichar)[1] = c2;
	(*multichar)[2] = c3;
	(*multichar)[3] = c4;
	print->lc = 3;
	return (0);
}

unsigned char	*ft_cut_wide_character(unsigned char *str)
{
	unsigned int	end;
	int				count;
	unsigned char	*tmp;

	count = 0;
	tmp = NULL;
	end = ft_strlen((char*)str);
	end--;
	if (str[end] < 128)
	{
		return (str);
	}
	else if (str[end] < 192)
	{
		while (str[end] < 192)
		{
			count++;
			end--;
		}
		tmp = ft_cut_wide_character2(str, end, count, tmp);
	}
	else
		tmp = (unsigned char*)ft_strsub((char*)str, 0,
		ft_strlen((char*)str) - 1);
	return (tmp);
}

unsigned char	*ft_cut_wide_character2(unsigned char *str, unsigned int end,
	int count, unsigned char *tmp)
{
	if (str[end] < 224)
	{
		if (count == 1)
			return (str);
		else
			tmp = (unsigned char*)ft_strsub((char*)str, 0,
			ft_strlen((char*)str) - (count + 1));
	}
	else if (str[end] < 240)
	{
		if (count == 2)
			return (str);
		else
			tmp = (unsigned char*)ft_strsub((char*)str, 0,
			ft_strlen((char*)str) - (count + 1));
	}
	else if (str[end] >= 240)
	{
		if (count == 3)
			return (str);
		else
			tmp = (unsigned char*)ft_strsub((char*)str, 0,
			ft_strlen((char*)str) - (count + 1));
	}
	return (tmp);
}
