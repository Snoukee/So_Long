/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:19:47 by ifreire-          #+#    #+#             */
/*   Updated: 2022/04/12 01:44:23 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_conversion(int x, int i, const char *txt, va_list arg)
{
	if (txt[i - 1] == 's')
		x += s_printf(va_arg(arg, char *));
	if (txt[i - 1] == 'c')
		x += c_printf(va_arg(arg, int));
	if (txt[i - 1] == 'p')
		x += p_printf(va_arg(arg, unsigned long));
	if ((txt[i - 1] == 'd') || (txt[i - 1] == 'i'))
		x += d_printf(va_arg(arg, int));
	if (txt[i - 1] == 'u')
		x += u_printf(va_arg(arg, int));
	if (txt[i - 1] == 'x')
		x += hex97_printf(va_arg(arg, int));
	if (txt[i - 1] == 'X')
		x += hex65_printf(va_arg(arg, int));
	if (txt[i - 1] == '%')
		x += c_printf('%');
	return (x);
}

int	ft_printf(const char *txt, ...)
{
	static int	i;
	int			x;
	va_list		arg;

	va_start(arg, txt);
	i = 0;
	x = 0;
	while (txt[i] != '\0')
	{
		if (txt[i] == '%')
		{
			i = i + 2;
			x = ft_conversion(x, i, txt, arg);
		}
		else
		{
			x += write(1, &txt[i], 1);
			i++;
		}
	}
	va_end(arg);
	return (x);
}
