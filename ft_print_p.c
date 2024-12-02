/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:52:12 by jdupuis           #+#    #+#             */
/*   Updated: 2024/12/02 22:55:40 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

#include <stdlib.h>

char	*ft_alloc(unsigned long nbr, int *i)
{
	char	*a;

	if (nbr == 0)
		(*i)++;
	while (nbr >= 1)
	{
		nbr /= 16;
		(*i)++;
	}
	a = (char *)malloc(sizeof(char) * (*i) + 1);
	if (!a)
		return (NULL);
	a[(*i)] = '\0';
	return (a);
}

char	*ft_u_itoa_hexa_base(unsigned long nbr)
{
	int			i;
	int			j;
	char		*res;
	const char	*base = "0123456789abcdef";

	i = 0;
	res = ft_alloc(nbr, &i);
	if (!res)
		return (0);
	j = 1;
	while (i > j - 1)
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
	s = ft_u_itoa_hexa_base(va_arg(*list, long));
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
