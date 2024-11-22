/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ju <ju@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:37:26 by ju                #+#    #+#             */
/*   Updated: 2024/11/22 12:07:54 by ju               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LibFT/libft.h"
#include <stdarg.h>
#include <unistd.h>

size_t	ft_vdputchar(int fd, va_list *list)
{
	char	c;

	c = va_arg(*list, int);
	write(fd, &c, 1);

	return (1);
}

size_t	ft_vdputstr(int fd, va_list *list)
{
	char	*str;

	str = va_arg(*list, char *);
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

size_t	ft_vdputnbr(int fd, va_list *list)
{
	int	d;

	d = va_arg(*list, int);
	ft_putnbr_fd(d, fd);
	return (3);
}

struct s_printf_flag
{
	char	flag;
	size_t	(*f)(int fd, va_list *list);
};

static struct s_printf_flag flags[] = {
	{
		.flag = 'c',
		.f = ft_vdputchar
	},
	{
		.flag = 's',
		.f = ft_vdputstr
	},
	{
		.flag = 'd',
		.f = ft_vdputnbr
	}
};

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (format[i])
	{
		j = 0;
		while (j < (sizeof(flags) / sizeof(*flags)))
		{
			if (format[i] == flags[j].flag)
			{
				res = res + flags[j].f(fd, &ap);
				break ;
			}
			j++;
		}
		i++;
	}
	return (res);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	ft_vdprintf(1, format, ap);
	va_end(ap);
	return (1);
}

int	main(void)
{
	ft_printf("dsc", 12, "Hello world", 'c');

	return (0);
}
