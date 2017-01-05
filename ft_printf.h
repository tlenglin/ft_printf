/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:28:06 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/05 21:48:31 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct	s_flag
{
	int	hashtag;
	int	zero;
	int	l;
	int	plus;
	int	minus;
	int	space;
	int	h;
	int	j;
	int	z;
}								t_flag;

int	ft_printf(const char *str, ...);
char	*ft_parsing(char *str, va_list ap, t_flag *flag);
int	ft_parsing_conversion(char *str, va_list ap);
int	set_flag(char **str, t_flag *flag);
//int	ft_sS_conversion(char *str, va_list ap);
//int	ft_p_conversion(char *str, va_list ap);
//int	ft_number_conversion(char *str, va_list ap);
//int	ft_cC_conversion(char *str, va_list ap);

#endif
