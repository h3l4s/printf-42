/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_s_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:08:36 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 16:08:42 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_s_tiret(char *str, char *strm, int value, t_list *struc)
{
	int arr[3];

	arr[0] = 0;
	arr[1] = 0;
	if (struc->dot == 1)
		value = struc->precize;
	else
		value = 1;
	arr[2] = ft_strlen(str);
	if (struc->precize > arr[2] || struc->precize < 0)
		struc->precize = arr[2];
	if (struc->precize)
		while (struc->precize != 0)
		{
			strm[arr[0]++] = str[arr[1]++];
			struc->precize -= 1;
		}
	else
		while (str[arr[1]] && value != 0)
			strm[arr[0]++] = str[arr[1]++];
	while (arr[0] < struc->field)
		strm[arr[0]++] = ' ';
	strm[arr[0]] = '\0';
	ft_putstr(strm, struc);
}
