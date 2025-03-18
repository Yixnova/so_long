/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:00:13 by yigsahin          #+#    #+#             */
/*   Updated: 2024/11/14 01:41:42 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	length(unsigned long nbr, char *base, int class, int base_len)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	if (class == 1)
	{
		if (!base)
			return (write(1, "(null)", 6));
		else
		{
			while (base[++i])
				len += write(1, &base[i], 1);
		}
		return (len);
	}
	if (class == 2 && (long)nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -nbr;
	}
	if ((nbr / base_len) != 0)
		len += length((nbr / base_len), base, 0, base_len);
	len += write(1, &base[nbr % base_len], 1);
	return (len);
}

static int	ft_format1(char c, va_list a)
{
	char	chr;

	if (c == 'c')
	{
		chr = va_arg(a, int);
		return (write(1, &chr, 1));
	}
	if (c == 's')
		return (length(0, va_arg(a, char *), 1, 0));
	if (c == 'd' || c == 'i')
		return (length(va_arg(a, int), "0123456789", 2, 10));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	ft_format2(char c, va_list a)
{
	unsigned long	ptr;
	int				len;

	if (c == 'p')
	{
		ptr = va_arg(a, unsigned long);
		if (!ptr)
			return (write(1, "(nil)", 5));
		len = write(1, "0x", 2);
		return (len + length(ptr, "0123456789abcdef", 0, 16));
	}
	if (c == 'u')
		return (length(va_arg(a, unsigned int), "0123456789", 0, 10));
	if (c == 'x')
		return (length(va_arg(a, unsigned int), "0123456789abcdef", 0, 16));
	if (c == 'X')
		return (length(va_arg(a, unsigned int), "0123456789ABCDEF", 0, 16));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	a;

	va_start(a, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c' || str[i] == 's' || str[i] == 'd'
				|| str[i] == 'i' || str[i] == '%')
				len += ft_format1(str[i], a);
			else
				len += ft_format2(str[i], a);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(a);
	return (len);
}
