/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Pprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:15:33 by ifreire-          #+#    #+#             */
/*   Updated: 2022/03/16 00:02:31 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_size_long(unsigned long d)
{
	int	size;

	size = 0;
	while (d != 0)
	{
		size++;
		d = d / 16;
	}
	size += 2;
	return (size);
}

void	ft_pointer(unsigned long d)
{
	char	c;

	if (d >= 16)
	{
		ft_pointer(d / 16);
		ft_pointer(d % 16);
	}
	else
	{
		if (d <= 9)
		{
			c = d + 48;
			write (1, &c, 1);
		}
		else
		{
			c = d + 87;
			write(1, &c, 1);
		}
	}
}

unsigned long	p_printf(unsigned long d)
{
	if (d == 0)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	ft_pointer(d);
	return (ft_size_long(d));
}
