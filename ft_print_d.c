/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:20:13 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/28 13:53:30 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_d(int fd, va_list *list)
{
	int	d;

	d = va_arg(*list, int);
	ft_putnbr_fd(d, fd);
	return (3);
}
