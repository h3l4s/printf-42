/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:41:46 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:41:48 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_redir_p(char *str, t_list *struc)
{
	int		len;
	char	*strm;

	if (struc->field < 0)
	{
		struc->field = -struc->field;
		struc->tiret = 1;
	}
	len = retbigger(struc->precize, struc->field);
	if (len < ft_strlen(str))
		len = ft_strlen(str);
	if (!(strm = malloc(sizeof(char) * (len + 3))))
		return ;
	strm[len] = '\0';
	if (!(struc->dot) && !(struc->tiret) && len && struc->zero == 0)
		just_field_p(str, struc, strm, len);
	if (struc->dot == 0 && struc->tiret == 1 && struc->zero == 0)
		just_tiret_p(str, struc, strm, len);
}

void	just_field_p(char *str, t_list *struc, char *strm, int value)
{
	int i;
	int k;
	int size;

	k = 0;
	i = 0;
	size = ft_strlen(str);
	(void)value;
	while (i < (struc->field - (size + 2)))
		strm[i++] = ' ';
	strm[i++] = '0';
	strm[i++] = 'x';
	while (str[k])
		strm[i++] = str[k++];
	strm[i] = '\0';
	ft_putstr(strm, struc);
}

void	just_tiret_p(char *str, t_list *struc, char *strm, int value)
{
	int i;
	int k;

	k = 0;
	i = 0;
	(void)value;
	strm[i++] = '0';
	strm[i++] = 'x';
	while (str[k])
		strm[i++] = str[k++];
	while (i < struc->field)
		strm[i++] = ' ';
	ft_putstr(strm, struc);
}
