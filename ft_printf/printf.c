/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkan <andrespathway@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:54:52 by aalkan            #+#    #+#             */
/*   Updated: 2022/10/26 13:17:03 by aalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(char *str)
{
	int	sayac;

	sayac = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[sayac])
		write(1, str + sayac++, 1);
	return (sayac);
}

int	write_hex(unsigned long long nbr, char x)
{
	int	i;

	i = 0;
	if (!(nbr <= 15))
		i += write_hex(nbr / 16, x);
	if (x == 'x')
		i += write(1, &HEXA_SMALL[nbr % 16], 1);
	else if (x == 'X')
		i += write(1, &HEXA_BIG[nbr % 16], 1);
	return (i);
}

int	write_dec(long long nbr)
{
	int	ret_value;

	ret_value = 0;
	if (nbr < 0)
		ret_value += ft_putchar('-');
		nbr *= -1;
	if (!(nbr <= 9))
		ret_value += write_dec(nbr / 10);
	ret_value += ft_putchar(nbr % 10 + '0');
	return (ret_value);
}

int	ft_format(char c, va_list arg)
{
	int	sayac;

	sayac = 0;
	if (c == 'c')
		sayac += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		sayac += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
	{
		sayac += ft_putstr("0x");
		sayac += write_hex(va_arg(arg, unsigned long long), 'x');
	}
	else if (c == 'x' || c == 'X')
		sayac += write_hex(va_arg (arg, int), c);
	else if (c == '%')
		sayac += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		sayac += write_dec((long long)va_arg(arg, int));
	else if (c == 'u')
		sayac += write_dec((long long)va_arg(arg, unsigned int));
	return (sayac);
}

int	ft_printf(const char *str, ...)
{
	int		ssayac;
	int		sayac;
	va_list	ag;

	sayac = 0;
	ssayac = 0;
	va_start (ag, str);
	while (str[sayac] != '\0')
	{
		if (str[sayac] != '%')
			ssayac += ft_putchar(str[sayac]);
		else
		{
			if (str[sayac + 1] != '\0')
				ssayac += ft_format(str[++sayac], ag);
			else
				return (-1);
		}
		sayac++;
	}
	va_end(ag);
	return (ssayac);
}
