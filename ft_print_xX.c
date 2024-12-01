/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:05:39 by jdupuis           #+#    #+#             */
/*   Updated: 2024/12/01 15:01:48 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

size_t	ft_print_x(int fd, va_list *list)
{
	int		len;
	int		i;
	char	*s;

	len = 0;
	i = 0;
	s = ft_itoa_hexa_base(va_arg(*list, long));
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	ft_putstr_fd(s, fd);
	len += ft_strlen(s);
	printf("\ns: %s\n", s);
	printf("\nlen: %d\n", len);
	free(s);
	return (len);
}

size_t	ft_print_X(int fd, va_list *list)
{
	int		len;
	char	*s;

	len = 0;
	s = ft_itoa_hexa_base(va_arg(*list, long));
	ft_putstr_fd(s, fd);
	len += ft_strlen(s);
	free(s);
	return (len);
}
