/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:55:20 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/26 22:38:29 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_printf_flags
{
	char	flag;
	size_t	(*f)(int fd, va_list *list);
}							t_struct;

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
size_t	ft_vdputchar(int fd, va_list *list);
size_t	ft_vdputnbr(int fd, va_list *list);
size_t	ft_vdputstr(int fd, va_list *list);
size_t	ft_strlen(const char *str);

#endif