/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:32:24 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 15:32:26 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, t_list *struc)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		struc->count += 1;
		i++;
	}
	free(str);
}

int		retbigger(int a, int b)
{
	if (a >= b)
		return (a);
	if (b >= a)
		return (b);
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
