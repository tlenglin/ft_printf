/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:28:06 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/25 15:09:43 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_print
{
	int				hashtag;
	int				zero;
	int				plus;
	int				minus;
	int				space;
	int				width;
	int				precision;
	int				h;
	int				j;
	int				z;
	int				hh;
	int				ll;
	int				l;
	unsigned long	lc;
	unsigned long	length;
}				t_print;

int				ft_printf(const char *str, ...);
unsigned char	*ft_global_parsing(unsigned char *copy, t_print *print,
	unsigned int cursor, va_list ap);
int				ft_printf2(const char *str, va_list ap, t_print *print);
int				ft_printf3(t_print *print, unsigned char *tmp);
unsigned char	*ft_printf4(unsigned char **copy, t_print *print, va_list ap);
int				ft_printf5(int *cursor, t_print *print, unsigned char *copy,
	unsigned char *tmp);
unsigned char	*ft_set_conversion_specifier(unsigned char *copy,
	t_print *print, unsigned int current_cursor, va_list ap);
unsigned char	*ft_id_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_u_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_x_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_o_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_s_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_c_conversion(t_print *print, va_list ap, char c);
unsigned char	*ft_p_conversion(t_print *print, va_list ap);
unsigned char	*ft_percent_conversion(t_print *print);
unsigned char	*ft_other_conversion(t_print *print, unsigned char c);
unsigned char	*ft_s_conversion1(t_print *print, va_list ap, int **nb);
unsigned char	*ft_s_conversion2(t_print *print, va_list ap, int **nb);
int				ft_parsing_length_modifier(unsigned char *copy, t_print *print,
	unsigned int current_cursor);
long			ft_set_length_modifier_di(t_print *print, va_list ap, char c);
unsigned long	ft_set_length_modifier_uox(t_print *print, va_list ap, char c);
int				ft_fill_zero(unsigned char **str, int nb);
int				ft_parsing_length_modifier2(int *count,
	unsigned int *current_cursor, t_print *print, unsigned char *copy);
int				ft_reset_flag(t_print *print);
int				ft_parsing_flag(unsigned char *copy, t_print *print,
	unsigned int current_cursor);
unsigned char	*ft_set_flag_signed_number(char c, unsigned char *str,
	t_print *print);
unsigned char	*ft_set_flag_unsigned_number(char c, unsigned char *str,
	t_print *print);
unsigned char	*ft_set_flag_char(unsigned char *str, t_print *print);
unsigned char	*ft_set_flag(char c, unsigned char *str, t_print *print);
unsigned char	*ft_set_flag_plus_space(char c, unsigned char *str,
	t_print *print, int sign);
unsigned char	*ft_set_flag_hashtag(char c, unsigned char *str);
unsigned char	*ft_set_flag_string(unsigned char *str, t_print *print);
void			ft_set_flag_signed_number2(int sign, t_print *print,
	unsigned char **tmp, int length);
void			ft_set_flag_signed_number3(int sign, t_print *print,
	unsigned char **tmp, int length);
unsigned char	*ft_add_zeros_precision(t_print *print, unsigned char *tmp);
int				ft_parsing_width(unsigned char *copy, t_print *print,
	unsigned int current_cursor);
int				ft_parsing_precision(unsigned char *copy, t_print *print,
	unsigned int current_cursor);
unsigned char	*ft_add_zeros(t_print *print, unsigned char *tmp, char c);
unsigned char	*ft_add_space(t_print *print, unsigned char *tmp);
int				ft_get_wildchar2(unsigned char **multichar, int nb,
	t_print *print);
int				ft_get_wildchar3(unsigned char **multichar, int nb,
	t_print *print);
int				ft_get_wildchar4(unsigned char **multichar, int nb,
	t_print *print);
int				ft_get_wildchar5(unsigned char **multichar, int nb,
	t_print *print);
unsigned char	*ft_itoa_ubase(uintmax_t unb, int base);
void			ft_putunbr(uintmax_t nb);
int				ft_strchr_position(unsigned char *str, unsigned char c);
unsigned char	*ft_get_wildchar(int nb, t_print *print);
unsigned char	*ft_strupper(unsigned char *str);
int				ft_set_cursor(unsigned int cursor, unsigned char *copy);
unsigned char	*ft_printf_join(unsigned char *str1, unsigned char *str2);
unsigned char	*ft_cut_wide_character(unsigned char *str);
unsigned char	*ft_itoa(long n);
void			*ft_memalloc(size_t size);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strdup(const char *s);
char			*ft_strnew(size_t size);
void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *dest, const char *src);
int				ft_isprint(int c);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *nptr);
unsigned char	*ft_printf_join_bis(unsigned char *str1, unsigned char *str2,
	unsigned int len1, unsigned int len2);
unsigned char	*ft_cut_wide_character2(unsigned char *str, unsigned int end,
	int count, unsigned char *tmp);
unsigned char	*ft_printf_join_ter(unsigned int len1, unsigned int len2,
	unsigned char *str1, unsigned char *str2);
int				ft_init_tab(unsigned char **tab);

#endif
