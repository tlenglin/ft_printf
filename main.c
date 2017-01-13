/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 11:52:51 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/13 19:35:00 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("%o-x\n", 128);
	ft_printf("%0.5o-.5x\n", 128);
	ft_printf("%09.5o-5x\n", 128);
	ft_printf("%.5o-.5x\n", 128);
	ft_printf("%5o-5x\n", 128);
	ft_printf("%5.5o-5.5x\n", 128);
	ft_printf("%6.5o-6.5x\n", 128);
	ft_printf("%5.6o-5.6x\n", 128);
	ft_printf("%#5.5o-5.5x\n", 128);
	ft_printf("%#09.o-6.5x\n", 128);
	ft_printf("%#09o-6.5x\n", 128);
	ft_printf("%#5.6o-5.6x\n", 128);
	// ft_printf("%x-x\n", 128);
	// ft_printf("%0.5x-.5x\n", 128);
	// ft_printf("%09.5x-09.5x\n", 128);
	// ft_printf("%.5x-.5x\n", 128);
	// ft_printf("%5x-5x\n", 128);
	// ft_printf("%5.5x-5.5x\n", 128);
	// ft_printf("%6.5x-6.5x\n", 128);
	// ft_printf("%5.6x-5.6x\n", 128);
	// ft_printf("%#5.5x-5.5x\n", 128);
	// ft_printf("%#09.x-6.5x\n", 128);
	// ft_printf("%#09x-6.5x\n", 128);
	// ft_printf("%#5.6x-5.6x\n", 128);
	// ft_printf("%7d 7d\n", -123456);
	// ft_printf("%.7d .7d\n", -123456);
	// ft_printf("%+.7d +.7d\n", -123456);
	// ft_printf("%0+.7d 0+.7d\n", -123456);
	// ft_printf("%-+.7d -+.7d\n", -123456);
	// ft_printf("%0 .7d 0 .7d\n", -123456);
	// ft_printf("%- .7d - .7d\n", -123456);
	// ft_printf("%0+7d 0+7d\n", -123456);
	// ft_printf("%-+7d -+7d\n", -123456);
	// ft_printf("%0 7d 0 7d\n", -123456);
	// ft_printf("%- 7d - 7d\n", -123456);
	// ft_printf("%0+7.7d 0+7.7d\n", -123456);
	// ft_printf("%-+7.7d -+7.7d\n", -123456);
	// ft_printf("%0 7.7d 0 7.7d\n", -123456);
	// ft_printf("%- 7.7d - 7.7d\n", -123456);
	// ft_printf("%0+8.7d 0+8.7d\n", -123456);
	// ft_printf("%-+8.7d -+8.7d\n", -123456);
	// ft_printf("%0 8.7d 0 8.7d\n", -123456);
	// ft_printf("%- 8.7d - 8.7d\n", -123456);
	// ft_printf("%0+7.8d 0+7.8d\n", -123456);
	// ft_printf("%-+7.8d -+7.8d\n", -123456);
	// ft_printf("%0 7.8d 0 7.8d\n", -123456);
	// ft_printf("%- 7.8d - 7.8d\n", -123456);
	// ft_printf("%-12.7d - 7.8d\n", -123456);
	// ft_printf("123%03%45678%-4%coucou\n");
	// ft_printf("%3%\n");
	// ft_printf("%+3%\n");
	// ft_printf("% 3%\n");
	// ft_printf("%-3%\n");
	// ft_printf("%03%\n");
	// ft_printf("%0-3%\n");
	// ft_printf("%0+ #3%\n");
	// ft_printf("%-+ #3%-\n");
	//
	// ft_printf("%.3%-.3\n");
	// ft_printf("%+.3%-+.3\n");
	// ft_printf("% .3%- .3\n");
	// ft_printf("%-.3%--.3\n");
	// ft_printf("%0.3%-0.3\n");
	// ft_printf("%0-.3%-0-.3\n");
	// ft_printf("%0+ #.3%-0+ #.3\n");
	// ft_printf("%-+ #.3%-0+ #.3\n");
	//
	// ft_printf("%3.3%-3.3\n");
	// ft_printf("%+3.3%-+3.3\n");
	// ft_printf("% 3.3%- 3.3\n");
	// ft_printf("%-3.3%--3.3\n");
	// ft_printf("%03.3%-03.3\n");
	// ft_printf("%0-3.3%-0-3.3\n");
	// ft_printf("%0+ #3.3%-0+ #3.3\n");
	// ft_printf("%-+ #3.3%-0+ #3.3\n");
	return (0);
}
