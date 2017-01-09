/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 11:52:51 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/09 19:43:20 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	/*ft_printf("test 1 \ncoucou");
	ft_printf("test 1 \n");*/
	/*ft_putendl(ft_itoa_ubase(17, 2));
	ft_putendl(ft_itoa_ubase(17 >> 1, 2));
	ft_putendl(ft_itoa_ubase(17 >> 2, 2));
	ft_putendl(ft_itoa_ubase(17 >> 3, 2));
	ft_putendl(ft_itoa_ubase(17 >> 4, 2));
	ft_putendl(ft_itoa_ubase(17 >> 5, 2));
	ft_putendl(ft_itoa_ubase(17 >> 6, 2));
	ft_putendl(ft_itoa_ubase(17 >> 7, 2));*/
	/*ft_putendl(ft_itoa_ubase(ft_get_wildchar(65537)[0], 2));
	ft_putendl(ft_itoa_ubase(ft_get_wildchar(65537)[1], 2));
	ft_putendl(ft_itoa_ubase(ft_get_wildchar(65537)[2], 2));
	ft_putendl(ft_itoa_ubase(ft_get_wildchar(65537)[3], 2));*/


	/*ft_putnbr(ft_get_wildchar(128)[0]);
	ft_putnbr(ft_get_wildchar(128)[1]);
	ft_putnbr(ft_get_wildchar(128)[2]);
	ft_putnbr(ft_get_wildchar(128)[3]);*/
	ft_printf("123 %llX %0#hhs", 63, "c'est moi");
	ft_putchar('\n');
	//ft_printf("123 %S", 10084);
	//printf("c1 = %d\nc2 = %d\nc3 = %d\nc4 = %d\n", ft_get_wildchar(128)[0], ft_get_wildchar(128)[1], ft_get_wildchar(128)[2], ft_get_wildchar(128)[3]);
	/*ft_putendl(ft_itoa_ubase(ft_get_wildchar(65537)[0], 2));
	ft_putendl(ft_itoa_ubase(ft_get_wildchar(65537)[1], 2));
	ft_putendl(ft_itoa_ubase(ft_get_wildchar(65537)[2], 2));
	ft_putendl(ft_itoa_ubase(ft_get_wildchar(65537)[3], 2));*/
	return (0);
}
