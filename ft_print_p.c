/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:52:12 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/29 16:26:55 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_alloc(long nbr, int signe, int *i)
{
	char	*a;

	if (nbr == 0)
		(*i)++;
	while (nbr >= 1)
	{
		nbr /= 16;
		(*i)++;
	}
	a = (char *)malloc(sizeof(char) * (*i) + signe + 2);
	if (!a)
		return (NULL);
	if (signe == 1)
	{
		a[0] = '-';
		(*i)++;
	}
	a[(*i)] = '\0';
	return (a);
}

char	*ft_itoa_hexa_base(long nbr)
{
	int			i;
	int			j;
	int			signe;
	char		*res;
	const char	*base = "0123456789ABCDEF";

	i = 0;
	signe = 0;
	if (nbr < 0)
	{
		signe = 1;
		nbr *= -1;
	}
	res = ft_alloc(nbr, signe, &i);
	if (!res)
		return (0);
	j = 1;
	while (i > j - 1 + signe)
	{
		res[i - j] = base[(nbr % 16)];
		nbr = (nbr / 16);
		j++;
	}
	return (res);
}

size_t	ft_print_p(int fd, va_list *list)
{
	int		len;
	char	*s;

	len = 0;
	s = ft_itoa_hexa_base(va_arg(*list, long));
	if (s && ft_strlen(s) > 0)
	{
		ft_putstr_fd("0x", fd);
		len += 2;
	}
	ft_putstr_fd(s, fd);
	len += ft_strlen(s);
	free(s);
	return (len);
}
