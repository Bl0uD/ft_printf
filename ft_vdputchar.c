/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdputchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:19:42 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/26 23:34:30 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_vdputchar(int fd, va_list *list)
{
	char	c;

	c = va_arg(*list, int);
	if (c == '%')
		write(fd, &c, 1);
	else
		write(fd, &c, 1);
	return (1);
}
