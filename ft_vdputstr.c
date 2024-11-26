/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdputstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:19:58 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/26 21:21:14 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_vdputstr(int fd, va_list *list)
{
	char	*str;

	str = va_arg(*list, char *);
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
