/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:41:52 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:41:53 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		merci_clion(t_list *struc, int size)
{
	int len;

	if (struc->precize < 0)
	{
		struc->dot = 0;
		struc->precize = 0;
	}
	if (struc->field >= struc->precize)
		if (struc->field < size)
			len = size;
		else if (struc->field > size)
			len = struc->field;
		else
			len = struc->precize;
	else if (struc->precize > size)
	{
		if (size > struc->field)
			len = size;
		else
			len = struc->field;
	}
	else
		len = size;
	return (len);
}

void	flag_redir_s(char *str, t_list *struc)
{
	int		len;
	int		size;
	char	*strm;

	size = ft_strlen(str);
	if (struc->field < 0)
	{
		struc->field = -struc->field;
		struc->tiret = 1;
	}
	len = merci_clion(struc, size);
	if (!(strm = malloc(sizeof(char) * (len + 1))))
		return ;
	if (struc->dot == 1 && !struc->field && struc->tiret == 0)
		flag_s_dot(str, strm, len, struc);
	if (struc->dot == 1 && struc->field && struc->tiret == 0)
		flag_s_dot_width(str, strm, len, struc);
	if (struc->dot == 0 && struc->tiret == 0)
		flag_s_width(str, strm, len, struc);
	if (struc->tiret == 1)
		flag_s_tiret(str, strm, len, struc);
}

void	flag_s_dot(char *str, char *strm, int value, t_list *struc)
{
	int i;
	int k;
	int size;

	i = 0;
	k = 0;
	(void)value;
	size = ft_strlen(str);
	if (struc->precize < size)
	{
		if (struc->precize < 0)
			struc->precize = size;
		while (i < struc->precize)
			strm[i++] = str[k++];
	}
	else
	{
		while (str[k])
			strm[i++] = str[k++];
	}
	strm[i] = '\0';
	ft_putstr(strm, struc);
}

void	flag_s_dot_width(char *str, char *strm, int value, t_list *struc)
{
	int i;
	int k;
	int size;

	i = 0;
	k = 0;
	(void)value;
	size = ft_strlen(str);
	if (struc->precize > size || struc->precize < 0)
		struc->precize = size;
	while (i < (struc->field - struc->precize))
		strm[i++] = ' ';
	while (struc->precize)
	{
		strm[i++] = str[k++];
		struc->precize -= 1;
	}
	strm[i] = '\0';
	ft_putstr(strm, struc);
}

void	flag_s_width(char *str, char *strm, int value, t_list *struc)
{
	int i;
	int k;
	int size;

	i = 0;
	k = 0;
	(void)value;
	size = ft_strlen(str);
	while (i < (struc->field - size))
		strm[i++] = ' ';
	while (str[k])
		strm[i++] = str[k++];
	strm[i] = '\0';
	ft_putstr(strm, struc);
}
