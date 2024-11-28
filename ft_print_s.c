/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:19:58 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/27 19:46:48 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_s(int fd, va_list *list)
{
	char	*str;

	str = va_arg(*list, char *);
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
