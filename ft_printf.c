/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:37:26 by jdupuis           #+#    #+#             */
/*   Updated: 2024/12/21 15:04:35 by jdupuis          ###   ########.fr       */
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

	rft_printf += ft_printf("Pourcent: %% -> ft_printf\n");
	rprintf += printf("Pourcent: %% ->    printf\n");
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
	
	rft_printf += ft_printf("nombre d: %d -> ft_printf\n", INT_MIN);
	rprintf += printf("nombre d: %d ->    printf\n", INT_MIN);
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
	
	rft_printf += ft_printf("chiffre i: %i -> ft_printf\n", 5);
	rprintf += printf("chiffre i: %i ->    printf\n", 5);
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
		
	rft_printf += ft_printf("unsigned u: %u -> ft_printf\n", Unb);
	rprintf += printf("unsigned u: %u ->    printf\n", Unb);
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
	
	rft_printf += ft_printf("string: %s -> ft_printf\n", str);
	rprintf += printf("string: %s ->    printf\n", str);
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
	
	rft_printf += ft_printf("adresse : %p -> ft_printf\n", (void *)-14523);
	rprintf += printf("adresse : %p ->    printf\n", (void *)-14523);
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
	
	rft_printf += ft_printf("caractere: %c -> ft_printf\n", 'z');
	rprintf += printf("caractere: %c ->    printf\n", 'z');
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
	
	rft_printf += ft_printf("%%x: %x -> ft_printf\n", -10);
	rprintf += printf("%%x: %x ->    printf\n", -10);
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
	
	rft_printf += ft_printf("%%X: %X -> ft_printf\n", 42);
	rprintf += printf("%%X: %X ->    printf\n", 42);
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
	
	rft_printf += ft_printf("au revoir ! -> ft_printf\n");
	rprintf += printf("au revoir ! ->    printf\n");
	printf("return ft_printf: %d vs return printf: %d\n\n", rft_printf, rprintf);
	
	rft_printf += ft_printf("%%p du test: %p %p -> ft_printf\n", 0, 0);
	rprintf += printf("%%p du test: %p %p ->    printf\n", 0, 0);
	printf("return ft_printf: %d vs return printf: %d\n", rft_printf, rprintf);
	return (0);
}
*/