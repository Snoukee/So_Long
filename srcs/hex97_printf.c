/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lXprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:16:03 by ifreire-          #+#    #+#             */
/*   Updated: 2022/03/15 23:54:07 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_hex97(unsigned int d)
{
	char	c;

	if (d >= 16)
	{
		ft_hex97(d / 16);
		ft_hex97(d % 16);
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

int	hex97_printf(int d)
{
	if (d == 0)
		return (write(1, "0", 1));
	else
		ft_hex97(d);
	return (ft_size_hex(d));
}
