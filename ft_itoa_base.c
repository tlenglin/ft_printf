/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:45:28 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 14:53:20 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int				ft_set_cursor(unsigned int cursor, unsigned char *copy)
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

unsigned char	*ft_printf_join(unsigned char *str1,
	unsigned char *str2)
{
	unsigned char	*tmp;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = -1;
	tmp = NULL;
	if (str1 == NULL)
		tmp = (unsigned char*)ft_strdup((char*)str2);
	else if (str2 == NULL)
		tmp = (unsigned char*)ft_strdup((char*)str1);
	else
	{
		if (!(tmp = (unsigned char*)ft_strnew(ft_strlen((char*)str1) +
		ft_strlen((char*)str2) + 1)))
			return (NULL);
		while (str1[++i])
			tmp[i] = str1[i];
		while (str2[++j])
		{
			tmp[i] = str2[j];
			i++;
		}
	}
	return (tmp);
}

unsigned char	*ft_printf_join_bis(unsigned char *str1, unsigned char *str2,
	unsigned int len1, unsigned int len2)
{
	unsigned char	*tmp;
	unsigned int	i;

	i = -1;
	tmp = NULL;
	if (str1 == NULL)
	{
		tmp = (unsigned char*)ft_strnew(len2);
		while (++i < len2)
			tmp[i] = str2[i];
	}
	else if (str2 == NULL)
	{
		tmp = (unsigned char*)ft_strnew(len1);
		while (++i < len1)
			tmp[i] = str1[i];
	}
	else
	{
		tmp = ft_printf_join_ter(len1, len2, str1, str2);
	}
	return (tmp);
}

unsigned char	*ft_printf_join_ter(unsigned int len1, unsigned int len2,
	unsigned char *str1, unsigned char *str2)
{
	unsigned char	*tmp;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	tmp = NULL;
	if (!(tmp = (unsigned char*)ft_strnew(len1 + len2 + 1)))
		return (NULL);
	while (++i < len1)
		tmp[i] = str1[i];
	while (j < len2)
	{
		tmp[i] = str2[j];
		i++;
		j++;
	}
	return (tmp);
}
