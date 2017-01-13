/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:28:06 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/13 18:14:52 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "./libft/libft.h"
# include <stdint.h>

/*typedef struct	s_flag
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
}				t_flag;*/

typedef struct	s_print
{
	int	hashtag;
	int	zero;
	int	plus;
	int	minus;
	int	space;
	int width;
	int precision;
	int	h;
	int	j;
	int	z;
	int hh;
	int ll;
	int l;
}				t_print;

int				ft_printf(const char *str, ...);
unsigned char	*ft_global_parsing(unsigned char *copy, t_print *print, unsigned int cursor, va_list ap);

unsigned char	*ft_set_conversion_specifier(unsigned char *copy, t_print *print, unsigned int current_cursor, va_list ap);
unsigned char	*ft_id_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_u_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_x_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_o_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_s_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_c_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_p_conversion(t_print *print, va_list ap);
unsigned char	*ft_percent_conversion(t_print *print);

int				ft_parsing_length_modifier(unsigned char *copy, t_print *print, unsigned int current_cursor);
long			ft_set_length_modifier_di(t_print *print, va_list ap, char c);
unsigned long	ft_set_length_modifier_uox(t_print *print, va_list ap, char c);

t_print			*ft_reset_flag(void);
int				ft_parsing_flag(unsigned char *copy, t_print *print, unsigned int current_cursor);
unsigned char	*ft_set_flag_signed_number(char c, unsigned char *str, t_print *print);
unsigned char	*ft_set_flag_unsigned_number(char c, unsigned char *str, t_print *print);
unsigned char	*ft_set_flag_char(unsigned char *str, t_print *print);
unsigned char	*ft_set_flag(char c, unsigned char *str, t_print *print);
unsigned char	*ft_set_flag_plus_space(char c, unsigned char *str, t_print *print);
unsigned char	*ft_set_flag_hashtag(char c, unsigned char *str);

unsigned char	*ft_add_zeros_precision(t_print *print, unsigned char *tmp);
int				ft_parsing_width(unsigned char *copy, t_print *print, unsigned int current_cursor);
int	ft_parsing_precision(unsigned char *copy, t_print *print, unsigned int current_cursor);
unsigned char	*ft_add_zeros(t_print *print, unsigned char *tmp);
unsigned char	*ft_add_space(t_print *print, unsigned char *tmp);

unsigned char	*ft_itoa_ubase(uintmax_t unb, int base);
void			ft_putunbr(uintmax_t nb);
int	ft_strchr_position(unsigned char *str, unsigned char c);
unsigned char	*ft_get_wildchar(int nb);
unsigned char	*ft_strupper(unsigned char *str);
int				ft_set_cursor(unsigned int cursor, unsigned char *copy);
unsigned char	*ft_printf_join(unsigned char *str1, unsigned char *str2);


#endif
