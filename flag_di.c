/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:37:29 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:41:37 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_redir(char *str, t_list *struc)
{
	int		len;
	char	*strm;

	if (struc->field < 0)
	{
		struc->field = -struc->field;
		struc->tiret = 1;
		struc->zero = 0;
	}
	len = retbigger(struc->precize, struc->field);
	if (len < ft_strlen(str))
		len = ft_strlen(str);
	if (!(strm = malloc(sizeof(char) * (len + 1))))
		return ;
	strm[len] = '\0';
	if (struc->dot && struc->tiret)
		dot_tiret(str, struc, strm, len);
	if (struc->dot && !struc->tiret)
		dot(str, struc, strm, len);
	if (!(struc->dot) && !(struc->tiret) && len && struc->zero == 0)
		just_field(str, struc, strm, len);
	if (struc->dot == 0 && struc->tiret == 1 && struc->zero == 0)
		just_tiret(str, struc, strm, len);
	if (struc->dot == 0 && struc->tiret == 0 && struc->zero == 1)
		just_zero(str, struc, strm, len);
}

void	dot_tiret_2(t_list *struc, char *strm, int *arr)
{
	arr[2]--;
	arr[1]++;
	strm[arr[0]++] = '-';
	struc->precize++;
}

void	dot_tiret(char *str, t_list *struc, char *strm, int value)
{
	int	arr[3];

	arr[1] = 0;
	arr[0] = 0;
	arr[2] = ft_strlen(str);
	if (struc->precize == 0 && struc->field == 0 && str[0] == '0')
	{
		free(strm);
		return ;
	}
	if (str[0] == '-')
		dot_tiret_2(struc, strm, arr);
	while (arr[0] < (struc->precize - arr[2]))
		strm[arr[0]++] = '0';
	while (str[arr[1]])
		if (str[0] != '0' || struc->precize != 0)
			strm[arr[0]++] = str[arr[1]++];
		else
			arr[1]++;
	while (arr[0] < value)
		strm[arr[0]++] = ' ';
	ft_putstr(strm, struc);
}

void	just_field(char *str, t_list *struc, char *strm, int value)
{
	int i;
	int k;
	int size;

	k = 0;
	i = 0;
	size = ft_strlen(str);
	while (i < value - size && struc->field)
		strm[i++] = ' ';
	while (str[k])
		strm[i++] = str[k++];
	ft_putstr(strm, struc);
}

void	just_tiret(char *str, t_list *struc, char *strm, int value)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (str[k])
		strm[i++] = str[k++];
	while (i < value)
		strm[i++] = ' ';
	ft_putstr(strm, struc);
}
