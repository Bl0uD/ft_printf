/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:57:09 by jdupuis           #+#    #+#             */
/*   Updated: 2024/12/01 12:57:55 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_u(int fd, va_list *list)
{
	unsigned int	nb;
	int				len;

	len = 1;
	nb = (unsigned int)va_arg(*list, int);
	ft_u_putnbr_fd((unsigned int)nb, fd);
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
