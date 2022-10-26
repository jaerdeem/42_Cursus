/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkan <andrespathway@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:56:10 by aalkan            #+#    #+#             */
/*   Updated: 2022/10/26 15:01:30 by aalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define HEXA_SMALL  "0123456789abcdef"
# define HEXA_BIG  "0123456789ABCDEF"
# define DECI "0123456789"

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	write_hex(unsigned long long nbr, char x);
int	write_dec(long long nbr);
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int	ft_putchar(char a);
int	ft_format(char a, va_list arg);

#endif
