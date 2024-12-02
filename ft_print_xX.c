/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:05:39 by jdupuis           #+#    #+#             */
/*   Updated: 2024/12/03 00:06:57 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*ft_i_alloc(unsigned int nbr, int *i)
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

char	*ft_u_itoa_hexa_base(unsigned int nbr)
{
	int			i;
	int			j;
	char		*res;
	const char	*base = "0123456789abcdef";

	i = 0;
	res = ft_i_alloc(nbr, &i);
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

size_t	ft_print_x(int fd, va_list *list)
{
	int		len;
	char	*s;

	len = 0;
	s = ft_u_itoa_hexa_base(va_arg(*list, int));
	ft_putstr_fd(s, fd);
	len += ft_strlen(s);
	free(s);
	return (len);
}

size_t	ft_print_big_x(int fd, va_list *list)
{
	int		len;
	int		i;
	char	*s;

	len = 0;
	i = 0;
	s = ft_u_itoa_hexa_base(va_arg(*list, int));
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	ft_putstr_fd(s, fd);
	len += ft_strlen(s);
	free(s);
	return (len);
}
