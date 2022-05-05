/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:12:43 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:42:10 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		strchrmodif(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*strlenmodif(const char *str, int i)
{
	int		j;
	int		l;
	char	*strm;

	j = 0;
	l = i;
	while (str[i++] && j++ && strchrmodif("%-0123456789.*", str[i]))
		if (strchrmodif("cspdiuxX%", str[i]))
			break ;
	if (!(strm = malloc(sizeof(char) * (j + 10))))
		return (NULL);
	j = 0;
	while (str[l] && strchrmodif("%-0123456789.*", str[l]))
	{
		strm[j++] = str[l++];
		if (strchrmodif("cspdiuxX%", str[l]))
		{
			strm[j++] = str[l];
			break ;
		}
	}
	strm[j] = '\0';
	return (strm);
}

void	ft_printf_2(const char *format, int *i, t_list *struc)
{
	if (format[(*i)] && format[(*i)] != '%')
	{
		write(1, &format[(*i)], 1);
		(*i)++;
		(*struc).count += 1;
	}
}

void	ft_printf_3(const char *format, va_list arg, int *i, t_list *struc)
{
	if ((*struc).fieldstar)
		(*struc).field = va_arg(arg, int);
	if ((*struc).precize_star)
		(*struc).precize = va_arg(arg, int);
	(*i)++;
	while (!strchrmodif("cspdiuxX%", format[(*i)]))
		(*i)++;
	redirige(arg, format[(*i)], struc);
	(*i)++;
}

int		ft_printf(const char *format, ...)
{
	int		i;
	char	*str;
	t_list	struc;
	va_list	arg;

	va_start(arg, format);
	i = 0;
	struc.count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i])
		{
			str = strlenmodif(format, i);
			set_flag_struc(&struc, str);
			set_field_struc(&struc, str);
			ft_printf_3(format, arg, &i, &struc);
			free(str);
		}
		ft_printf_2(format, &i, &struc);
	}
	va_end(arg);
	return (struc.count);
}
