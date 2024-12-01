/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:20:13 by jdupuis           #+#    #+#             */
/*   Updated: 2024/12/01 12:58:01 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_d(int fd, va_list *list)
{
	int	nb;
	int	len;

	len = 1;
	nb = va_arg(*list, int);
	ft_putnbr_fd(nb, fd);
	if (nb < 0 || nb == 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
