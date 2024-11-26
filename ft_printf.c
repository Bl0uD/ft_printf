/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:37:26 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/26 20:58:37 by jdupuis          ###   ########.fr       */
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

static struct	s_printf_flag flags[] = {
	{
		.flag = 'c',
		.f = ft_vdputchar
	},
	{
		.flag = 's',
		.f = ft_vdputstr
	},
	{
		.flag = 'p',
		.f = ft_vdputnbr
	},
	{
		.flag = 'd',
		.f = ft_vdputnbr
	},
	{
		.flag = 'i',
		.f = ft_vdputnbr
	},
	{
		.flag = 'u',
		.f = ft_vdputnbr
	},
	{
		.flag = 'x',
		.f = ft_vdputnbr
	},
	{
		.flag = 'X',
		.f = ft_vdputnbr
	},
	{
		.flag = '%',
		.f = ft_vdputchar
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
			if (format[i] == '%' && format[i + 1] == flags[j].flag)
			{
				res = res + flags[j].f(fd, &ap);
				i += ft_strlen(&flags[j].flag) + 1;
				break ;
			}
			j++;
		}
		write(fd, &format[i], 1);
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
	ft_printf("Coucou %%, %d, %s, %c, au revoir !\n", 4, "Hello world!", 'z');
	printf("Coucou %%, %d, %s, %c, au revoir !\n", 4, "Hello world!", 'z');
	return (0);
}
