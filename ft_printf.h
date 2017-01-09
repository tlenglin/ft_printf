/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:28:06 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/09 14:39:37 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "./libft/libft.h"
# include <stdint.h>

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
}				t_flag;

int	ft_printf(const char *str, ...);
char	*ft_parsing(char *str, va_list ap, t_flag *flag);
int	ft_parsing_conversion(char **str, t_flag *flag, va_list ap);
int	set_flag(char **str, t_flag *flag);
int	ft_sS_conversion(char **str, va_list ap);
int	ft_p_conversion(va_list ap);
int	ft_number_conversion(char **str, va_list ap);
int	ft_cC_conversion(char **str, va_list ap);
uintmax_t	ft_get_octal(uintmax_t unb);
char	*ft_get_hexa(uintmax_t unb, char c);
char	*ft_itoa_ubase(uintmax_t unb, int base);
void	ft_putunbr(uintmax_t nb);
char *ft_get_wildchar(int nb);
void	ft_putwstr(int *tab);



#endif
