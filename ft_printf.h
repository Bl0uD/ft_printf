/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:55:20 by jdupuis           #+#    #+#             */
/*   Updated: 2024/12/02 20:02:34 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_printf_flags
{
	char	flag;
	size_t	(*f)(int fd, va_list * list);
}							t_struct;

char	*ft_itoa_hexa_base(long nbr);
int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_tolower(int c);
void	ft_putnbr_fd(int n, int fd);
void	ft_u_putnbr_fd(unsigned int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
size_t	ft_print_c(int fd, va_list *list);
size_t	ft_print_d(int fd, va_list *list);
size_t	ft_print_p(int fd, va_list *list);
size_t	ft_print_s(int fd, va_list *list);
size_t	ft_print_u(int fd, va_list *list);
size_t	ft_print_x(int fd, va_list *list);
size_t	ft_print_big_x(int fd, va_list *list);
size_t	ft_strlen(const char *str);

#endif