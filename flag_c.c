/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:41:29 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:41:32 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_redir_c(char c, t_list *struc)
{
	int		len;
	char	*strm;

	if (struc->field < 0)
	{
		struc->field = -struc->field;
		struc->tiret = 1;
	}
	len = 1;
	if (struc->field != 0)
		len = struc->field;
	if (!(strm = malloc(sizeof(char) * len + 1)))
		return ;
	if (struc->tiret == 1)
		flag_c_tiret(c, strm, len, struc);
	if (struc->tiret == 0 && struc->zero == 0)
		flag_c(c, strm, len, struc);
	if (struc->zero == 1 && struc->tiret == 0)
		flag_c_zero(c, strm, len, struc);
}

void	flag_c_zero(char c, char *strm, int value, t_list *struc)
{
	int i;

	i = 0;
	(void)value;
	while (i < (struc->field - 1))
	{
		if (struc->zero == 1)
			strm[i++] = '0';
		else
			strm[i++] = ' ';
	}
	strm[i++] = c;
	strm[i] = '\0';
	ft_putstr(strm, struc);
}

void	flag_c_tiret(char c, char *strm, int value, t_list *struc)
{
	int i;

	i = 0;
	(void)value;
	write(1, &c, 1);
	struc->count += 1;
	while (i < (struc->field - 1))
		strm[i++] = ' ';
	strm[i] = '\0';
	ft_putstr(strm, struc);
}

void	flag_c(char c, char *strm, int value, t_list *struc)
{
	int i;

	i = 0;
	(void)value;
	while (i < (struc->field - 1))
		strm[i++] = ' ';
	strm[i] = '\0';
	ft_putstr(strm, struc);
	write(1, &c, 1);
	struc->count += 1;
}
