/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:37:26 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/26 23:47:59 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static const struct s_printf_flags	g_flags[] = {
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
},
};

const struct s_printf_flags	*get_flag_from_char(char c)
{
	int	i;

	i = 0;
	while (i < (sizeof(g_flags) / sizeof(*g_flags)))
	{
		if (c == g_flags[i].flag)
			return (&g_flags[i]);
		i++;
	}
	return (NULL);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int							i;
	int							res;
	const struct s_printf_flags	*p_flag;
	va_list						cpy_ap;

	i = 0;
	res = 0;
	va_copy(cpy_ap, ap);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				write(fd, &format[i + 1], 1);
			else
			{
				p_flag = get_flag_from_char(format[i + 1]);
				res = res + p_flag->f(fd, &cpy_ap);
			}
			i += 2;
		}
		write(fd, &format[i], 1);
		i++;
	}
	return (va_end(cpy_ap), res);
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
