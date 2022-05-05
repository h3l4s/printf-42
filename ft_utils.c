/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:58:02 by aestor            #+#    #+#             */
/*   Updated: 2021/03/18 14:42:33 by aestor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoimod(const char *str, int v)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	if (v == 1)
	{
		while (strchrmodif("%0-*", str[i]))
			i++;
	}
	if (v == 2)
	{
		while (str[i] != '.' && str[i])
			i++;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10 + (str[i] - 48));
		i++;
	}
	return (nbr);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		s1_len;
	int		i;

	s1_len = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[s1_len])
		s1_len++;
	if (!(dest = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_redir_clion(va_list vl, char c, t_list *struc, char *str)
{
	if (c == 's')
	{
		str = ft_strdup(va_arg(vl, char*));
		if (str == NULL)
			str = ft_strdup("(null)");
		flag_redir_s(str, struc);
		free(str);
	}
	if (c == 'c')
	{
		flag_redir_c(va_arg(vl, int), struc);
	}
	if (c == 'u')
	{
		str = ft_itoa_uns(va_arg(vl, unsigned int));
		flag_redir(str, struc);
		free(str);
	}
	if (c == '%')
		flag_redir_c('%', struc);
}

void	redir_clion_2(va_list vl, char c, t_list *struc, char *str)
{
	if (c == 'p')
	{
		if (!(str = malloc(sizeof(char) * 17)))
			return ;
		ft_putnbr_base_uns(str, va_arg(vl, unsigned long long),
		"0123456789abcdef");
		flag_redir_p(str, struc);
		free(str);
	}
	if (c == 'd' || c == 'i')
	{
		str = ft_itoa(va_arg(vl, int));
		flag_redir(str, struc);
		free(str);
	}
}

void	redirige(va_list vl, char c, t_list *struc)
{
	char *str;

	if (c == 'x')
	{
		if (!(str = malloc(sizeof(char) * 10)))
			return ;
		ft_putnbr_base(str, va_arg(vl, int), "0123456789abcdef");
		flag_redir(str, struc);
		free(str);
	}
	if (c == 'X')
	{
		if (!(str = malloc(sizeof(char) * 10)))
			return ;
		ft_putnbr_base(str, va_arg(vl, int), "0123456789ABCDEF");
		flag_redir(str, struc);
		free(str);
	}
	redir_clion_2(vl, c, struc, str);
	ft_redir_clion(vl, c, struc, str);
}
