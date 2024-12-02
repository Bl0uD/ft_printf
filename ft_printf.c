/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:37:26 by jdupuis           #+#    #+#             */
/*   Updated: 2024/12/03 00:00:14 by jdupuis          ###   ########.fr       */
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
	.f = ft_print_x
},
{
	.flag = 'X',
	.f = ft_print_big_x
},
};

const struct s_printf_flags	*get_flag_from_char(char c)
{
	long unsigned	i;

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
	size_t						len;
	const struct s_printf_flags	*p_flag;
	va_list						cpy_ap;

	i = 0;
	len = 0;
	va_copy(cpy_ap, ap);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == '%')
				len += ft_putchar_fd(format[i + 1], fd);
			else
			{
				p_flag = get_flag_from_char(format[i + 1]);
				len += (size_t)p_flag->f(fd, &cpy_ap);
			}
			i += 2;
		}
		else
			len += ft_putchar_fd(format[i++], fd);
	}
	return (va_end(cpy_ap), len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (len);
}
/*
int	main(void)
{
	int		rft_printf = 0;
	int		rprintf = 0;
	char	*str = "Hello world!";
	unsigned int	Unb = -42;

	// ft_printf("Pourcent: %% -> ft_printf\n");
	// printf("Pourcent: %% -> ft_printf\n");
	// rft_printf += ft_printf("nombre d: %d -> ft_printf\n", INT_MIN);
	// rprintf += printf("nombre d: %d -> ft_printf\n", INT_MIN);
	// ft_printf("chiffre i: %i -> ft_printf\n", 5);
	// printf("chiffre i: %i -> ft_printf\n", 5);
	// ft_printf("unsigned u: %u -> ft_printf\n", Unb);
	// printf("unsigned u: %u -> ft_printf\n", Unb);
	// ft_printf("string: %s -> ft_printf\n", str);
	// printf("string: %s -> ft_printf\n", str);
	// ft_printf("adresse : %p -> ft_printf\n", (void *)-14523);
	// printf("adresse : %p -> ft_printf\n", (void *)-14523);
	// ft_printf("caractere: %c -> ft_printf\n", 'z');
	// printf("caractere: %c -> ft_printf\n", 'z');
	// rft_printf += ft_printf("%%x: %x -> ft_printf\n", -10);
	// rprintf += printf("%%x: %x -> ft_printf\n", -10);
	// ft_printf("%%X: %X -> ft_printf\n", 42);
	// printf("%%X: %X -> ft_printf\n", 42);
	// ft_printf("au revoir ! -> ft_printf\n");
	// printf("au revoir ! -> ft_printf\n");

	printf("\nreturn ft_printf: %d vs return printf: %d", rft_printf, rprintf);
	return (0);
}
*/