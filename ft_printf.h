/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:42:22 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:42:23 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_list
{
	int			dot;
	int			precize_star;
	int			fieldstar;
	int			zero;
	int			tiret;
	int			field;
	int			precize;
	int			count;
}				t_list;

int				ft_printf(const char *format, ...);
char			*strlenmodif(const char *str, int i);
int				strchrmodif(const char *str, char c);
void			reset_struct(t_list *struc);
void			set_flag_struc(t_list *struc, char *str);
int				ft_atoimod(const char *str, int v);
void			set_field_struc(t_list *struc, char *str);
char			*ft_itoa(int nb);
void			redirige(va_list vl, char c, t_list *struc);
void			flag_redir(char *str, t_list *struc);
void			ft_putstr(char *str, t_list *struc);
int				ft_strlen(char *str);
int				retbigger(int a, int b);
void			dot_tiret(char *str, t_list *struc, char *strm, int value);
void			dot(char *str, t_list *struc, char *strm, int value);
void			just_field(char *str, t_list *struc, char *strm, int value);
void			just_tiret(char *str, t_list *struc, char *strm, int value);
void			just_zero(char *str, t_list *struc, char *strm, int value);
char			*ft_strdup(const char *s1);
void			flag_redir_s(char *str, t_list *struc);
void			flag_s_dot(char *str, char *strm, int value, t_list *struc);
void			flag_s_tiret(char *str, char *strm, int value, t_list *struc);
void			flag_s_dot_width(char *str, char *strm, int value, t_list
*struc);
void			flag_s_width(char *str, char *strm, int value, t_list *struc);
void			flag_redir_c(char c, t_list *struc);
void			flag_c_tiret(char c, char *strm, int value, t_list *struc);
void			flag_c(char c, char *strm, int value, t_list *struc);
void			flag_c_zero(char c, char *strm, int value, t_list *struc);
void			ft_putnbr_base(char *str, unsigned int nbr, char *base);
void			ft_putnbr_base_uns(char *str, unsigned long long nbr, char
*base);
char			*ft_itoa_uns(unsigned int nb);
void			flag_redir_p(char *str, t_list *struc);
void			just_field_p(char *str, t_list *struc, char *strm, int value);
void			just_tiret_p(char *str, t_list *struc, char *strm, int value);

#endif
