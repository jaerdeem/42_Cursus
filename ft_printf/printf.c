/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkan <andrespathway@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:54:52 by aalkan            #+#    #+#             */
/*   Updated: 2022/10/26 14:59:57 by aalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
		write(1, str + count++, 1);
	return (count);
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
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += write_hex(va_arg(arg, unsigned long long), 'x');
	}
	else if (c == 'x' || c == 'X')
		count += write_hex(va_arg (arg, int), c);
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		count += write_dec((long long)va_arg(arg, int));
	else if (c == 'u')
		count += write_dec((long long)va_arg(arg, unsigned int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		countt;
	int		count;
	va_list	ag;

	count = 0;
	countt = 0;
	va_start (ag, str);
	while (str[count] != '\0')
	{
		if (str[count] != '%')
			countt += ft_putchar(str[count]);
		else
		{
			if (str[count + 1] != '\0')
				countt += ft_format(str[++count], ag);
			else
				return (-1);
		}
		count++;
	}
	va_end(ag);
	return (countt);
}
