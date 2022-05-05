/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flad_di2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:22:01 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:41:43 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	just_zero(char *str, t_list *struc, char *strm, int value)
{
	int i;
	int k;
	int size;

	k = 0;
	i = 0;
	size = ft_strlen(str);
	if (str[0] == '-')
	{
		strm[i++] = str[k++];
		size--;
	}
	while (i < (value - size))
		strm[i++] = '0';
	while (str[k])
		strm[i++] = str[k++];
	ft_putstr(strm, struc);
}

int		dot_22_clion(char *str, t_list *struc, int value, int *arr)
{
	if (struc->precize > struc->field && str[0] == '-' && arr[2] <
	struc->precize)
		value++;
	if (struc->precize == arr[2] && str[0] == '-')
		arr[2]--;
	if (arr[2] > struc->precize)
		struc->precize = arr[2];
	if (str[0] == '-')
	{
		arr[1]++;
		if (struc->precize > arr[2])
			++struc->precize;
		if (!(ft_strlen(str) == (struc->precize - 1)))
			arr[2]--;
		if (struc->field == (struc->precize - 1) && (struc->precize_star == 0
		|| struc->fieldstar == 0))
			arr[2]--;
		if (ft_strlen(str) == (struc->precize - 1) && struc->precize_star ==
		1 && struc->fieldstar == 1)
			arr[2]--;
	}
	return (value);
}

void	dot_223_clion(const char *str, char *strm, int value, int *arr)
{
	if (str[0] == '-')
		strm[arr[0]++] = '-';
	while (arr[0] < (value - arr[2]))
		strm[arr[0]++] = '0';
	while (str[arr[1]])
		strm[arr[0]++] = str[arr[1]++];
	strm[arr[0]] = '\0';
}

void	dot(char *str, t_list *struc, char *strm, int value)
{
	int arr[3];

	arr[1] = 0;
	arr[0] = 0;
	arr[2] = ft_strlen(str);
	if (struc->precize == 0 && struc->field == 0 && str[0] == '0')
	{
		free(strm);
		return ;
	}
	if (struc->precize == 0 && struc->field != 0 && str[0] == '0')
	{
		while (arr[0] < value)
			strm[arr[0]++] = ' ';
		ft_putstr(strm, struc);
		return ;
	}
	value = dot_22_clion(str, struc, value, arr);
	while (arr[0] < (value - struc->precize))
		strm[arr[0]++] = ' ';
	dot_223_clion(str, strm, value, arr);
	ft_putstr(strm, struc);
}
