/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:53:42 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:41:20 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_struct(t_list *struc)
{
	struc->dot = 0;
	struc->tiret = 0;
	struc->zero = 0;
	struc->field = 0;
	struc->precize = 0;
	struc->fieldstar = 0;
	struc->precize_star = 0;
}

void	set_flag_struc(t_list *struc, char *str)
{
	int i;

	i = 0;
	reset_struct(struc);
	while (str[i])
	{
		if (str[i] == '.')
			struc->dot = 1;
		if (str[i] == '*')
		{
			if (str[i - 1] == '.')
				struc->precize_star = 1;
			else
				struc->fieldstar = 1;
		}
		if (str[i] == '-')
			struc->tiret = 1;
		if (str[i] == '0' && (str[i - 1] < '0' || str[i - 1] > '9') && str[i
		- 1] != '.')
			struc->zero = 1;
		i++;
	}
}

void	set_field_struc(t_list *struc, char *str)
{
	int i;

	i = ft_atoimod(str, 1);
	struc->field = i;
	if (struc->dot == 1)
	{
		i = ft_atoimod(str, 2);
		struc->precize = i;
	}
}
