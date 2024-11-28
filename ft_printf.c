/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:37:26 by jdupuis           #+#    #+#             */
/*   Updated: 2024/11/28 14:02:27 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const struct s_printf_flags	g_flags[] = {
{
	.flag = 'c',
	.f = ft_print_c
},
{
	.flag = 's',
	.f = ft_print_s
},
{
	.flag = 'p',
	.f = ft_print_p
},
{
	.flag = 'd',
	.f = ft_print_d
},
{
	.flag = 'i',
	.f = ft_print_d
},
{
	.flag = 'u',
	.f = ft_print_u
},
{
	.flag = 'x',
	.f = ft_print_d
},
{
	.flag = 'X',
	.f = ft_print_d
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
	int							len;
	const struct s_printf_flags	*p_flag;
	va_list						cpy_ap;

	i = 0;
	len = 0;
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
				len = len + p_flag->f(fd, &cpy_ap);
			}
			i += 2;
		}
		write(fd, &format[i], 1);
		i++;
	}
	return (va_end(cpy_ap), len);
}

// int	ft_dprintf(int fd, const char *format, ...)
// {
// 	va_list	ap;
// 	int		i;

// 	va_start(ap, format);
// 	ft_vdprintf(fd, format, ap);
// 	va_end(ap);
// 	return (1);
// }

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
	char	*str = "Hello world!";
	ft_printf("Coucou %%, %d, %s, %c, au revoir !\n", 44, str, 'z');
	printf("Pourcent: %%, nombre d: %d, chiffre i: %i, string: %s, adresse : %p, caractère: %c, au revoir !\n", 44, 5, str, str, 'z');
	return (0);
}
