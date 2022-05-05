/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:42:39 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:42:42 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isfine(char *base)
{
	int	i;
	int	i2;
	int	j;

	i = 0;
	i2 = 0;
	j = ft_strlen(base);
	if (j <= 1)
		return (0);
	while (base[i])
	{
		i2 = i + 1;
		while (base[i2])
		{
			if (base[i] == base[i2] || base[i] == '+' || base[i] == '-')
				return (0);
			if (base[i2] == '+' || base[i2] == '-')
				return (0);
			i2++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(char *str, unsigned int nbr, char *base)
{
	long		nb;
	int			i;
	static int	k = 0;
	static int	depth = 0;

	nb = nbr;
	depth++;
	i = ft_strlen(base);
	if (ft_isfine(base) == 1)
	{
		if (nb < 0)
			nb = -nb;
		if (nb >= i)
		{
			ft_putnbr_base(str, nb / i, base);
			ft_putnbr_base(str, nb % i, base);
		}
		else
			str[k++] = base[nb];
		depth--;
	}
	str[k] = '\0';
	if (depth == 0)
		k = 0;
}

void	ft_putnbr_base_uns(char *str, unsigned long long nbr, char *base)
{
	unsigned long long		nb;
	int						i;
	static int				k = 0;
	static int				depth = 0;

	nb = nbr;
	depth++;
	i = ft_strlen(base);
	if (ft_isfine(base) == 1)
	{
		if (nb >= (unsigned long long)i)
		{
			ft_putnbr_base_uns(str, nb / i, base);
			ft_putnbr_base_uns(str, nb % i, base);
		}
		else
			str[k++] = base[nb];
		depth--;
	}
	str[k] = '\0';
	if (depth == 0)
		k = 0;
}
